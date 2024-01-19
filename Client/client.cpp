#include "client.h"

void Client::SetName(const std::string& name) 
{
	user_data_.set_name(name);
}

void Client::SetLogin(const std::string& login)
{
	user_data_.set_login(login);
}

void Client::SetPassword(const std::string& password)
{
	user_data_.set_password(password);
}

void Client::SetId(const int id)
{
	user_data_.set_id(id);
}

void Client::SetAddress(SOCKET address)
{
	address_ = address;
}

void Client::AddFriend(const int friend_id)
{
	user_data_.add_friend_list(friend_id);
}

void Client::AddPersonToBlackList(const std::string& name, const int friend_id)
{
	///black_list_.insert({ name, friend_id });
}

void Client::UnblockUser(const int user_id)
{
	//for (const auto& user : black_list_)
	//{
	//	if (user.second == user_id)
	//	{
	//		black_list_.erase(user.first);
	//		break;
	//	}
	//}
	return;
}

void Client::AddMessage(const int interlocutor_id, std::string message)
{	messages_[interlocutor_id].push_back(message);
}

void Client::ClearMessagesHistory(const int id)
{
	if (!messages_.count(id))
	{
		return;
	}
	messages_.at(id).clear();
}

int Client::GetId() const
{
	return user_data_.id();
}

void Client::GetMessagesHistory(std::ostream& out, const int interlocutor_id) const
{
	if (!messages_.count(interlocutor_id))
	{
		out << "------you have no messages------" << std::endl;
		return;
	}
	for (const auto& message : messages_.at(interlocutor_id))
	{
		out << message << std::endl;
	}
	return;
}

std::string Client::GetName() const
{
	return user_data_.name();
}

size_t Client::GetFriendsCount() const
{
	return user_data_.friend_list().size();
}

size_t Client::GetBlackListSize() const
{
	return user_data_.black_list().size();
}

void Client::GetBlockedUsers(std::ostream& out) const
{
	/*for (const auto& user : black_list_)
	{
		out << std::endl;
		out << "name: " << user.first << " id: " << user.second << std::endl;
	}*/
}

//Message Client::MakeMessage(const int receicer_id, const std::string& message_text)
//{
//	Message m(user_data_.id(), receicer_id, user_data_.name(), message_text);
//	return m;
//}
