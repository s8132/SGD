#include <iostream>
#include <string>
          #include "GoodPrisonerSocket.h"

using namespace std;

const int STRLEN = 256;
                                 
int main(int argc, char* argv[])
{
        int choice;
	int port;
	string ipAddress;
        char* ip;
	char recMessage[STRLEN];
	char sendMessage[STRLEN];                            
        bool done = false;

        cout << "Enter the port: ";
        cin >> port;
        cout << "Enter ip address: ";
        cin >> ipAddress;
        ipAddress = strcpy(ip, ipAddress.c_str());

        	ClientSocket sockClient;
		cout << "ATTEMPTING TO CONNECT" << endl;
		sockClient.ConnectToServer(ip, port);
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



        return 0;
}
//---------------------------------------------------------------------------
 