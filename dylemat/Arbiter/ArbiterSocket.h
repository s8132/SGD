//ArbiterSocket.h

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
	SOCKET acceptSocket;
	sockaddr_in myAddress;
public:
	Socket();
	~Socket();
	bool SendData(char*);
	bool ReceiveData(char*, int);
	void CloseConnection();


};

class ServerSocket : public Socket
{
public:
	void Listen();
	void StartHosting(int);
};
/*
class ClientSocket : public Socket
{
public:
	void ConnectToServer(char*, int);
};
*/