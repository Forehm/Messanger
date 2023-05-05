#pragma comment(lib, "ws2_32.lib")
#include <iostream>
#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <set>
#include "Tests.h"
#include "Server.h"

using namespace std;

const int BUFF_SIZE = 256;



const char SERVER_IP[] = "***.***.**.***";
const int PORT_NUMBER = 1234;
const short BUFF_SIZE = 1024;




int main()
{
	TestServer();


	WSADATA wsData;
	WORD dll_version = MAKEWORD(2, 2);

	int last_error = WSAStartup(dll_version, &wsData);


	if (last_error == 0)
	{
		cerr << "WinSock initialization is OK" << endl;
	}
	else
	{
		cerr << "Error::" << WSAGetLastError() << endl;
	}

	SOCKET server_socket = socket(AF_INET, SOCK_STREAM, 0);

	if (server_socket == INVALID_SOCKET)
	{
		cerr << "Error::" << WSAGetLastError() << endl;
		closesocket(server_socket);
		WSACleanup();
		return 1;
	}
	else
	{
		cerr << "Server socket initialization is OK" << endl;
	}

	in_addr adress{};
	last_error = inet_pton(AF_INET, SERVER_IP, &adress);

	if (last_error <= 0)
	{
		cerr << "Error in IP translation to special numeric format" << endl;
		return 1;
	}

	sockaddr_in server_info;
	ZeroMemory(&server_info, sizeof(server_info));

	server_info.sin_family = AF_INET;
	server_info.sin_addr = adress;
	server_info.sin_port = htons(PORT_NUMBER);

	last_error = bind(server_socket, (sockaddr*)&server_info, sizeof(server_info));

	if (last_error != 0)
	{
		cerr << "Error Socket binding to server::" << WSAGetLastError() << endl;
		closesocket(server_socket);
		WSACleanup();
		return 1;
	}
	else
	{
		cerr << "Binding socket to Server info is OK" << endl;
	}

	last_error = listen(server_socket, SOMAXCONN);

	if (last_error != 0)
	{
		cerr << "Errors with listening to socket::" << WSAGetLastError() << endl;
		closesocket(server_socket);
		WSACleanup();
		return -1;
	}

	sockaddr_in client_info;

	ZeroMemory(&client_info, sizeof(client_info));

	int client_info_size = sizeof(client_info);

	SOCKET client_connection = accept(server_socket, (sockaddr*)&client_info, &client_info_size);

	if (client_connection == INVALID_SOCKET)
	{
		cerr << "Client detected, but can't connect to a client. Error # " << WSAGetLastError() << endl;
		closesocket(server_socket);
		closesocket(client_connection);
		WSACleanup();
		return 1;
	}
	else
	{
		cerr << "Connection to a client established successfully" << endl;
	}

	vector<char> server_buffer(BUFF_SIZE), client_buffer(BUFF_SIZE);

	short packet_size = 0;

	while (true)
	{
		packet_size = recv(client_connection, server_buffer.data(), server_buffer.size(), 0);
		cout << "Clients message: " << server_buffer.data() << endl;

		cout << "Host message: ";
		fgets(client_buffer.data(), client_buffer.size(), stdin);

		if (client_buffer[0] == 'x' && client_buffer[1] == 'x' && client_buffer[2] == 'x') {
			shutdown(client_connection, SD_BOTH);
			closesocket(server_socket);
			closesocket(client_connection);
			WSACleanup();
			return 0;
		}

		packet_size = send(client_connection, client_buffer.data(), client_buffer.size(), 0);

		if (packet_size == SOCKET_ERROR) {
			cout << "Can't send message to Client. Error # " << WSAGetLastError() << endl;
			closesocket(server_socket);
			closesocket(client_connection);
			WSACleanup();
			return 1;
		}
	}
}