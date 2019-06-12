#define _CRT_SECURE_NO_WARNINGS
#include <winsock2.h>
#include <fstream>
#include <random>
#include <process>
#include <queue>
#include <string>

#include "cocos2d.h"
#include "BaseMonster.h"
#include "webclient.h"
//还有一些头文件要包括 留坑.. 

#define PORTS 1236  //端口号~~~呼唤钰儿~~~ 

#pragma
#pragma  //留坑 

USING_NS_CC;
using std::queue;
using std::fstream;
using std::string;
using std::endl; 
std::queue<recvInfo> MyClient::recvQueue; 
/***
名称：初始化
功能：连接服务端
***/

static inline GameScene* getGameScene()//留坑 不知道小伙伴们定义类的名字 
{
	auto scene=Director::getInstance()->getRunningScene();
	return dynamic_cast<GameScene*>(scene->getChildByTag(  )); //留坑 tag不晓得 
}

bool MyClient::init()
{
	std::fstream outfile;
	outfile.open("    ");  //留坑 
	
	WSADATA MyWSAData;
	if(WSAStartup(MAKEWORD(2, 2), &MyWSAData) != 0)  //初始化socket环境 
	{
		return false;
	}
	
	if((ClientSock = socket(PF_INET, SOCK_STREAM, 0))== INVALID_SOCKET)   //创建失败 
	{
		WSACleanup(); 
		outfile<<"bind socket error: "<<strerror(errno)<<"(error: "<<errno<<")"<<endl;  //not sure
		return false;
	} 
	
	memset(&ServerSockAddr,0,sizeof(ServerSockAddr));
	ServerSockAddr.sin_family = PF_INET;            //指定ip地址和端口号 
	ServerSockAddr.sin_port =  htons(PORTS);
	ServerSockAddr.sin_addr.S_un.S_addr = inet_addr("  ");  //留坑 
	
	unsigned long ul=1;
    int ret=ioctlsocket(ClientSock, FIONBIO, (unsigned long *)&ul);//设置成非阻塞模式。 
    if(ret==SOCKET_ERROR)//设置失败。  
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
		fd_set fd;
		struct timeval SuspendTime;
		
		FD_ZERO(&fd);
		FD_SET(ClientSock,&fd);
		SuspendTime.tv_sec= 0.1;
		SuspendTime.tv_usec=0;
		
		int sel= select(ClientSocket, NULL, &fd, NULL, &SuspendTime);
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


	
DWORD WINAPI MyClient::Tansmission(LPVOID PROCURATOR1,LPVOID PROCURATOR2)  //塔 英雄 兵*3 
{
	MyClient *myclient1 = static_cast<MyClient *>(PROCURATOR1);
	MyClient *myclient2 = static_cast<MyClient *>(PROCURATOR2);
	
	const int PACKAGE =       ;//留坑 每次发送包的长度未定 
	
	char SendContent[1<<10];
	
	static int times = 0;
	
	while(true)
	{
		WaitForSingleObject(myclient1->hMutex, INFINITE);
		
		fd_set wfd,rfd;
		FD_ZERO(&rfd);
		FD_ZERO(&wfd);
		
		FD_SET(myclient1->ClientSock,&wfd);
		FD_SET(myclient2->ClientSock,&rfd);
		
		int sel = select(0,&rfd,&wfd,NULL,NULL);
		if(sel>0)
		{
			if(FD_SET(myclient1->ClientSock,&wfd))
			{
				BaseMonster* myplayer = dynamic_cast<BaseMonster*>(myclient1->runningGameScene->getChildByName("   "));
				if(myplayer==nullptr)
				{
					return 0;
				}
				int SendStill = myplayer->still;
				
				int SendAttack = 0;
				SendAttack = myplayer->attack;
				
				int SendDirect = myplayer->direct;    
        		
				Vec2 pos = myplayer->getPosition();
				
				char SendData[1<<10];
				ZeroMemory(SendData,sizeof(SendData));
				
				sprintf(SendData,"%d %d %d %f %f",SendStill,SendAttack,SendDirect,pos.x,pos.y);
				
				int sendByte = 0;
				while(sendByte<PACKAGE)
				{
					int ret = send(myclient1->ClientSock,SendData,strlen(SendData)+sizeof(char),0);
					sendByte += ret;
					
				}
			}
				if(FD_ISSET(myclient2->ClientSock,&rfd))
				{
					InfoRecv = new SendInfo[1];
					BaseMonster* myplayer2 = dynamic_cast<BaseMonster*>(myclient2->runningGameScene->getChildByName("   "));
			     	if(myplayer2==nullptr)
		     		{
		    			return 0;
		     		}
		     		int RecvStill = myplayer2->still;
				
		     		int RecvAttack = 0;
	     			RecvAttack = myplayer2->attack;
				
	    			int RecvDirect = myplayer2->direct;    
        		
		     		Vec2 pos_2 = myplayer2->getPosition();
				
	     			char RecvData[PACKAGE*100];
		    		ZeroMemory(RecvData,sizeof(RecvData));
		    		
		    		int RecvByte = 0;
		    		int ret;
				
		     		while(RecvByte<PACKAGE)
		     		{
			     		int ret = recv(myclient2->ClientSock,RecvData,PACKAGE*100,0);
			    		RecvByte += ret;
				    }
				    
				    int len = RecvByte/PACKAGE;
				    RecvData[PACKAGE] = '\0';
				    
				    for (int i = 0; i < len; i++)
				    {
				    	RecvInfo temp;
		     			sscanf(RecvData + i*PACKAGE, "%d %d %d %f %f",&temp.still,&temp.attack,&temp.direct,&temp.Posx,&temp.Posy);
	    				recvQueue.push(temp);
		    		}
		    		
		    	}
		    }
		    ReleaseMutex(myclient1->hMutex);
		}
	return 1;
}
					/*
					character* myplayer2 = dynamic_cast<character*> (myclient0->runningGameScene->getChildName("  "));
					if(myplayer2 ==nullptr)
					{
						break;
					}
					
					if(mypalyer2->blood <= 0)
					{
						send(myclient1->ClientSock,"#GAMEOVER! congratulations! you win!#",strlen("#GAMEOVER! congratulations! you win!#")+sizeof(char),0);
						win = 0;
						break;
					}
					
					if(typeid(*(myplayer2->mCurState)).hash_code() == typeid(CharMove).hash_code())
					{
 						int InfoSend->Direct = myplayer->direct;    
        	         	int InfoSend->Blood = myplayer->blood;   
                		int InfoSend->HeroLevel = myplayer->HeroLevel;  
                		int InfoSend->Money = myplayer->money;   
                		int InfoSend->Buff = myplayer->Buff;  
                 		int InfoSend->Experience = myplayer->experience;
                		int InfoSend->Attack = myplayer->attack;
                 		int InfoSend->StandardBuff = myplayer->StandardBuff;
                 		int InfoSend->KillNum = myplayer->KillNum;
                 		int InfoSend->KilledNum = myplayer->KilledNum;
                 		int InfoSend->EquipIndex = myplayer->EquipIndex;
                 		
                 		Vec2 pos2 = myplayer2->getPosition();
                 		
                 		if(InfoReserved != nullptr)
                 		{
                 			if(!memcpy(InfoReserved,InfoSend,sizeof(InfoSend)))
                 			{
                 				times++;
                 				if(times<200)
                 				    continue;
                 				else
                 				    times = 0;
							}
							else
							{
								memcpy(InfoReserved,InfoSend,sizeof(InfoSend));
							}
						}
						else
						{
							InfoReserved = new SendInfo[1];
							memcpy(InfoReserved,InfoSend,sizeof(InfoSend));
						}
						
						ZeroMemory(SendData,sizeof(SendData));
						
						sprinff(SendData,"%d %d %d %d %d %d %d %d %d %d %d %d %d %f %f",InfoSend->Direct,InfoSend->Blood,InfoSend->HeroLevel,InfoSend->Money,InfoSend->Buff,InfoSend->Experience,InfoSend->Attack,InfoSend->StandardBuff,InfoSend->KillNum,InfoSend->KilledNum,InfoSend->EquipIndex,pos2.x,pos2.y);
						
						int SendByte = 0;
						while(SendByte<PACKAGE)
						{
							int ret = send(myclient1->ClientSock,SendData,strlen(SendData)+sizeof(char),0);
							SendByte+=ret; 
						} 
						 
					}
					*/ 
	/*		    }
			}
		}
	} 
	
	if(InfoReserved != nullptr)
	{
		delete[]InfoReserved;
	}
	return 1;	
}**/
/***
DWORD WINAPI MyClient::InfoRecvThread(LPVOID PROCURATOR)
{
	MyClient *myclient1 = static_cast<MyClient *>(PROCURATOR);
	const int PACKAGE =    ;
	char RecvData[PACKAGE* 100];
	
	while(true)
	{
		fd_set rfd;
		FD_ZERO(&rfd);
		FD_SET(myclient1->ClientSock,&rfd);
		int sel = select(0,&rfd,NULL,NULL,NULL);
		if(sel>0)
		{
			if(FD_SET(myclient1->ClientSock,&rfd))
			{
				int direct;    //朝向 
        		int blood;   //血量 
        		int HeroLevel;  // 英雄等级 
         		int money;   //钱 
        		int Buff;  
        		int experience;
        		int attack;
         		int StandardBuff;
         		int KillNum;
        		int KilledNum;
	        	int EquipIndex;
	        	ZeroMemory(RecvData,sizeof(RecvData));
				
				int temp = 0;
				
				int ret,len=0;
				
				while(recvByte<PACKAGE)
				{
					ret = recv(myclient2->ClientSock,RecvData,PACKAGE*100,0);
					if(ret == SOCKET_ERRO)
					{
						continue;
					}
					len++;
				}
				
				if(recvData[0] =='#')
				{
					win = 1;
					break;
				}
				
				recvData[PACKAGE] = '\0';
				
				for(int i =0;i<len;i++)
				{
					RecvInfo temp;
					sscanf(recvData+i*PACKAGE,"%d %d %d %d %d %d %d %d %d %d %d %d %d %f %f",&temp.Direct,&temp.Blood,&temp.HeroLevel,&temp.Money,&temp.Buff,&temp.Experience,&temp.Attack,&temp.StandardBuff,&temp.KillNum,&temp.KilledNum,&temp.EquipIndex,&temp.posx,&temp.posy);
					
					g_lock.lock();
					RecvInfoQueue.push(temp);
					g_lock.unlock();
				}
			}
		}
		
		ReleaseMutex(myclient1->hMutex);
		
	}
	
	WaitForSingleObject(myclient1->hMutex,INFINITE);
	return 1;
}
*/ 



DWORD WINAPI MyClient::control(LPVOID lpParam)
{
	MyClient *myclinet = (MyClient *)lpParam;
	
	if(recvQueue.empty() == true)
	{
		return 0;
	}
	
	BaseMonster * player2 = dynamic_cast<BaseMonster*>(myclient->runningGameScene->getChildByName("player2"));
	WaitForSingleObject(myclient->hMutex,INFINITE);
	while(true)
	{
		recvInfo temp;
		if(!recvQueue.empty())
		{
			temp = recvQueue.front();
		}
		else
		{
			ReleaseMutex(myclient->hMutex);
			break;
		}
		if(temp.Posx>0&&temp.Posy>0)
		{
			player2->setPosition(temp.Posx,temp.Posy);
		}
		else
		{
			ReleaseMutex(myclient->hMutex);
			break;
		}
		
		Vec2 Pos(temp.Posx,temp.Posy);
		
		if(temp.attack)
		{
			//留坑 等对接再说吧 
			
			
		}
		if(!recvQueue.empty())
		{
			recvQueue.pop();
		}
		else
		{
			ReleaseMutex(myclient->hMutex);
			break;
		}
	}
	ReleaseMutex(myclient->hMutex);
	WaitForSingleObject(myclient->hMutex.INFINITE);
	return 1;
}


WINAPI MyClient::MyProcess(LPVOID procurator)
{
	if(!runningGameScene)
	{
		runningGameScene = getGameScene();
		if(runningGameScene == nullptr)
		{
			return;
		}
	} 

	HANDLE SendThread,RecvThread;
	SendThread = CreateThread(NULL,0,static_cast<LPTHREAD_START_ROUTINE>(MyClient::InfoSendThread),static_cast<LPVOID>(this),0,NULL));
	RecvThread = CreateThread(NULL,0,static_cast<LPTHREAD_START_ROUTINE>(MyClient::InfoRecvThread),static_cast<LPVOID>(this),0,NULL));
	
	CloseHandle(SendThread);
	CloseHandle(RecvThread);
	
	/***
	hMutex = CreateMutex(nullptr,TRUE,TEXT("control"));
	if(hMutex)
	{
		if(ERROR_ALREADY_EXISTS == GetLastError())
		{
			return;
		}
		
	}
	***/
	
	hMutex = CreateMutex(nullptr, TRUE, TEXT("Control"));
	if (hMutex)
	{
		if (ERROR_ALREADY_EXISTS == GetLastError())
		{
			return;
		}
	}
	WaitForSingleObject(hMutex, INFINITE);
	ReleaseMutex(hMutex); 
	ReleaseMutex(hMutex);
	return true;
}

MyClient::~MyClient()
{
	closesocket(ClientSock);
	WSACleanup();
}








