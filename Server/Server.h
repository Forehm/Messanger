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



class Server
{
public:

	void SignUp();

	User& SignIn(const string& login, const string& password);


private:

	static int id;
	deque<User> all_users_;
	map<pair<int, int>, deque<string>> messages_storage_;
	set<string>all_logins_;

	void AddUser(const string& login, const string& password, const string& profile_name);

	bool is_password_appropriate(const string& password) const;

	void AddMessage(const User& sender, const User& receiver, const string& message);





	friend void TestAddUser();
	friend void TestAddingMessagesToMessageshistoryByID();
	friend void TestSigningIn();
};

int Server::id = 0;



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

User& Server::SignIn(const string& login, const string& password)
{
	for (User& user : all_users_)
	{
		if (user.login == login && user.password == password)
		{
			return user;
		}
	}
}

void Server::AddUser(const string& login, const string& password, const string& profile_name)
{
	all_users_.push_back({ ++id, login, password, profile_name });
	all_logins_.insert(login);
}

bool Server::is_password_appropriate(const string& password) const
{
	return password.size() >= 8 ? true : false;
}

void Server::AddMessage(const User& sender, const User& receiver, const string& message)
{
	int first_id = -1, second_id = -1;
	first_id = sender.id;
	second_id = receiver.id;

	if (first_id > second_id)
	{
		swap(first_id, second_id);
	}

	messages_storage_[{first_id, second_id}].push_back(message);

}
