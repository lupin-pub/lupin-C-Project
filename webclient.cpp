#define _CRT_SECURE_NO_WARNINGS
#include <winsock2.h>
#include <fstream>
#include <random>
#include <string>
#include <cstring>
#include <mutex>
#include "../   /DJGameScene.h"
#include "../   /HYGameScene.h"
#include "../   /YSGameScene.h"
#include "../   /GameManager.h" 
#include "../   /BaseMonster.h"

#include "ui/CocosGUI.h"
#include "cocos2d.h"
#include "webclient.h"
//����һЩͷ�ļ�Ҫ���� ����.. 

#define PORTS 1236  //�˿ں�~~~�����ڶ�~~~ 
USING_NS_CC;
using namespace ui;

using std::queue;
using std::fstream;
using std::string;
using std::endl; 

std::queue<TransInfo> MyClient::recvQueue; 

std::mutex g_lock;

extern bool win; //���� 

/**
static inline DJGameScene* getDJGameScene()//���� ��֪��С����Ƕ���������� 
{
	auto scene=Director::getInstance()->getRunningScene();
	return dynamic_cast<DJGameScene*>(scene->getChildByTag(  )); //���� tag������ 
}

static inline HYGameScene* getHYGameScene()//���� ��֪��С����Ƕ���������� 
{
	auto scene=Director::getInstance()->getRunningScene();
	return dynamic_cast<HYGameScene*>(scene->getChildByTag(  )); //���� tag������ 
}

static inline YSGameScene* getYSGameScene()//���� ��֪��С����Ƕ���������� 
{
	auto scene=Director::getInstance()->getRunningScene();
	return dynamic_cast<YSGameScene*>(scene->getChildByTag(  )); //���� tag������ 
}
**/
template <class T>
bool MyClient<T>::init()
{
	std::fstream outfile;
	outfile.open("    ");  //���� 
	
	WSADATA MyWSAData;
	if(WSAStartup(MAKEWORD(2, 2), &MyWSAData) != 0)  //��ʼ��socket���� 
	{
		return false;
	}
	
	memset(&ServerSockAddr,0,sizeof(ServerSockAddr));
	ServerSockAddr.sin_family = PF_INET;            //ָ��ip��ַ�Ͷ˿ں� 
	ServerSockAddr.sin_port =  htons(PORTS);
	ServerSockAddr.sin_addr.S_un.S_addr = inet_addr("  ");  //���� 
	
	if((ClientSock = socket(PF_INET, SOCK_STREAM, 0))== INVALID_SOCKET)   //����ʧ�� 
	{
		WSACleanup(); 
		return false;
	} 	
	
	unsigned long ul=1;
    int ret=ioctlsocket(ClientSock, FIONBIO, (unsigned long *)&ul);//���óɷ�����ģʽ�� 
    if(ret==SOCKET_ERROR)//����ʧ�ܡ�  
    {
    	outfile<<"the setting of non-blocks failed!"; 
		closesocket(ClientSock); 
		WSACleanup(); 
		return false;
    } 
    else 
    {
    	outfile<<"the setting of non-blocks succeed"<<endl;
	}
	
	if(connect(ClientSock,static_cast<LPSOCKADDR>(&ServerSockAddr),sizeof(ServerSockAddr))<0)
	{
		fd_set wfd;
		struct timeval SuspendTime;
		
		FD_ZERO(&wfd);
		FD_SET(ClientSock,&wfd);
		SuspendTime.tv_sec= 0.1;
		SuspendTime.tv_usec=0;
		
		int sel= select(ClientSocket, NULL, &wfd, NULL, &SuspendTime);
		if (sel<= 0)
		{
			outfile << "connection fail"<<endl;
			closesocket(ClientSock);
			WSACleanup();
			return false;
		}
	}
	outfile << "the client has connected successfully!"<<endl;
	outfile.close();
	return true;
}

