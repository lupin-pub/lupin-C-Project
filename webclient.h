#pragma once
#include <winsock2.h>
#include <process.h>
#include <string>
#include <fstream>
#include "    scene" //Áô¿Ó 
#include "cocos2d.h"
#include <queue>
#pragma comment(lib,"ws2_32.lib")

struct TransInfo
{
		int direct;    
		int attack;
		int equip;
		float Posx;
		float Posy;
		
};

template <class T> class MyClient
{
	public:
		~MyClient();
		bool MyProcess(T* gamescene); 
		bool virtual init();
		
		static DWORD WINAPI InfoSendThread(LPVOID lpParam);
		static DWORD WINAPI InfoRecvThread(LPVOID lpParam);
		static DWORD WINAPI InfoRecvThread(LPVOID lpParam);
		
		SOCKET ClientSock;
		struct sockaddr_in ServerSockAddr;
		//char RecvBuf[1<<10];ÁÄÌì 
		//char SendBuff[1<<10];
		
	private:
		T* RunGameScene;
		HANDLE hMutex;
		static std::queue<InfoRecv> recvQueue;
		
};

