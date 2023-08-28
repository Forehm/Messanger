#include "server.h"
#include <mutex>


inline void Server::SaveMessagesHistory(const std::pair<int, int>& users)
{
	if (users_by_ids_.count(users.first) && users_by_ids_.count(users.second))
	{
		std::string path = users_by_ids_[users.first]->profile_name + " , " + users_by_ids_[users.second]->profile_name;
		std::fstream file;
		file.open(path);
		for (const auto& message : messages_storage_[{users.first, users.second}])
		{
			file << message << std::endl;
		}
		file.close();
	}
}

void Server::AddUser(const std::string& login, const std::string& password, const std::string& profile_name, SOCKET& connection)
{
	all_users_.push_back({ ++id, login, password, profile_name });
	sockets_by_users_[all_users_.back()] = connection;
	all_logins_.insert(login);
	users_by_ids_.insert({ id, &all_users_.back() });
}

bool Server::is_password_appropriate(const std::string& password) const
{
	return password.size() >= 8 ? true : false;
}

void Server::AddMessage(const int sender_id, const int receiver_id, const std::string& message)
{
	messages_storage_[GetIdsFromUsersInRightOrder(sender_id, receiver_id)].push_back(message);
}

std::pair<int, int> Server::GetIdsFromUsersInRightOrder(const int sender_id, const int receiver_id) const
{
	int first_id = -1, second_id = -1;
	first_id = sender_id;
	second_id = receiver_id;

	if (first_id > second_id)
	{
		std::swap(first_id, second_id);
	}
	return { first_id, second_id };
}

void Server::DeleteMessageHistory(const int user1_id, const int user2_id)
{
	std::pair<int, int> pair_of_ids = GetIdsFromUsersInRightOrder(user1_id, user2_id);
	std::map<std::pair<int, int>, std::deque<std::string>>::iterator messages_to_erase = messages_storage_.find(pair_of_ids);

	if (messages_to_erase != messages_storage_.end())
	{
		SaveMessagesHistory(pair_of_ids);
		messages_storage_.erase(messages_to_erase);
	}
}

inline void Server::CommitQueryWork(const std::vector<std::string>& query_words, SOCKET& connection)
{
	if (query_words.empty()) { return; }
	if (query_words[0] == "AddUser")
	{
		AddUser(query_words[1], query_words[2], query_words[3], connection);
	}
	if (query_words[0] == "SendMSG")
	{
		AddMessage(stoi(query_words[1]), stoi(query_words[2]), query_words[3]);
	}
	if (query_words[0] == "DelMSG")
	{
		DeleteMessageHistory(stoi(query_words[1]), stoi(query_words[2]));
	}
	return; /////temporary
}

void Server::AddConnection(SOCKET& connection)
{
	connections_.push_back(connection);
}

void Server::SignIn(const std::string& login, const std::string& password, SOCKET& connection)
{
	for (const User& user : all_users_)
	{
		if (user.login == login && user.password == password)
		{
			sockets_by_users_[user] = connection;
			std::string str_id = std::to_string(user.id);
			send(connection, str_id.c_str(), sizeof(str_id), NULL);
			return;
		}
	}
	std::string str_id = std::to_string(-1);
	send(connection, str_id.c_str(), sizeof(str_id), NULL);
}

void Server::SendMessageFromTo(const int id_sender, const int id_receiver, const std::string& message)
{
	AddMessage(id_sender, id_receiver, message);
	for (const auto& [user, user_address] : sockets_by_users_)
	{
		if (user.id == id_receiver)
		{
			send(user_address, message.c_str(), sizeof(message), NULL);
			return;
		}
	}
	return;
}


bool User::operator!=(const User& another) const
{
	return ((this->id != another.id) && (this->login != another.login) && (this->password != another.password)
		&& (this->profile_name != another.profile_name));
}

std::vector<std::string> ParseQueryIntoWords(const std::string& query)
{
	std::vector<std::string> query_words;
	if (!query.empty())
	{
		std::string word = "";
		for (const char& c : query)
		{
			if (c == '~')
			{
				query_words.push_back(word);
				word = "";
			}
			else
			{
				word += c;
			}
		}

	}
	return query_words;
}