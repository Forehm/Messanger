#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "Server.h"
#pragma warning(disable: 4996)
#define _WINSOCK_DEPRECATED_NO_WARNINGS



Server server;

std::set<SOCKET>Connections;

int Counter = 0;

enum Packet {
	P_ChatMessage,
	P_Test
};

bool ProcessPacket(SOCKET conn, Packet packet_type) {
	switch (packet_type) {
	case P_ChatMessage:
	{
		int msg_size{};

		recv(conn, (char*)&msg_size, sizeof(int), NULL);

		char* received_msg = new char[msg_size + 1];
		received_msg[msg_size] = '\0';

		recv(conn, received_msg, msg_size, NULL);

		std::string msg_to_process = received_msg;
		if (msg_to_process == "exit/")
		{
			closesocket(conn);
			Connections.erase(conn);
			--Counter;
			return false;
		}

		server.CommitQueryWork(ParseQueryIntoWords(msg_to_process), conn);
		delete[] received_msg;
		break;
	}
	default:
		std::cout << "Unrecognized packet: " << packet_type << std::endl;
		break;
	}

	return true;
}

void ClientHandler(SOCKET conn) {
	Packet packet_type{};
	while (true) {
		recv(conn, (char*)&packet_type, sizeof(Packet), NULL);

		if (!ProcessPacket(conn, packet_type)) {
			break;
		}
	}
	closesocket(conn);

}

int main() {
	

	WSAData WSAData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &WSAData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN address{};
	int size_of_address = sizeof(address);
	address.sin_addr.s_addr = inet_addr("192.168.50.121");
	address.sin_port = htons(1111);
	address.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&address, sizeof(address));
	listen(sListen, SOMAXCONN);

	SOCKET newConnection;
	while (true)
	{
		newConnection = accept(sListen, (SOCKADDR*)&address, &size_of_address);

		cout << "all logins: " << server.all_logins_.size() << endl;
		cout << "all users: " << server.all_users_.size() << endl;
		cout << "messages storage: " << server.messages_storage_.size() << endl;

		

		if (newConnection == 0)
		{
			std::cout << "Error #2\n";
		}
		else
		{
			Connections.insert(newConnection);
			Counter++;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, (LPVOID)(newConnection), NULL, NULL);

			Packet test_packet = P_Test;
			send(newConnection, (char*)&test_packet, sizeof(Packet), NULL);
		}
	}


	system("pause");
	return 0;
}
