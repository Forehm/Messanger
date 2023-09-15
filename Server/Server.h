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
#include <map>
#include "message.h"





struct User
{
	int id = -1;
	std::string login = "";
	std::string password = "";
	std::string profile_name = "";
	std::set<int> conversation_with;
	std::set<int> friends;
	std::map<int, std::string> black_list;

	bool IsUserInBlackList(const int id) const;

	bool operator != (const User& another) const;

	bool operator < (const User& another) const;
};

enum Packet {

	P_Test,
	P_CommandMessage,
	P_Message
};

class Server
{
public:

	void CommitQueryWork(const std::vector<std::string>& query_words, SOCKET connection);

	void AddConnection(SOCKET connection);

	void LogIn(const std::string& login, const std::string& password, SOCKET connection);
	
	void SendMessageFromTo(const std::vector<std::string>& query);

	void BlockUser(const int id_sender, const int other_id, SOCKET connection);

	void AddUserToUsersBlackList(const int where, const int other_id);

	void UnblockUser(const int where, const int other_id, SOCKET connection);

	void AddFriend(const int where, const int other_id, SOCKET connection);

	void SendCommandToConnection(const std::string& command, SOCKET connection) const;

private:

	static int id;
	std::deque<SOCKET>connections_;
	std::deque<User> all_users_;
	std::map<User, SOCKET> sockets_by_users_;
	std::map<std::pair<int, int>, std::deque<std::string>> messages_storage_;
	std::set<std::string>all_logins_;
	std::unordered_map<int, const User*> users_by_ids_;
	std::unordered_map<int, std::set<int>> users_black_lists_;

	void DeleteMessageHistory(const int user1_id, const int user2_id);

	void SaveMessagesHistory(const std::pair<int, int>& users);

	void AddUser(const std::string& login, const std::string& password, const std::string& profile_name, SOCKET connection);

	void AddMessage(const int sender_id, const int receiver_id, const std::string& message);

	std::pair<int, int> GetIdsFromUsersInRightOrder(const int sender_id, const int receiver_id) const;

};


