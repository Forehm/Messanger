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

using namespace std;



vector<string> ParseQueryIntoWords(const string& query)
{
	vector<string> query_words;
	if (!query.empty())
	{
		string word = "";
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

struct User
{
	int id = -1;
	string login = "";
	string password = "";
	string profile_name = "";
	set<int> conversation_with;

	bool operator != (const User& another) const
	{
		return ((this->id != another.id) && (this->login != another.login) && (this->password != another.password)
			&& (this->profile_name != another.profile_name));
	}
};



class Server
{
public:

	void SignUp();

	void SignIn(const string& login, const string& password, SOCKET& connection);

	void DeleteMessageHistory(const int user1_id, const int user2_id);

	void CommitQueryWork(const vector<string>& query_words, SOCKET& connection);

private:

	static int id_;
	deque<User> all_users_;
	map<pair<int, int>, deque<string>> messages_storage_;
	set<string>all_logins_;
	unordered_map<int, const User*> users_by_ids_;
	void SaveMessagesHistory(const std::pair<int, int>& users);

	void AddUser(const string& login, const string& password, const string& profile_name);

	bool is_password_appropriate(const string& password) const;

	void AddMessage(const int sender_id, const int receiver_id, const string& message);

	pair<int, int> GetIdsFromUsersinRightOrder(const int sender_id, const int receiver_id) const;



	friend void TestAddUser();
	friend void TestAddingMessagesToMessageshistoryByID();
	//	friend void TestSigningIn();
	friend void TestErasingMessagesHistory();
	friend void TestOfGettingIdsOfUsersInTheRightOrder();
	friend void TestCommitQueryWork();
};

int Server::id_ = 0;



void Server::SignUp()
{
	cout << "Print your login" << endl;
	string login;
	cin >> login;
	cout << "Print your password" << endl;
	string password;
	bool flag = false;

	while (flag == false)
	{
		cout << "the password should contain at least 8 characters" << endl;
		cin >> password;
		flag = is_password_appropriate(password);
	}
	string profile_name;
	cin >> profile_name;


	AddUser(login, password, profile_name);
}

void Server::SignIn(const string& login, const string& password, SOCKET& connection)
{
	string error_message = "no user with such login or password";
	for (User& user : all_users_)
	{
		if (user.login == login && user.password == password)
		{
			string id_as_string = to_string(user.id);
			send(connection, (char*)&id_as_string, sizeof(id_as_string), NULL);
			return;
		}
	}
	send(connection, (char*)&error_message, sizeof(error_message), NULL);
}

inline void Server::SaveMessagesHistory(const std::pair<int, int>& users)
{
	if (users_by_ids_.count(users.first) && users_by_ids_.count(users.second))
	{
		std::string path = users_by_ids_[users.first]->profile_name + " , " + users_by_ids_[users.second]->profile_name;
		std::fstream file;
		file.open(path);
		for (const auto& message : messages_storage_[{users.first, users.second}])
		{
			file << message << endl;;
		}
		file.close();
	}
	 
}

void Server::AddUser(const string& login, const string& password, const string& profile_name)
{
	all_users_.push_back({ ++id_, login, password, profile_name });
	all_logins_.insert(login);
	users_by_ids_.insert({ id_, &all_users_.back() });
}

bool Server::is_password_appropriate(const string& password) const
{
	return password.size() >= 8 ? true : false;
}

void Server::AddMessage(const int sender_id, const int receiver_id, const string& message)
{
	messages_storage_[GetIdsFromUsersinRightOrder(sender_id, receiver_id)].push_back(message);
}

pair<int, int> Server::GetIdsFromUsersinRightOrder(const int sender_id, const int receiver_id) const
{
	int first_id = -1, second_id = -1;
	first_id = sender_id;
	second_id = receiver_id;

	if (first_id > second_id)
	{
		swap(first_id, second_id);
	}
	return { first_id, second_id };
}

void Server::DeleteMessageHistory(const int user1_id, const int user2_id)
{
	pair<int, int> pair_of_ids = GetIdsFromUsersinRightOrder(user1_id, user2_id);
	map<pair<int, int>, deque<string>>::iterator messages_to_erase = messages_storage_.find(pair_of_ids);

	if (messages_to_erase != messages_storage_.end())
	{
		SaveMessagesHistory(pair_of_ids);
		messages_storage_.erase(messages_to_erase);
	}
	
}

void Server::CommitQueryWork(const vector<string>& query_words, SOCKET& connection)
{
	if (query_words.empty()) { return; }
	if (query_words[0] == "AddUser")
	{
		AddUser(query_words[1], query_words[2], query_words[3]);
	}
	if (query_words[0] == "SendMSG")
	{
		AddMessage(stoi(query_words[1]), stoi(query_words[2]), query_words[3]);
	}
	if (query_words[0] == "DelMSG")
	{
		DeleteMessageHistory(stoi(query_words[1]), stoi(query_words[2]));
	}
	if (query_words[0] == "SignIn")
	{
		SignIn(query_words[1], query_words[2], connection);
	}
	return; /////temporary
}
