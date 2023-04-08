#pragma once
#include <iostream>
#include <string>
#include "Server.h"
using namespace std;

template<typename Function>
void TestStartingFunction(Function func, const string& func_name, const int& line)
{
	func();
	cerr << func_name << '(' << line << ')' << " OK" << endl;

}

template<typename T, typename T2>
void TestingFunction(const T& real_arg, const T2& expected_arg, const string& file, const string& function,
	const int& line)
{
	if (real_arg != expected_arg)
	{
		cerr << "Error " << file << "__" << function << "__" << line << endl;
		abort();
	}
}

#define ASSERT_EQUAL(real_argument, expected_argument) TestingFunction(real_argument, expected_argument, __FILE__, __FUNCTION__, __LINE__)

#define RUN_TEST(function)TestStartingFunction(function, (#function), __LINE__)

void TestAddUser()
{
	Server server;
	server.AddUser("ctvh", "wsedrftgyhuji", "rtyy");
	ASSERT_EQUAL(server.all_users_.size(), 1);
	ASSERT_EQUAL(server.all_users_[0].id, 1);

}

void TestAddingMessagesToMessageshistoryByID()
{
	Server server;
	User a{ -1, "vb", "vygbkjaxs", "cvgbhn" };
	User b{ -1, "vbdsc", "v345jaxs", "cbnm,hn" };
	server.AddUser(a.login, a.password, a.profile_name);
	server.AddUser(b.login, b.password, b.profile_name);

	server.AddMessage(a, b, "Hello");
	server.AddMessage(b, a, "How are you?");

	ASSERT_EQUAL(server.messages_storage_.at({ a.id, b.id }).size(), 2);
}



void TestServer()
{
	RUN_TEST(TestAddUser);
	RUN_TEST(TestAddingMessagesToMessageshistoryByID);
}