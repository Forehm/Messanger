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
	int id = -1;
	string login = "";
	string password = "";
	string profile_name = "";
	set<int> conversation_with;
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
		string profile_name;
		cin >> profile_name;
		
		AddUser(login, password, profile_name);
	}

	



private:
	static int id;
	list<User> all_users_;
	map<int, list<string>> messages_history_;

	void AddUser(const string& login, const string& password, const string& profile_name)
	{
		all_users_.push_back({ ++id, login, password, profile_name});
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
