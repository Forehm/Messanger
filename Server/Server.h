#pragma once
#include <iostream>
#include <string>
#include <WinSock2.h>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <set>
#include <unordered_map>
#include <fstream>




std::vector<std::string> ParseQueryIntoWords(const std::string& query);

struct User
{
	int id = -1;
	std::string login = "";
	std::string password = "";
	std::string profile_name = "";
	std::set<int> conversation_with;

	bool operator != (const User& another) const;
};



class Server
{
public:

	void CommitQueryWork(const std::vector<std::string>& query_words, SOCKET& connection);

	void AddConnection(SOCKET& connection);

	void SignIn(const std::string& login, const std::string& password, SOCKET& connection);
	
	void SendMessageFromTo(const int id_sender, const int id_receiver, const std::string& message);

private:

	static int id;
	std::deque<SOCKET>connections_;
	std::deque<User> all_users_;
	std::unordered_map<User, SOCKET> sockets_by_users_;
	std::map<std::pair<int, int>, std::deque<std::string>> messages_storage_;
	std::set<std::string>all_logins_;
	std::unordered_map<int, const User*> users_by_ids_;

	void DeleteMessageHistory(const int user1_id, const int user2_id);

	void SaveMessagesHistory(const std::pair<int, int>& users);

	void AddUser(const std::string& login, const std::string& password, const std::string& profile_name, SOCKET& connection);

	bool is_password_appropriate(const std::string& password) const;

	void AddMessage(const int sender_id, const int receiver_id, const std::string& message);

	std::pair<int, int> GetIdsFromUsersInRightOrder(const int sender_id, const int receiver_id) const;

};

int Server::id = 0;
