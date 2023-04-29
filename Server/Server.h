#pragma once
#include <iostream>
#include <string>
#include <WinSock2.h>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <set>
#include "Tests.h"

using namespace std;



enum class Action
{
	SIGN_UP,
	LOG_IN,
	SEND_MSG,
	DELETE_MSG_HISTORY
};





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

class UsersManager
{
public:

	void SignUp();

	User& SignIn(const string& login, const string& password);

private:
	static int id;
	deque<User> all_users_;
	set<string>all_logins_;

	void AddUser(const string& login, const string& password, const string& profile_name);

	friend void TestAddUser();
	friend void TestSigningIn();
};

int UsersManager::id = 0;

class MessagesManager
{
public:

	void DeleteMessageHistory(const User& user1, const User& user2);

	void AddMessage(const User& sender, const User& receiver, const string& message);

private:

	map<pair<int, int>, deque<string>> messages_storage_;

	friend void TestAddingMessagesToMessageshistoryByID();
	friend void TestErasingMessagesHistory();
};

class MessangerToolsManager
{
public:

	bool is_password_appropriate(const string& password) const;

	static pair<int, int> GetIdsFromUsersinRightOrder(const User& user1, const User& user2);

private:

	friend void TestOfGettingIdsOfUsersInTheRightOrder();
};







void UsersManager::SignUp()
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

User& UsersManager::SignIn(const string& login, const string& password)
{
	for (User& user : all_users_)
	{
		if (user.login == login && user.password == password)
		{
			return user;
		}
	}
}

void UsersManager::AddUser(const string& login, const string& password, const string& profile_name)
{
	all_users_.push_back({ ++id, login, password, profile_name });
	all_logins_.insert(login);
}

bool MessangerToolsManager::is_password_appropriate(const string& password) const
{
	return password.size() >= 8 ? true : false;
}

void MessagesManager::AddMessage(const User& sender, const User& receiver, const string& message)
{
	messages_storage_[GetIdsFromUsersinRightOrder(sender, receiver)].push_back(message);
}

pair<int, int> MessangerToolsManager::GetIdsFromUsersinRightOrder(const User& user1, const User& user2)
{
	int first_id = -1, second_id = -1;
	first_id = user1.id;
	second_id = user2.id;

	if (first_id > second_id)
	{
		swap(first_id, second_id);
	}
	return { first_id, second_id };
}

void MessagesManager::DeleteMessageHistory(const User& user1, const User& user2)
{
	pair<int, int> pair_of_ids = MessangerToolsManager::GetIdsFromUsersinRightOrder(user1, user2);
	map<pair<int, int>, deque<string>>::iterator messages_to_erase = messages_storage_.find(pair_of_ids);
	messages_storage_.erase(messages_to_erase);
}