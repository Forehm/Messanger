#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <vector>
#include <string>
#pragma warning(disable: 4996)
#define _WINSOCK_DEPRECATED_NO_WARNINGS



std::vector<SOCKET>Connections;

int Counter = 0;

enum Packet {
	P_ChatMessage,
	P_Test
};

bool ProcessPacket(int index, Packet packet_type) {
	switch (packet_type) {
	case P_ChatMessage:
	{
		int msg_size{};

		recv(Connections[index], (char*)&msg_size, sizeof(int), NULL);

		char* msg = new char[msg_size + 1];
		msg[msg_size] = '\0';

		recv(Connections[index], msg, msg_size, NULL);

		std::string a = msg;
		if (a == "exit/")
		{
			closesocket(Connections[index]);
			Connections.erase(Connections.begin() + index);
			--Counter;
			return false;
		}

		for (SOCKET connection : Connections)
		{

			if (connection == Connections[index])
			{
				continue;
			}

			Packet msg_type = P_ChatMessage;
			send(connection, (char*)&msg_type, sizeof(Packet), NULL);
			send(connection, (char*)&msg_size, sizeof(int), NULL);
			send(connection, msg, msg_size, NULL);
		}
		delete[] msg;
		break;
	}
	default:
		std::cout << "Unrecognized packet: " << packet_type << std::endl;
		break;
	}

	return true;
}

void ClientHandler(int index) {
	Packet packet_type{};
	while (true) {
		recv(Connections[index], (char*)&packet_type, sizeof(Packet), NULL);

		if (!ProcessPacket(index, packet_type)) {
			break;
		}
	}
	closesocket(Connections[index]);

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
	address.sin_addr.s_addr = inet_addr("192.168.1.198");
	address.sin_port = htons(1111);
	address.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&address, sizeof(address));
	listen(sListen, SOMAXCONN);

	SOCKET newConnection;
	for (int i = 0; i < 100; i++) {
		newConnection = accept(sListen, (SOCKADDR*)&address, &size_of_address);

		if (newConnection == 0)
		{
			std::cout << "Error #2\n";
		}
		else
		{
			Connections.push_back(newConnection);
			Counter++;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, (LPVOID)(i), NULL, NULL);

			Packet test_packet = P_Test;
			send(newConnection, (char*)&test_packet, sizeof(Packet), NULL);
		}
	}


	system("pause");
	return 0;
}