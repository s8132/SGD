
#include <iostream>
#include "ArbiterSocket.h"

using namespace std;

const int STRLEN = 256;

int main()
{
	int choice;
	int port = 1313;
	char* ipAddress = "127.0.0.1";
	char recMessage[STRLEN];
	char sendMessage[STRLEN];
	bool done = false;

		ServerSocket sockServer;
		cout << "HOSTING..." << endl;
		sockServer.StartHosting(port);
		sockServer.Listen();
		while(!done)
		{
			cout << "waiting for message..." << endl;
			sockServer.ReceiveData(recMessage, STRLEN);
			cout << "Client>" << recMessage << endl;
			cout << "\nEnter message..." << endl;
			cin >> sendMessage;
			cout << "Server>" << sendMessage << endl;
			sockServer.SendData(sendMessage);
			cout << "message sent" << endl;
			if(strcmp(recMessage, "end") == 0 || strcmp(sendMessage, "end") == 0)
			{
				done = true;
			}
		}

	return 0;
}
 