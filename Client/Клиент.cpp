#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <string>
#include "cryptography.h"
#include "client.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma warning(disable: 4996)


SOCKET Connection;


enum Packet
{
	P_ChatMessage,
	P_Test
};


bool ProcessPacket(Packet packettype)
{
	switch (packettype)
	{
	case P_ChatMessage:
	{
		int msg_size;
		recv(Connection, (char*)&msg_size, sizeof(int), NULL);
		char* msg = new char[msg_size + 1];
		msg[msg_size] = '\0';
		recv(Connection, msg, msg_size, NULL);
		std::cout << msg << std::endl;
		delete[] msg;
		break;
	}
	case P_Test:
		std::cout << "Test packet.\n";
		break;
	default:
		std::cout << "Unrecognized packet: " << packettype << std::endl;
		break;
	}

	return true;
}

void ClientHandler() {
	Packet packettype;
	while (true) {
		recv(Connection, (char*)&packettype, sizeof(Packet), NULL);

		if (!ProcessPacket(packettype)) {
			break;
		}
	}
	closesocket(Connection);
}

int main() 
{
	Client client("forehm", "ds829265");
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("192.168.1.78");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server.\n";
		return 1;
	}
	std::cout << "Connected!\n";

	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, NULL, NULL, NULL);

	std::string msg1;
	//while (true) {
	//	std::getline(std::cin, msg1);
	//	int msg_size = msg1.size();
	//	Packet packettype = P_ChatMessage;
	//	send(Connection, (char*)&packettype, sizeof(Packet), NULL);
	//	send(Connection, (char*)&msg_size, sizeof(int), NULL);
	//	send(Connection, msg1.c_str(), msg_size, NULL);
	//	Sleep(10);
	//}
	cryptography::GivenerEncrypter encrypter("cat");
	std::string login;
	std::string password;
	std::string name;
	int id = -1;
	std::string message_from_server;
	while (true)
	{
		
		int option = 0;
		std::cout << "AddUser______________1" << std::endl;
		std::cout << "Send message_________2" << std::endl;
		std::cout << "Delete messages______3" << std::endl;
		std::cout << "LogIn________________4" << std::endl;
		std::cin >> option;

		switch (option)
		{
		case 1:
		{
			{
				std::cout << "Print your login" << std::endl;
				std::cin >> login;
			portal:
				std::cout << "Print your password" << std::endl;
				std::cin >> password;
				if (!cryptography::is_password_appropriate(password))
				{
					goto portal;
				}
				std::cout << "Print your name" << std::endl;
				std::cin >> name;
				std::string query = "AddUser~" + login + '~' + password + '~' + name + '~';
				int msg_size = query.size();
				Packet packettype = P_ChatMessage;
				send(Connection, (char*)&packettype, sizeof(Packet), NULL);
				send(Connection, (char*)&msg_size, sizeof(int), NULL);
				send(Connection, query.c_str(), msg_size, NULL);
				Sleep(10);
				break;
			}
		}
		case 2:
		{
			std::cout << "Who would you like to send your message to?" << std::endl;
			std::string receiver;
			std::cin >> receiver;
			std::cout << "Print a message" << std::endl;
			std::string message;
			std::cin >> message;
			std::string query = "SendMSG~" + std::to_string(id) + '~' + receiver + '~' + message + '~';
			int msg_size = query.size();
			Packet packettype = P_ChatMessage;
			send(Connection, (char*)&packettype, sizeof(Packet), NULL);
			send(Connection, (char*)&msg_size, sizeof(int), NULL);
			send(Connection, query.c_str(), msg_size, NULL);
			Sleep(10);
			break;
		}
		case 4:
		{
			std::cout << "Print your login" << std::endl;
			std::cin >> login;
			portal2:
			std::cout << "Print your password" << std::endl;
			std::cin >> password;
			if (!cryptography::is_password_appropriate(password))
			{
				goto portal2;
			}
			std::string query = "LogIn~" + login + '~' + password + '~';
			int query_size = query.size();
			Packet packettype = P_ChatMessage;
			send(Connection, (char*)&packettype, sizeof(Packet), NULL);
			send(Connection, (char*)&query_size, sizeof(int), NULL);
			send(Connection, query.c_str(), query_size, NULL);
			Sleep(10);
			int msg_size;
			recv(Connection, (char*)&msg_size, sizeof(int), NULL);
			char* msg = new char[msg_size + 1];
			msg[msg_size] = '\0';
			recv(Connection, msg, msg_size, NULL);
			std::string str_id(msg);
			id = stoi(str_id);
			break;
		}
		}

	}

	system("pause");
	return 0;
}