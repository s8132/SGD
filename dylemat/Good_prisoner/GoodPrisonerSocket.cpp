#include "GoodPrisonerSocket.h"

bool Socket::SendData(char* buffer)
{
	send(mySocket, buffer, strlen(buffer), 0);
	return true;
}

bool Socket::ReceiveData(char* buffer, int size)
{
	int i = recv(mySocket, buffer, size, 0);
	buffer[i]='\0';
	return true;
}

void Socket::CloseConnection()
{
	closesocket(mySocket);
	mySocket = myBackup;
}

void ClientSocket::ConnectToServer(char* ipAddress, int port)
{
	myAddress.sin_family = AF_INET;
	myAddress.sin_addr.s_addr = inet_addr(ipAddress);
	myAddress.sin_port = htons(port);

	if(connect(mySocket, (SOCKADDR*) &myAddress, sizeof(myAddress)) == SOCKET_ERROR)
	{
		cout << "Failed to connect" << endl;
		WSACleanup();
		exit(13);
	}
}
 