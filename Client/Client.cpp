//#include "stdafx.h"
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <string>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma warning(disable: 4996)

SOCKET Connection;
int id; ///temporarily. just to test
enum Packet {
	P_ChatMessage,
	P_Test
};

struct PasswordHash
{
    uint64_t password_content_hash;
    uint64_t password_length_hash;
    uint64_t password_summary_hash;

    bool operator == (const PasswordHash& other_hash) const
    {
        return password_content_hash == other_hash.password_content_hash &&
            password_length_hash == other_hash.password_length_hash && 
         password_summary_hash == other_hash.password_summary_hash;
    }
};


PasswordHash HashPassword(const std::string& password)
{
    PasswordHash final_hash{};
    const char* password_as_array = password.c_str();
    const size_t size = password.size();
    for (int i = 0; i < size; ++i)
    {
        final_hash.password_content_hash += static_cast<uint64_t>(password_as_array[i]);
        final_hash.password_length_hash += static_cast<uint64_t>(password_as_array[i]);
        final_hash.password_summary_hash = final_hash.password_content_hash * final_hash.password_length_hash;
    }
    for (int i = 0; i < size; ++i)
    {
        final_hash.password_content_hash *= static_cast<uint64_t>(password_as_array[i]) * static_cast<uint64_t>(password_as_array[i]);
    }
    for (int i = 0; i < size; ++i)
    {
        final_hash.password_length_hash *= std::pow((uint64_t)password_as_array[i], size);
    }
    final_hash.password_summary_hash = final_hash.password_content_hash + final_hash.password_length_hash * (size);
    return final_hash;
}


bool ProcessPacket(Packet packettype) {
	switch (packettype) {
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

int main(int argc, char* argv[]) {
	//WSAStartup
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("192.168.50.121");
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
	std::string login;
	std::string password;
	std::string name;
	int id = 1;

	while (true)
	{
		int option = 0;
		std::cout << "LogIn________________1" << std::endl;
		std::cout << "Send message_________2" << std::endl;
		std::cout << "Delete messages______3" << std::endl;
		std::cin >> option;

		switch (option)
		{
		case 1:
		{
			std::cout << "Print your login" << std::endl;
			std::cin >> login;
			std::cout << "Print your password" << std::endl;
			std::cin >> password;
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
		case 2:
		{
			std::cout << "Who would you like to send your message to?" << std::endl;
			std::string receiver;
			std::cin >> receiver;
			std::cout << "Print a message" << std::endl;
			std::string message;
			std::cin >> message;
			std::string query = "SendMSG~" + id + '~' + receiver + '~' + message + '~';
			int msg_size = query.size();
			Packet packettype = P_ChatMessage;
			send(Connection, (char*)&packettype, sizeof(Packet), NULL);
			send(Connection, (char*)&msg_size, sizeof(int), NULL);
			send(Connection, query.c_str(), msg_size, NULL);
			Sleep(10);
			break;
		}
		}

	}

	system("pause");
	return 0;
}
