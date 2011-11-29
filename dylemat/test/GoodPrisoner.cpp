#include <iostream>
#include <string.h>
#include <conio.h>
#include "GoodPrisonerSocket.h"

using namespace std;

const int STRLEN = 256;

int main(int argc, char* argv[])
{



int choice;
	int port;

        string ip;
	char recMessage[STRLEN];
	char sendMessage[STRLEN];
	bool done = false;

        cout << "Enter port: ";
        cin >> port;
        cout << "Enter ip address: ";
        cin >> ip;

        cout << "I' m connectin to " << ip << " on " << port << endl;
        
        char *ipAddress = new char[ip.length()+1];
        strcpy(ipAddress, ip.c_str());


        ClientSocket sockClient;
        cout << "ATTEMPTING TO CONNECT" << endl;
        sockClient.ConnectToServer(ipAddress, port);
        while(!done)
        {
                cout << "enter message" << endl;
		cin >> sendMessage;
		cout << "Client>" << sendMessage << endl;
		sockClient.SendData(sendMessage);
		cout << "message sent" << endl;
		cout << "waiting for message" << endl;
		sockClient.ReceiveData(recMessage, STRLEN);
		cout << "Server>" << recMessage << endl;

		if(strcmp(recMessage, "end") == 0 || strcmp(sendMessage, "end") == 0)
		{
			done = true;
		}

        }
	sockClient.CloseConnection();

        getch();
        return 0;
}
//---------------------------------------------------------------------------
 