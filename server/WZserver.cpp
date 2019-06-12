#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "WZserver.h"
#include <iostream>
#include <vector>
#include <fstream>

using std::cout;
using std::string;

//<<<<<< < HEAD
	//int GameServer::prog_map[15][15];
volatile static int count = 0;
static int playerNum = 0;     //�������
std::vector <PlayerInfo> GameServer::allPlayerInfo;    //��������
//int GameServer::prog_map[15][15];
//std::vector <RoomInfo> GameServer::Rooms;

WZClientInformation GameServer::AcceptSocket[GameServer::MAX_NUM];  //������
//>>>>>> > WebGameLogic
/*
���ƣ����캯��
����������Socket��ʼ��
*/

GameServer::GameServer()
{
	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)   //�ж�һ����û������汾 (makeword�ǽ�����byte�ͺϲ���һ��word�ͣ�һ���ڸ�8λ(b)��һ���ڵ�8λ(a) )
	{
		cout << "�޷������׽���Э��ջ.\n";
		fflush(stdout);
		return;
	}

	//���ü����׽���
	ListenSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); //IPv4 STREAM TCP

	if (ListenSocket == INVALID_SOCKET)
	{
		cout << "�׽��ֳ�ʼ�����󣬴���ţ�" << WSAGetLastError() << "\n";
		fflush(stdout);
		return;
	}

	int port = 1236;  //���޸�

	//���÷���������Ϣ
	Server.sin_family = PF_INET;
	Server.sin_port = htons(port); //htons�ǽ����ͱ����������ֽ�˳��ת��������ֽ�˳��
	Server.sin_addr.S_un.S_addr = htonl(INADDR_ANY);     //INADDR_ANY����inet_addr("0.0.0.0")

	int errornum;
	//��
	bind(ListenSocket, (LPSOCKADDR)&Server, sizeof(Server));    //����ǿ��ת��,LPSOCKADDRΪ�ṹָ��
	while ((errornum = WSAGetLastError()) == 10048)    //10048���� �˿ڱ�ռ��
	{
		port++;
		Server.sin_port = htons(port);
		int retval = bind(ListenSocket, (LPSOCKADDR)&Server, sizeof(Server));
		cout << "�󶨴��󣬴����10048\n";
		fflush(stdout);

	}
	cout << "��������IPΪ:" << Server.sin_addr.S_un.S_addr
		<< " �˿ں�Ϊ: " << port << "\n";
	fflush(stdout);
	//����   ��listen����accept
		//if (listen(ListenSocket, 5) == SOCKET_ERROR)

	if (listen(ListenSocket, 2) == SOCKET_ERROR)     //connect��listen������װ���ӣ�ÿһ��accept���������listen����ȡ����ת��socket���ȴ����socket close��֮���ټ�����listen������ȡ���ӣ���listen���г��Ⱦ���listen�����ĵڶ�������--backlog
	{
		cout << "������������ţ�" << WSAGetLastError() << "\n";
		fflush(stdout);
		return;
	}

	//��������Ϣ��ʼ��
	for (int i = 0; i < MAX_NUM; i++)
		AcceptSocket[i].ClientSock = INVALID_SOCKET;

	cout << "�����ʼ���ɹ�\n";
	fflush(stdout);
}
//������ʼ������
/*playerNum = 0;
Rooms.resize(4);
for (int i = 0; i < 4; i++)
{
	Rooms[i].name = "Room" + std::to_string(i);
	Rooms[i].id = 100 + i;
	Rooms[i].curNum = 0;
}

	GenerateProps();
return;
}
*/

/*
���ƣ���������
���ã�������Դ�ͷ�
*/
GameServer::~GameServer()
{
	if (ListenSocket != INVALID_SOCKET)
		closesocket(ListenSocket);
	cout << "�������ر�\n";
	fflush(stdout);
	WSACleanup();
	return;
}


