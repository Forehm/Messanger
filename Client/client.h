#pragma once
#include <string>
#include <set>
#include <WinSock2.h>
#include <unordered_map>
#include <deque>
#include <ostream>
#include <map>
#include "message.h"

class Client
{
public:
	
	void SetName(const std::string& name);

	void SetLogin(const std::string& login);

	void SetPassword(const std::string& password);

	void SetId(const int id);

	void SetAddress(SOCKET address);

	void AddFriend(const int friend_id);

	void AddPersonToBlackList(const std::string& name, const int friend_id);

	void UnblockUser(const int user_id);

	void AddMessage(const int interlocutor_id, std::string message);

	void ClearMessagesHistory(const int id);

	int GetId() const;

	void GetMessagesHistory(std::ostream& out, const int interlocutor_id) const;

	std::string GetName() const;
	
	size_t GetFriendsCount() const;

	size_t GetBlackListSize() const;

	void GetBlockedUsers(std::ostream& out) const;

	Message MakeMessage(const int receicer_id, const std::string& message_text);

private:
	std::string name_;
	std::string login_;
	std::string password_;
	int id_ = -1;
	SOCKET address_;
	std::set<int> dialogues_with_;
	std::set<int> friends_;
	std::map<std::string, int> black_list_;
	std::unordered_map<int, std::deque<std::string>> messages_;
};