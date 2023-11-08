#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <thread>
#include <iostream>
#include <string>
#include "cryptography.h"
#include "client.h"
#include "CommandParsing.h"
#include "message.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma warning(disable: 4996)


SOCKET Connection; ///to delete
Client client;

enum Packet
{
	P_Test,
	P_CommandMessage,
	P_Message
};


bool ProcessPacket(Packet packettype)
{
	
	switch (packettype)
	{
	case P_Test:
	{
		std::cout << "Test packet.\n";
		break;
	}
	case P_CommandMessage:
	{
		int msg_size;
		recv(Connection, (char*)&msg_size, sizeof(int), NULL);
		char* msg = new char[msg_size + 1];
		msg[msg_size] = '\0';
		recv(Connection, msg, msg_size, NULL);
		std::vector<std::string> command = ParseServerCommand(msg);
		if (command[0] == "IdErrorRespond")
		{
			client.SetId(std::stoi(command[1]));
		}
		if (command[0] == "UserDataRespond")
		{
			client.SetId(std::stoi(command[1]));
			client.SetName(command[2]);
		}
		if (command[0] == "BlockRespond")
		{
			client.AddPersonToBlackList(command[1], std::stoi(command[2]));
		}
		if (command[0] == "UnblockRespond")
		{
			client.UnblockUser(std::stoi(command[1]));
		}
		delete[] msg;
		break;
	}
	case P_Message:
	{
		int msg_size;
		recv(Connection, (char*)&msg_size, sizeof(int), NULL);
		char* msg = new char[msg_size + 1];
		msg[msg_size] = '\0';
		recv(Connection, msg, msg_size, NULL);

		Message m(ParseServerCommand(msg));
		client.AddMessage(m.GetSenderId(), {m.GetSenderName() + ": " + m.GetMessageText() + "      " + m.GetTimeOfSending()});

		delete[] msg;
		break;
	}
	default:
	{
		std::cout << "Unrecognized packet: " << packettype << std::endl;
		break;
	}
	}
	return true;
}

void ClientHandler(Client& client) {
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
	std::string key = "cat";
	cryptography::GivenerEncrypter encrypter(key);
	
	

	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("192.168.50.126");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server.\n";
		return 1;
	}
	std::cout << "Connected!\n";

	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, NULL, NULL, NULL);

	

	while (true)
	{
		std::string login;
		std::string password;
		std::string name;
		int option = 0;
		std::cout << "Add user_____________1" << std::endl;
		std::cout << "Send message_________2" << std::endl;
		std::cout << "Delete messages______3" << std::endl;
		std::cout << "Log in_______________4" << std::endl;
		std::cout << "Get id_______________5" << std::endl;
		std::cout << "Add to black list____6" << std::endl;
		std::cout << "Print black list_____7" << std::endl;
		std::cout << "Print name___________8" << std::endl;
		std::cout << "Unblock user_________9" << std::endl;
		std::cin >> option;

		switch (option)
		{
		case 1:
		{
			{
				std::cout << "Print your login" << std::endl;
				while (!cryptography::HasMinLength(login))
				{
					std::cin >> login;
				}
			
				std::cout << "Print your password" << std::endl;
				while (!cryptography::HasMinLength(password))
				{
					std::cin >> password;
				}
				password = cryptography::hash_password(password);
				std::cout << "Print your name" << std::endl;
				std::cin >> name;
				std::string query = "AddUser~" + login + '~' + password + '~' + name + '~';
				int msg_size = query.size();
				Packet packettype = P_CommandMessage;
				send(Connection, (char*)&packettype, sizeof(Packet), NULL);
				send(Connection, (char*)&msg_size, sizeof(int), NULL);
				send(Connection, query.c_str(), msg_size, NULL);
				Sleep(10);
				break;
			}
		}
		case 2:
		{
			if (client.GetId() <= 0)
			{
				std::cout << "Sorry, you cannot send messages" << std::endl;
				break;
			}
			std::cout << "Who would you like to send your message to?" << std::endl;
			int receiver;
			std::cin >> receiver;

			
			std::string message;

			while (message != "~exit")
			{
				
				client.GetMessagesHistory(std::cout, receiver);

				std::cin >> message;
				if (message == "~exit")
				{
					break;
				}
				Message m = client.MakeMessage(receiver, message);
				std::string query = "SendMSG~" + m.Serialize();
				client.AddMessage(receiver, { m.GetSenderName() + ": " + m.GetMessageText() + "     " + m.GetTimeOfSending() });
				int msg_size = query.size();
				Packet packettype = P_CommandMessage;
				send(Connection, (char*)&packettype, sizeof(Packet), NULL);
				send(Connection, (char*)&msg_size, sizeof(int), NULL);
				send(Connection, query.c_str(), msg_size, NULL);
				Sleep(10);
				
			}
			break;
		}
		case 3:
		{
			std::cout << "Print id" << std::endl;
			int id_to_erase;
			std::cin >> id_to_erase;

			client.ClearMessagesHistory(id_to_erase);

			std::string query = "DelMSG~" + std::to_string(client.GetId()) + '~' + std::to_string(id_to_erase) + '~';
			int msg_size = query.size();
			Packet packettype = P_CommandMessage;
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
			while (!cryptography::HasMinLength(login))
			{
				std::cin >> login;
			}
			std::cout << "Print your password" << std::endl;
			while (!cryptography::HasMinLength(password))
			{
				std::cin >> password;
			}
			password = cryptography::hash_password(password);
			std::string query = "LogIn~" + login + '~' + password + '~';
			int msg_size = query.size();
			Packet packettype = P_CommandMessage;
			send(Connection, (char*)&packettype, sizeof(Packet), NULL);
			send(Connection, (char*)&msg_size, sizeof(int), NULL);
			send(Connection, query.c_str(), msg_size, NULL);
			Sleep(10);
			
			break;
		}
		case 5:
		{
			std::cout << "Your id = " << client.GetId() << std::endl;
			break;
		}
		case 6:
		{
			std::cout << "Print id" << std::endl;
			std::string receiver;
			std::cin >> receiver;
			std::string query = "Block~" + std::to_string(client.GetId()) + '~' + receiver + '~';
			int msg_size = query.size();
			Packet packettype = P_CommandMessage;
			send(Connection, (char*)&packettype, sizeof(Packet), NULL);
			send(Connection, (char*)&msg_size, sizeof(int), NULL);
			send(Connection, query.c_str(), msg_size, NULL);
			Sleep(10);
			break;
		}
		case 7:
		{
			std::cout << "Your black list:" << std::endl;
			client.GetBlockedUsers(std::cout);
			std::cout << "----------------" << std::endl;
			break;
		}
		case 8:
		{
			std::cout << "Your name is " << client.GetName() << std::endl;
			break;
		}
		case 9:
		{
			std::cout << "Print id" << std::endl;
			int id;
			std::cin >> id;
			client.UnblockUser(id);
		}
		}
		
	}

	system("pause");
	return 0;
}