/*
���ƣ����ID
���������ڼ�⵱ǰû���õ�ID��
*/
int GameServer::CheckSocket()
{
	for (int i = 0; i < MAX_NUM; i++)
	{
		if (AcceptSocket[i].ClientSock == INVALID_SOCKET)
			return i;
	}
	return -1;
}

/*
���ƣ��̴߳���
������Ϊÿһ������Ҵ���һ�������߳�
	  ��������ﵽ���ޣ��;ܾ�
*/
int GameServer::ProcessGameServer()
{


	while (true)
	{
		int index = CheckSocket();
		sockaddr_in Client;

		int ClntLen = sizeof(Client);

		if (index != -1) //���δ��
		{
			//��Ӧǰ���listen�������Ƕ�Ӧ����accept
			cout << "�ȴ�Client����...\n";
			fflush(stdout);
			AcceptSocket[index].ClientSock = accept(
				ListenSocket,
				(struct sockaddr*)&AcceptSocket[index].Client,
				&ClntLen);
			//cout << "#1 AcceptSocket[index].ClientSock: " << AcceptSocket[index].ClientSock << "\n";
			AcceptSocket[index].ID = index;       //��¼���Client��ID���Ժ�ҪѰ����
			AcceptSocket[index].Active = false;

			if (AcceptSocket[index].ClientSock == INVALID_SOCKET)
			{
				cout << "���Ӵ���\n";
				fflush(stdout);
				break;
			}
			//cout << "#2 AcceptSocket[index].ClientSock: " << AcceptSocket[index].ClientSock << "\n";
			cout << "���ӳɹ�\n";
			fflush(stdout);
			//����client��server���ӳɹ�,����
			AcceptSocket[index].ID = index;
			//����ID�������Ĳ���
			std::string msg = std::to_string(AcceptSocket[index].ID);    //����ֵת��Ϊ�ַ��������ض�Ӧ���ַ�����
			SendMessageToOneClient(AcceptSocket[index].ID, msg);
			cout << "#ID :" << msg << "\n";
			cout << "���ӳɹ�\n";
			fflush(stdout);
			playerNum++;
			//����client��server���ӳɹ�
			cout << "����Ҽ��룬IP��ַΪ��" << inet_ntoa(AcceptSocket[index].Client.sin_addr)
				<< "  �˿ں�Ϊ��" << ntohs(AcceptSocket[index].Client.sin_port) << "\n";
			fflush(stdout);
			//�����������߳� 
			int ThreadID;     //�߳�ID
				//�Ѹո����ӳɹ���Client����һ���µ��߳�
			ThreadID = (int)CreateThread(NULL, 0,
				(LPTHREAD_START_ROUTINE)(GameServer::ListenThread), //�̵߳㺯��
				(LPVOID)&AcceptSocket[index], 0,              //����
				&AcceptSocket[index].RecvThreadID          //ϵͳ�����ID
			);

			if (!ThreadID)
			{
				cout << "�����̴߳���\n";
				fflush(stdout);
				ExitThread(AcceptSocket[index].RecvThreadID);
			}

			//���ˣ��µ��̴߳����ɹ������Դ���������

			cout << "�����" << index << "�Ľ����̴߳����ɹ�\n";
			fflush(stdout);
			//cout << "#3 AcceptSocket[index].ClientSock: " << AcceptSocket[index].ClientSock << "\n";
			struct PlayerInfo temp;
			temp.clientInfo = { NULL,AcceptSocket[index].Client,AcceptSocket[index].ID,0,0,0 };
			temp.nickname = std::to_string(AcceptSocket[index].Client.sin_addr.S_un.S_addr) + "_" +
				std::to_string(AcceptSocket[index].Client.sin_port) + "_" + std::to_string(AcceptSocket[index].ID);      //������
			allPlayerInfo.push_back(temp);
		}

		/*CreateThread(NULL, 0,
			static_cast<LPTHREAD_START_ROUTINE>(GameServer::sendRoomInfo), //�̵߳㺯��
			(LPVOID)&AcceptSocket[index], 0,              //����
			nullptr
		);*/

		else   //�������
		{
			SOCKET Accept = accept(ListenSocket,
				(struct sockaddr*)&Client, &ClntLen);

			if (Accept == INVALID_SOCKET)
			{
				cout << "���Ӵ���\n";
				fflush(stdout);
				break;
			}


			cout << "�Ƿ��������ҵ�IP�ĵ�ַΪ:" << inet_ntoa(Client.sin_addr)
				<< " �˿ں�Ϊ :" << ntohs(Client.sin_port) << "\n";
			fflush(stdout);
			send(Accept, "��ǰ�û�����", strlen("��ǰ�û�����") + sizeof(char), 0);

			closesocket(Accept);

			cout << "�Ƿ���������ѶϿ�\n";
			fflush(stdout);
			break;
		}
	}
	return 0;
}

