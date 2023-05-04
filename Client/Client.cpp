#pragma comment(lib, "ws2_32.lib")
#include <iostream>
#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdio.h>
#include <vector>

using namespace std;

const char SERVER_IP[] = "***.***.**.***";
const short SERVER_PORT_NUM = 1234;
const short BUFF_SIZE = 1024;

int main()
{
	WSAData WsData;
	WORD dll_version = MAKEWORD(2, 2);

	int last_error = WSAStartup(dll_version, &WsData);

	if (last_error != 0)
	{
		cerr << "Error:: " << WSAGetLastError() << endl;
		return 1;
	}
	else
	{
		cerr << "WinSock initialization is OK" << endl;
	}

	SOCKET client_socket = socket(AF_INET, SOCK_STREAM, 0);

	if (client_socket == INVALID_SOCKET)
	{
		cerr << "Error with initializing the socket::" << WSAGetLastError() << endl;
		closesocket(client_socket);
		WSACleanup();
		return 1;
	}
	else
	{
		cerr << "Socket initializing is OK" << endl;
	}

	sockaddr_in server_info;

	ZeroMemory(&server_info, sizeof(server_info));

	in_addr adress{};
	last_error = inet_pton(AF_INET, SERVER_IP, &adress);
	if (last_error <= 0)
	{
		cerr << "Convertion ipv4 adress failed, error::" << WSAGetLastError() << endl;
		closesocket(client_socket);
		WSACleanup();
		return 1;
	}
	else
	{
		cerr << "Convertion ipv4 is OK" << endl;
	}

	server_info.sin_family = AF_INET;
	server_info.sin_addr = adress;
	server_info.sin_port = htons(SERVER_PORT_NUM);

	last_error = connect(client_socket, (sockaddr*)&server_info, sizeof(server_info));

	if (last_error != 0)
	{
		cerr << "Connection to server failed, error::" << WSAGetLastError() << endl;
		closesocket(client_socket);
		WSACleanup();
		return 1;
	}
	else
	{
		cerr << "Connection is set up :)" << endl;
	}
	vector <char> servBuff(BUFF_SIZE), clientBuff(BUFF_SIZE);
	short int packet_size = 0;

	while (true) {

		cout << "Your (Client) message to Server: ";
		fgets(clientBuff.data(), clientBuff.size(), stdin);

		// Check whether client like to stop chatting 
		if (clientBuff[0] == 'x' && clientBuff[1] == 'x' && clientBuff[2] == 'x') {
			shutdown(client_socket, SD_BOTH);
			closesocket(client_socket);
			WSACleanup();
			return 0;
		}


	}

	closesocket(client_socket);
	WSACleanup();

	return 0;
}