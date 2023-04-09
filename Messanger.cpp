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

	SOCKET my_socket = socket(AF_INET, SOCK_STREAM, 0);

	if (my_socket == INVALID_SOCKET)
	{
		cerr << "Error::" << WSAGetLastError() << endl;
		closesocket(my_socket);
		WSACleanup();
		return 1;
	}
	else
	{
		cerr << "Server socket initialization is OK" << endl;
	}

}