/*
���ƣ������߳�
������Selectģʽ
	�����жϸ��߳��Ƿ�ɶ�������ɶ��Ͷ�ȡ���ϵ���Ϣ
*/
DWORD WINAPI GameServer::ListenThread(void *data) //�����������ĸ�AcceptSocket[xx]�ĵ�ַ
{
	WZClientInformation *GameSocket = (WZClientInformation *)data;
	//return 1;
//}
		//DWORD WINAPI GameServer::GameThread(void *data) //�����������ĸ�AcceptSocket[xx]�ĵ�ַ
	//{
		//WZClientInformation *GameSocket = (WZClientInformation *)data;
		//WZClientInformation *GameSocket = static_cast<WZClientInformation *>(data);
			//sendProps(GameSocket->ID);

	while (true)
	{
		cout << "DEBUG:�µ��շ�ѭ��\n";
		//�������� 

		char recvBuf[28000];

		fd_set Read;//����selectģʽ��IO���й���  
		cout << "DEBUG:xxxxxxxxx\n";
		FD_ZERO(&Read);    //��ʼ��Ϊ0  ���fdset�������ļ��������ϵ
		FD_SET(GameSocket->ClientSock, &Read); //��ClientSock�������
		cout << "DEBUG:yyyyyyyyy\n";
		//we only care reads
		int sel = select(0, &Read, NULL, NULL, NULL);
		cout << "DEBUG:select֮��\n";

		if (FD_ISSET(GameSocket->ClientSock, &Read))     //??
		{
			//���ܿͻ��˵�����
			int result = recv(GameSocket->ClientSock, recvBuf, sizeof(recvBuf), 0);
			cout << "recv ����ֵ: " << result << "\n";
			fflush(stdout);
			if (result > 0 && result < 28000)
			{
				recvBuf[result] = '\0';
				cout << "���" << GameSocket->ID << "��������Ϣ:"
					<< recvBuf << "\n";
				fflush(stdout);
			}
			if (result == SOCKET_ERROR)
			{
				CleanSocket(GameSocket->ID);
				break;
			}
		}

		//�������� 
		char sendBuf[28000];
		fd_set write;//����selectģʽ��IO���й���  
		FD_ZERO(&write);    //��ʼ��Ϊ0
		FD_SET(GameSocket->ClientSock, &write); //��ClientSock�������
		//we only care read
		select(0, NULL, &write, NULL, NULL);

		if (FD_ISSET(GameSocket->ClientSock, &write))       //���fdset��ϵ���ļ����fd�Ƿ�ɶ�д�� > 0��ʾ�ɶ�д��
		{
			//���ܿͻ��˵�����
			strcpy(sendBuf, recvBuf);
			//cout << "Just Before Enter TOALL func, AcceptSocket[ID].ClientSock: " << GameSocket->ClientSock << "\n";
			SendMessageToAllClient(sendBuf, GameSocket->ID);

		}

	}
	return 1;
}

