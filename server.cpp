#include <iostream>
#include <string>
#include <WinSock2.h>
#include <vector>
#include <algorithm>
#include <list>
#include <map>

using namespace std;


struct User
{
	int id;
	string login;
	string password;
};



class Server
{
public:


	void SignUp()
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
		
		AddUser(login, password);
	}

	



private:
	static int id;
	list<User> all_users_;
	map<int, list<string>> messages_history_;

	void AddUser(const string& login, const string& password)
	{
		all_users_.push_back({ ++id, login, password });
	}

	bool is_password_appropriate(const string& password) const
	{
		return password.size() >= 8 ? true : false;
	}

};

int Server::id = 0;


int main()
{
	Server server;

	server.SignUp();

}
