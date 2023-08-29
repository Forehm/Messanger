#pragma once
#include <string>
#include <set>
#include <WinSock2.h>

class Client
{
public:
	Client(const std::string& login, const std::string& password) : login_(login), password_(password)
	{
	}

private:
	std::string name_;
	std::string login_;
	std::string password_;
	int id_ = -1;
	SOCKET address_;
	std::set<int> dialogues_with_;
	std::set<int> friends_;
	std::set<int> black_list_;
};