/*
���ƣ�������Ϣ��һ��client
������������Ϣ��һ��client
*/
int GameServer::SendMessageToOneClient(int ID, const string  str)
{
	if (ID < 0)
		return 0;

	int oneSend = send(AcceptSocket[ID].ClientSock,
		str.c_str(), str.length() + sizeof(char), 0);    //ͨ��string�����ĳ�Ա����c_str()��string ����ת����c�е��ַ�����ʽ��
	cout << "�����" << ID << "������" << oneSend << "��bits����Ϣ\n";
	fflush(stdout);
	if (oneSend == SOCKET_ERROR)
	{
		cout << "�����" << ID << "������Ϣʧ��\n";
		fflush(stdout);

		//cout << "#5  ��AcceptSocket[index].ClientSock: " << AcceptSocket[ID].ClientSock << "\n";
		return 0;
	}

	return 1;
}

/*
���ƣ�ȫ����
������������Client������Ϣ
*/
void GameServer::SendMessageToAllClient(const string  str, int ID)
{

	bool flag = true;
	for (int i = 0; i < MAX_NUM; i++)
	{
		//cout << "Just In TOALL func, AcceptSocket[ID].ClientSock :" << AcceptSocket[i].ClientSock << "\n";
		if (ID != i)
		{
			if (AcceptSocket[i].ClientSock != INVALID_SOCKET &&             //����INVALID_SOCKET����
				!SendMessageToOneClient(i, str))
				flag = false;
		}
	}
	if (flag)
		cout << "��������ȫ��(�������" << ID << ")��������Ϣ:"
		<< str << "\n";
	else
		cout << "���ʹ�������\n";
	fflush(stdout);

}

