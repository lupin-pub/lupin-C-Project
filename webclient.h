#pragma once
#include <winsock2.h>
#include <process.h>
#include <string>
#include <fstream>
#include "    scene" //Áô¿Ó 
#include "cocos2d.h"
#include <queue>
#pragma comment(lib,"ws2_32.lib")

struct recvInfo
{
		int direct;    
		int attack;
		int still;
		float Posx;
		float Posy;
};

class MyClient
{
	public:
		~MyClient();
		void MyProcess(); 
		bool virtual init();
		
		static DWORD WINAPI transmission(LPVOID lpParam);
		static DWORD WINAPI control(LPVOID lpParam);
		
		SOCKET ClientSock;
		struct sockaddr_in ServerSockAddr;
		char RecvBuf[1<<10];
		char SendBuff[1<<10];
		
	private:
		GameScene* runningGameScene;
		HANDLE hMutex;
		static std::queue<recvInfo> recvQueue;
};

