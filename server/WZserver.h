#include <winsock2.h>
#include <process.h>               //C中的线程 
#include <string>
#include <random>
#include <array>
#pragma comment(lib,"ws2_32.lib")

//<<<<<<< HEAD
	/*
	Maybe:线程的部分或许会改用C++11的thread类来写
	*/

	//>>>>>> > WebGameLogic

struct  WZClientInformation           //Client 相关信息
{
	SOCKET ClientSock;       //套接字
	//<<<<<< < HEAD
	sockaddr_in Client;      //Clinet IP

	//sockaddr_in Client;      //Clinet IP port
//>>>>>> > WebGameLogic
	int ID;                   //Server分配的ID号码
	DWORD RecvThreadID;        //Server分配接收的线程号
	DWORD SendThreadID;			//Server分配发送的线程号
	bool Active;
};

//<<<<<< < HEAD


struct PlayerInfo {
	std::string nickname;
	struct  WZClientInformation clientInfo;
	int order;
};


/*struct RoomInfo {
	std::string name;   //房间名称
	long id;           //房间号
	std::vector <PlayerInfo> playerList;   //玩家列表
	int curNum;        //当前房间里面的人数
};*/


//>>>>>> > WebGameLogic
class GameServer
{
protected:
	enum {

		MAX_NUM = 2  //最大上限人数   //我就先做一个的demo，需要改的话自己加就行了

		//MAX_NUM = 4  //最大上限人数  

	};
public:
	GameServer();
	~GameServer();

	int ProcessGameServer();    //线程处理

	static int SendMessageToOneClient(int ID, const std::string  str);  //向某一个Client发送信息

	int CheckSocket();     //检测当前可用的ID号
	static void CleanSocket(int ID); //清空ID号的套接字
	static void SendMessageToAllClient(const std::string  str, int ID = -1); //向所有Client发送信息
	//<<<<<< < HEAD

		//Socket 相关
public:
	static DWORD WINAPI ListenThread(void *data); //接受线程


protected:


	//线程
public:
	static DWORD WINAPI GameThread(void *data); //接受线程
	static DWORD WINAPI sendRoomInfo(void *data);

private:
	//>>>>>> > WebGameLogic
	SOCKET ListenSocket;       //等待接受数据的socket,此为真·Server
	static WZClientInformation AcceptSocket[MAX_NUM];  //Client的相关信息，此为真·Clients
	sockaddr_in Server;        //绑定地址

	//对网络数据的处理
public:
	void GenerateProps();
	static void sendProps(int ID);
	//static int prog_map[15][15];		
		//static std::vector <RoomInfo> Rooms;
	static std::vector <PlayerInfo> allPlayerInfo;
};