/*
DWORD WINAPI GameServer::sendRoomInfo(void *data)
{
	BnbClientInformation *GameSocket = static_cast<BnbClientInformation*>(data);   //static_cast�൱�ڴ�ͳ��C�������ǿ��ת�������������expressionת��Ϊnew_type���ͣ�����ǿ����ʽת����non-const����תΪconst����


	//����RoomChooseScene
	/*while (true)
	{
		int flag = 0;
		int whichRoom = -1;
		char buf[16];
		ZeroMemory(buf, sizeof(buf));
		int result = recv(GameSocket->ClientSock, buf, sizeof(buf), 0);
		cout << "#buf:" << buf << "\n";
		sscanf(buf, "%d %d", &flag, &whichRoom);
		if (whichRoom != -1)
		{
			Rooms[whichRoom].curNum++;

			Rooms[whichRoom].playerList.push_back(allPlayerInfo.at(GameSocket->ID));
			if (Rooms[whichRoom].playerList.size() == 1)
				Rooms[whichRoom].playerList.back().order = -1;
			Rooms[whichRoom].playerList.back().order++;
		}


		std::string myRoom = std::to_string(playerNum);
		for (int i = 0; i < 4; i++)
			myRoom += " " + std::to_string(Rooms[i].curNum);

		cout << "myRoom :" << myRoom << "\n";
		cout << "myRoom size:" << myRoom.size() << "\n";
		if (SendMessageToOneClient(GameSocket->ID, myRoom) && !flag)
			continue;
		else
			break;
	}*/


	/*
	//����CharacterSelect
	while (true)
	{
		//����   ֻ��Ҫ����which������
		int which;
		char recvBuf[8];
		recv(GameSocket->ClientSock, recvBuf, sizeof(recvBuf), 0);
		sscanf(recvBuf, "%d", &which);

		//����  ����which�����Ͷ�Ӧ������
		std::string send = std::to_string(Rooms[which].playerList.size()) + " ";
		for (auto i : Rooms[which].playerList)
			send += i.nickname + '|';
		cout << send << "\n";
		SendMessageToOneClient(GameSocket->ID, send);
	}*/

	/*
		char sendBuf[1024];
		char recvBuf[1024];
		char Msg[1024];
		int ret, left, idx = 0;
		while (true)
		{
			ZeroMemory(sendBuf, sizeof(sendBuf)); //ZeroMemory������΢��˾�����������SDK�е�һ����,�Խṹ�������г�ʼ��������
			ZeroMemory(recvBuf, sizeof(recvBuf));
			ZeroMemory(Msg, sizeof(Msg));
			cout << "�ȴ����գ�\n";
			ret = recv(GameSocket->ClientSock, recvBuf, sizeof(recvBuf), 0);
			cout << "ret:" << ret << "\n";
			if (ret == 0)
				return 1;
			if (ret == SOCKET_ERROR)
			{
				cout << "����ʧ��\n";
				break;
			}
			if (ret < 1024)
				recvBuf[ret] = '\0';
			else
				cout << "buf is full\n";
			cout << "�յ���Ϣ:" << recvBuf << "\n";
			int whichRoom;
			sscanf(recvBuf, "%d %s", &whichRoom, Msg);
			string msg = Msg;

			if (msg == "#GO_TO_GAME_SCENE!")
			{
				sprintf(sendBuf, "@ %d %d", Rooms[whichRoom].playerList.size(), GameSocket->ID);
				cout << "####��������" << Rooms[whichRoom].playerList.size() << "��\n";
				SendMessageToOneClient(Rooms[whichRoom].playerList.at(GameSocket->ID).clientInfo.ID, sendBuf);
				break;
			}
			else
				sprintf(sendBuf, "[%s said]:%s", inet_ntoa(GameSocket->Client.sin_addr), Msg);

			for (int i = 0; i < Rooms[whichRoom].playerList.size(); i++)
			{
				if (i == GameSocket->ID)
					continue;
				SendMessageToOneClient(Rooms[whichRoom].playerList.at(i).clientInfo.ID, msg);
			}

		}
		cout << "���뿪CharacterSelect,count++\n";
		count++;

		CreateThread(NULL, 0,
			static_cast<LPTHREAD_START_ROUTINE>(GameServer::GameThread), //�̵߳㺯��
			(LPVOID)data, 0,              //����
			&GameSocket->RecvThreadID         //ϵͳ�����ID
		);

		return 0;
	}
	*/

	/*
	���ƣ�����Socket
	�����������˳���Ϸ���߳�
	*/
void GameServer::CleanSocket(int ID)
{
	if (ID < 0)
		return;

	char send[20];
	sprintf(send, "#DD i%d*", ID);
	SendMessageToAllClient(send, ID);


	cout << " ���" << ID << "�˳���Ϸ\n";
	fflush(stdout);

	AcceptSocket[ID].Active = false;
	closesocket(AcceptSocket[ID].ClientSock);
	AcceptSocket[ID].ClientSock = INVALID_SOCKET;
	//cout << "��������,����ô��������������.....AcceptSocket[i].ClientSock :" << AcceptSocket[ID].ClientSock << "\n";

	cout << "���ڹر�������߳�:" << AcceptSocket[ID].RecvThreadID << "\n";
	fflush(stdout);
	ExitThread(AcceptSocket[ID].RecvThreadID);



	cout << "�رճɹ�!\n";
	fflush(stdout);
}


/*	void GameServer::GenerateProps()
{
	static std::random_device rd;
	static std::uniform_int_distribution<int> dist(1,6);

	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++)
			prog_map[i][j] = dist(rd);

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
			cout << prog_map[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";

}

	void GameServer::sendProps(int ID)
{
	const int MAX = 2 * (sizeof(int) * 15 * 15 + 10 * sizeof(int));
	char buffer[MAX];
	ZeroMemory(buffer, sizeof(buffer));
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++)
		{
			sprintf(buffer + 2 * (i * 15 + j), "%d ", prog_map[i][j]);
		}
	string str(buffer);



	fflush(stdout);
	SendMessageToOneClient(ID, str);
	<<<<<< < HEAD
}*/


