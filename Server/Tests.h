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

	server.AddMessage(1, 2, "Hello");
	server.AddMessage(1, 2, "How are you?");

	ASSERT_EQUAL(server.messages_storage_.at({ 1, 2 }).size(), 2);
}

void TestSigningIn()
{
	Server server;
	User a{ -1, "vb", "vygbkjaxs", "cvgbhn" };
	server.AddUser(a.login, a.password, a.profile_name);

	User& user_a = server.all_users_[0];
	User& ref_b = server.SignIn("vb", "vygbkjaxs");

	ASSERT_EQUAL(user_a, ref_b);
}

void TestErasingMessagesHistory()
{
	Server server;

	server.AddMessage(1, 2, "Hello");
	server.AddMessage(1, 2, "How are you?");

	ASSERT_EQUAL(server.messages_storage_.at({ 1, 2 }).size(), 2);
	server.DeleteMessageHistory(2, 1);
	ASSERT_EQUAL(server.messages_storage_.count({ 1, 2 }), 0);
}

void TestOfGettingIdsOfUsersInTheRightOrder()
{
	Server server;

	pair<int, int> needed_unswer{ 1, 2 };
	pair<int, int> real_unswer = server.GetIdsFromUsersinRightOrder(2, 1);
	ASSERT_EQUAL(needed_unswer, real_unswer);
}

void TestCommitQueryWork()
{
	Server server;
	string needed_answer = "Hello, what's up?";
	server.CommitQueryWork(ParseQueryIntoWords("AddUser~__login__~__password__~__name__~"));
	ASSERT_EQUAL(server.all_users_.size(), 1);

	server.CommitQueryWork(ParseQueryIntoWords("SendMSG~1~2~Hello, what's up?~"));

	ASSERT_EQUAL(server.messages_storage_.count({ 1, 2 }), 1);

	server.CommitQueryWork(ParseQueryIntoWords("DelMSG~2~1~"));

	ASSERT_EQUAL(server.messages_storage_.count({ 1, 2 }), 0);
}


void TestServer()
{
	RUN_TEST(TestAddUser);
	RUN_TEST(TestAddingMessagesToMessageshistoryByID);
	RUN_TEST(TestSigningIn);
	RUN_TEST(TestErasingMessagesHistory);
	RUN_TEST(TestOfGettingIdsOfUsersInTheRightOrder);
	RUN_TEST(TestCommitQueryWork);
}