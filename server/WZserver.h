#include <winsock2.h>
#include <process.h>               //C�е��߳� 
#include <string>
#include <random>
#include <array>
#pragma comment(lib,"ws2_32.lib")

//<<<<<<< HEAD
	/*
	Maybe:�̵߳Ĳ��ֻ�������C++11��thread����д
	*/

	//>>>>>> > WebGameLogic

struct  WZClientInformation           //Client �����Ϣ
{
	SOCKET ClientSock;       //�׽���
	//<<<<<< < HEAD
	sockaddr_in Client;      //Clinet IP

	//sockaddr_in Client;      //Clinet IP port
//>>>>>> > WebGameLogic
	int ID;                   //Server�����ID����
	DWORD RecvThreadID;        //Server������յ��̺߳�
	DWORD SendThreadID;			//Server���䷢�͵��̺߳�
	bool Active;
};

//<<<<<< < HEAD


struct PlayerInfo {
	std::string nickname;
	struct  WZClientInformation clientInfo;
	int order;
};


/*struct RoomInfo {
	std::string name;   //��������
	long id;           //�����
	std::vector <PlayerInfo> playerList;   //����б�
	int curNum;        //��ǰ�������������
};*/


//>>>>>> > WebGameLogic
class GameServer
{
protected:
	enum {

		MAX_NUM = 2  //�����������   //�Ҿ�����һ����demo����Ҫ�ĵĻ��Լ��Ӿ�����

		//MAX_NUM = 4  //�����������  

	};
public:
	GameServer();
	~GameServer();

	int ProcessGameServer();    //�̴߳���

	static int SendMessageToOneClient(int ID, const std::string  str);  //��ĳһ��Client������Ϣ

	int CheckSocket();     //��⵱ǰ���õ�ID��
	static void CleanSocket(int ID); //���ID�ŵ��׽���
	static void SendMessageToAllClient(const std::string  str, int ID = -1); //������Client������Ϣ
	//<<<<<< < HEAD

		//Socket ���
public:
	static DWORD WINAPI ListenThread(void *data); //�����߳�


protected:


	//�߳�
public:
	static DWORD WINAPI GameThread(void *data); //�����߳�
	static DWORD WINAPI sendRoomInfo(void *data);

private:
	//>>>>>> > WebGameLogic
	SOCKET ListenSocket;       //�ȴ��������ݵ�socket,��Ϊ�桤Server
	static WZClientInformation AcceptSocket[MAX_NUM];  //Client�������Ϣ����Ϊ�桤Clients
	sockaddr_in Server;        //�󶨵�ַ

	//���������ݵĴ���
public:
	void GenerateProps();
	static void sendProps(int ID);
	//static int prog_map[15][15];		
		//static std::vector <RoomInfo> Rooms;
	static std::vector <PlayerInfo> allPlayerInfo;
};

