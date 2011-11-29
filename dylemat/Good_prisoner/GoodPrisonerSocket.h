//GoodPrisonerSocketScoket.h

#pragma once
#include <iostream>
#include <WinSock2.h>

using namespace std;

class Socket
{
protected:
	WSADATA wsaData;
	SOCKET mySocket;
	SOCKET myBackup;
	sockaddr_in myAddress;
public:
	Socket();
	~Socket();
	bool SendData(char*);
	bool ReceiveData(char*, int);
	void CloseConnection();


};

class ClientSocket : public Socket
{
public:
	void ConnectToServer(char*, int);
};
 
 