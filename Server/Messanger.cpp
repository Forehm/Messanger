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

	in_addr adress;
	last_error = inet_pton(AF_INET, "***.***.**.***", &adress);

	if (last_error <= 0)
	{
		cerr << "Error in IP translation to special numeric format" << endl;
		return 1;
	}

	sockaddr_in server_info;
	ZeroMemory(&server_info, sizeof(server_info));

	server_info.sin_family = AF_INET;
	server_info.sin_addr = adress;
	server_info.sin_port = htons(1234);

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
}