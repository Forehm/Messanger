#include "server.h"
#include <mutex>


void Server::SaveMessagesHistory(const std::pair<int, int>& users)
{
	if (users_by_ids_.count(users.first) && users_by_ids_.count(users.second))
	{
		std::string path = users_by_ids_[users.first]->profile_name + " , " + users_by_ids_[users.second]->profile_name;
		std::ofstream file;
		file.open(path);
		for (const auto& message : messages_storage_[{users.first, users.second}])
		{
			file << message << std::endl;
		}
		file.close();
	}
}

void Server::AddUser(const std::string& login, const std::string& password, const std::string& profile_name, SOCKET connection)
{
	int user_id = ++id;
	all_users_.push_back({ user_id, login, password, profile_name });
	sockets_by_users_[all_users_.back()] = connection;
	all_logins_.insert(login);
	users_by_ids_.insert({ user_id, &all_users_.back() });

	std::string users_path_ = "users.txt";
	std::ofstream users_file_(users_path_, std::ios_base::app);

	users_file_ << profile_name << " - " << user_id << std::endl;
	LogIn(login, password, connection);
}

void Server::AddMessage(const int sender_id, const int receiver_id, const std::string& message)
{
	std::pair ids = GetIdsFromUsersInRightOrder(sender_id, receiver_id);
	messages_storage_[{ids.first, ids.second}].push_back(message);

	std::string sender_name = users_by_ids_[sender_id]->profile_name;

	std::string path = "messages " + std::to_string(ids.first) + " & " + std::to_string(ids.second) + ".txt";
	std::ofstream file(path, std::ios_base::app);
	file << sender_name << ": " << message << std::endl;
}

std::pair<int, int> Server::GetIdsFromUsersInRightOrder(const int sender_id, const int receiver_id) const
{
	int first_id = sender_id;
	int second_id = receiver_id;

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

void Server::CommitQueryWork(const std::vector<std::string>& query_words, SOCKET connection)
{
	if (query_words.empty()) { return; }
	if (query_words[0] == "AddUser")
	{
		AddUser(query_words[1], query_words[2], query_words[3], connection);
	}
	if (query_words[0] == "SendMSG")
	{
		SendMessageFromTo(query_words);
	}
	if (query_words[0] == "DelMSG")
	{
		DeleteMessageHistory(stoi(query_words[1]), stoi(query_words[2]));
	}
	if (query_words[0] == "LogIn")
	{
		LogIn(query_words[1], query_words[2], connection);
	}
	if (query_words[0] == "Block")
	{
		BlockUser(std::stoi(query_words[1]), std::stoi(query_words[2]), connection);
	}
	if (query_words[0] == "Unblock")
	{
		UnblockUser(std::stoi(query_words[1]), std::stoi(query_words[2]), connection);
	}
	if (query_words[0] == "AddFriend")
	{
		AddFriend(std::stoi(query_words[1]), std::stoi(query_words[2]), connection);
	}
	return;
}

void Server::AddConnection(SOCKET connection)
{
	connections_.push_back(connection);
}

void Server::LogIn(const std::string& login, const std::string& password, SOCKET connection)
{
	std::string query = "IdErrorRespond~-1~";
	for (const User& user : all_users_)
	{
		if (user.login == login && user.password == password)
		{
			sockets_by_users_[user] = connection;
			query = "UserDataRespond~" + std::to_string(user.id) + '~' + user.profile_name + '~';
			break;
		}
	}
	
	SendCommandToConnection(query, connection);
}

void Server::SendMessageFromTo(const std::vector<std::string>& query)
{
	Message m({ query.begin() + 1, query.end() });
	
	if (m.GetSenderId() == m.GetReceiverId())
	{
		return;
	}
	for (const auto& [user, user_address] : sockets_by_users_)
	{
		if (user.id == m.GetReceiverId())
		{
			if (users_black_lists_[user.id].count(m.GetSenderId()))
			{
				return;
			}
			std::string msg = m.Serialize();
			int msg_size = msg.size();
			Packet packettype = P_Message;

			send(user_address, (char*)&packettype, sizeof(Packet), NULL);
			send(user_address, (char*)&msg_size, sizeof(int), NULL);
			send(user_address, msg.c_str(), msg_size, NULL);
			AddMessage(m.GetSenderId(), m.GetReceiverId(), m.GetMessageText());
			return;
		}
	}
	return;
}

void Server::BlockUser(const int id_sender, const int other_id, SOCKET connection)
{
	auto it_user = std::find_if(all_users_.begin(), all_users_.end(), [id_sender](const User& user)
		{
			return user.id == id_sender;
		});
	auto it_to_block = std::find_if(all_users_.begin(), all_users_.end(), [other_id](const User& user)
		{
			return user.id == other_id;
		});

	if (it_to_block == all_users_.end() || it_user == all_users_.end())
	{
		return;
	}

	AddUserToUsersBlackList(it_user->id, it_to_block->id);
	it_user->black_list.insert({ it_to_block->id, it_to_block->profile_name });
	std::string query = "BlockRespond~" + it_to_block->profile_name + '~' + std::to_string(it_to_block->id) + '~';
	SendCommandToConnection(query, connection);	
}

void Server::AddUserToUsersBlackList(const int where, const int other_id)
{
	users_black_lists_[where].insert(other_id);
}

void Server::UnblockUser(const int where, const int other_id, SOCKET connection)
{
	if (!users_black_lists_.count(where))
	{
		return;
	}
	if (!users_black_lists_.at(where).count(other_id))
	{
		return;
	}
	users_black_lists_.at(where).erase(other_id);

	std::string query = "UnblockRespond~" + std::to_string(other_id) + '~';
	SendCommandToConnection(query, connection);
}

void Server::AddFriend(const int where, const int other_id, SOCKET connection)
{
	auto it_user = std::find_if(all_users_.begin(), all_users_.end(), [where](const User& u) {
		return u.id == where;
		});
	auto it_friend = std::find_if(all_users_.begin(), all_users_.end(), [other_id](const User& u) {
		return u.id == other_id;
		});

	if (it_user != all_users_.end() && it_friend != all_users_.end())
	{
		it_user->friends.insert(other_id);

		std::string query = "AddFriendRespond~" + std::to_string(other_id) + '~' + it_friend->profile_name + '~';
		SendCommandToConnection(query, connection);
	}	
}

void Server::SendCommandToConnection(const std::string& command, SOCKET connection) const
{
	int msg_size = command.size();
	Packet packettype = P_CommandMessage;
	send(connection, (char*)&packettype, sizeof(Packet), NULL);
	send(connection, (char*)&msg_size, sizeof(int), NULL);
	send(connection, command.c_str(), msg_size, NULL);
}


bool User::IsUserInBlackList(const int id) const
{
	return black_list.count(id);
}

bool User::operator!=(const User& another) const
{
	return ((this->id != another.id) && (this->login != another.login) && (this->password != another.password)
		&& (this->profile_name != another.profile_name));
}

bool User::operator<(const User& another) const
{
	return this->id < another.id;
}



int Server::id = 0;