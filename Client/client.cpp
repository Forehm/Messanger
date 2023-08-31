#include "client.h"

void Client::SetName(const std::string& name) 
{
	name_ = name;
}

void Client::SetLogin(const std::string& login)
{
	login_ = login;
}

void Client::SetPassword(const std::string& password)
{
	password_ = password;
}

void Client::SetId(const int id)
{
	id_ = id;
}

void Client::SetAddress(SOCKET address)
{
	address_ = address;
}

void Client::AddFriend(const int friend_id)
{
	friends_.insert(friend_id);
}

void Client::AddPersonToBlackList(const std::string& name, const int friend_id)
{
	black_list_.insert({ name, friend_id });
}

void Client::AddMessage(const int interlocutor_id, std::string message)
{
	messages_[interlocutor_id].push_back(message);
}

int Client::GetId() const
{
	return id_;
}

std::string Client::GetName() const
{
	return name_;
}

size_t Client::GetFriendsCount() const
{
	return friends_.size();
}

size_t Client::GetBlackListSize() const
{
	return black_list_.size();
}

void Client::GetBlockedUsers(std::ostream& out) const
{
	for (const auto& user : black_list_)
	{
		out << std::endl;
		out << "name: " << user.first << "id: " << user.second << std::endl;
	}
}