template <class T>
DWORD WINAPI MyClient<T>::InfoSendThread(LPVOID lpParam)  //�� Ӣ�� ��*3 
{
	MyClient<T> *myclient = static_cast<MyClient<T> *>(lpParam); //���� 
	const int PACKAGE = 28 ;//���� ÿ�η��Ͱ��ĳ���δ�� 
	char SendContent[1<<10];
	TransInfo * reserve = nullptr;
	TransInfo * send; 
//	static int times = 0;

	while(true)
	{
		fd_set wfd;
		FD_ZERO(&wfd);
		FD_SET(myclient->ClientSock,&wfd);
		int sel = select(0,NULL,&wfd,NULL,NULL);
		if(sel>0)
		{
			if(FD_ISSET(myclient->ClientSock,&wfd))
			{
				send = new TransInfo[1];
				
				BaseMonster* myplayer = dynamic_cast<BaseMonster*>(myclient->RunGameScene->getChildByName("myplayer"));
				if(myplayer==nullptr)
				{
					break;
				}
				if(   <=0) //ˮ����ûѪ�� 
				{
			        send(myclient->ClientSock,"!Gameover_youwin!",strlen("!Gameover_youwin!")+sizeof(char),0);
					win = 0;
					break; 
				} 
				if(myplayer->isAttacking==true)
				send->attack = 1;
				else
				send->attack = 0;
				if(   ) //�������װ�� 
				send->equip = 1;
				else
				send->equip = 0; 
				if (typeid(*(myplayer->mCurState)).hash_code() == typeid(CharMove).hash_code() || send->attack ||send->equip) //���Ӹ�py 
				{
					send->direct = myplayer->direct;//���Ӹ�py
					Vec2 pos = myplayer->getPosition();
					send->Posx = pos.x;
					send->Posy = pos.y;
					
					if(reserve!=nullptr)
					{
						if(!memcmp(reserve,send,sizeof(reserve))&&!send->attack&&!send->equip)  //���û���Ͳ��� 
						{
							times++;
							if(time<200)
							continue;
							else
							times = 0;
						}
						else
						memcpy(reserve, send, sizeof(reserve));
					}
					{
						reserve = new TransInfo[1];
						memcpy(reserve, send, sizeof(reserve));
					} 
					ZeroMemory(SendContent, sizeof(SendContent));
					sprintf(SendContent,"%d %d %d %f %f",send->equip,send->attack,send->direct,pos.x,pos.y);
					
					int byte = 0;
					while(byte<PACKAGE)
					{
						int m = send(myclient->ClientSock,SendContent,strlen(SendContent)+sizeof(char),0);
						byte += m;
					}
				}
				delete[]send;
			}
		}
	}
	if(reserve != nullptr)
	{
		delete[]reserve;
	}
	return 1;
}
//���� ���MyClient<T> 
template<class T>
DWORD WINAPI MyClient<T>::InfoRecvThread(LPVOID lpParam)
{
	MyClient<T> *myclient = static_cast<MyClient<T> *>(lpParam);
	const int PACKAGE = 28;
	char RecvContent[PACKAGE * 100];

	while (true)
	{
		fd_set rfd;
		FD_ZERO(&rfd);
		FD_SET(myclient->ClientSock, &rfd);
		int sel = select(0, &rfd, NULL, NULL, NULL);
		if (sel > 0)
		{
			if (FD_ISSET(myclient->ClientSock, &rfd))
			{
				ZeroMemory(RecvContent, sizeof(RecvContent));

				int direct2;
				int attack2 = 0;
				
				int byte2 = 0;
				int n;
				while (byte2 < PACKAGE)
				{
					n = recv(myclient->ClientSock, RecvContent, PACKAGE * 100, 0);
					if (n == SOCKET_ERROR)
						continue;
					byte2 += n;
				}
				RecvContent[PACKAGE] = '\0';

				if (RecvContent[0] == '#')
				{
					win = 1;
					break;
				}

				for (int i = 0; i < (byte2 / PACKAGE); i++)
				{
					TransInfo temp;
					sscanf(RecvContent + i*PACKAGE, "%d %d %d %f %f",&temp.equip, &temp.attack, &temp.direct,&temp.Posx, &temp.Posy);
	
					g_lock.lock();
					recvQueue.push(temp);
					g_lock.unlock();
				}
			}
		}
	}
}

template <class T>
DWORD WINAPI MyClient<T>::InfoControlThread(LPVOID lpParam)
{
	MyClient<T> *myclient = (MyClient<T> *)lpParam;
	//���� 
	BaseMonster* enemy = dynamic_cast<BaseMonster*>(myclient->RunGameScene->getChildByName("enenmy"));
	
	while(true)
	{
		TransInfo temp;
		g_lock.lock();
		if(!recvQueue.empty())
		{
			temp = recvQueue.front();
			recvQueue.pop();
			g_lock.unlock();
		}
		else
		{
			g_lock.unlock();
			continue;
		}
		Vec2 Pos(temp.Posx,temp.Posy);
		if(temp.attack)
		{
			
			//���ӶԽ� 
			
		}
		if(temp.equip)
		{
			
			//���ӶԽ� 
			
		}
		if(temp.Posx>0&&temp.Posy>0)
		{
			enemy0>setPosition(temp.Posx,temp.Posy);
		}
		else
		continue;
	}
	return 1;
}


template<class T>
bool MyClient<T>::MyProcess(T* gamescene)
{
	RunGameScene = gamescene;
	
	HANDLE SendThread,RecvThread,ControlThread;
	SendThread = CreateThread(NULL,0,static_cast<LPTHREAD_START_ROUTINE>(MyClient<T>::InfoSendThread),static_cast<LPVOID>(this),0,NULL));
	RecvThread = CreateThread(NULL,0,static_cast<LPTHREAD_START_ROUTINE>(MyClient<T>::InfoRecvThread),static_cast<LPVOID>(this),0,NULL));
	ControlThread = CreateThread(NULL,0,static_cast<LPTHREAD_START_ROUTINE>(MyClient<T>::InfoControlThread),static_cast<LPVOID>(this),0,NULL)); //��ȷ������ 
	
	CloseHandle(SendThread);
	CloseHandle(RecvThread);
	CloseHandle(ControlThread); 
	
	return true;
}

template<class T> 
bool MyClient<T>::GameConnect()
{
	char buf[25];
	recv(ClientSock,buf,strlen(buf)+sizeof(char),0);
	if(buf[0]=='#')
	return true;
} 

template<class T>
void MyClient<T>::MyHeroSelect(int type)
{
	MyType = type;
	char buf[5];
	ZeroMemory(buf,sizeof(buf));
	sprintf(buf,"%d",type);
	send(ClientSock,buf,strlen(buf)+sizeof(char),0);
}
template<class T>
int MyClient<T>::EnemyHeroSelect()
{
	char buf[5];
	ZeroMeory(buf,sizeof(buf));
	recv(ClinetSock,buf,strlen(buf)+sizeof(char),0);
	int type;
	if(buf[0] =='0')
	type = 0;
	if(buf[0] == '1')
	type = 1;
	if(buf[0] == '2')
	type = 2;
	return type;
}
template <class T>
MyClient<T>::~MyClient()
{
	closesocket(ClientSock);
	WSACleanup();
}








