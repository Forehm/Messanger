#pragma once
#include <iostream>
#include <string>

using namespace std;

template<typename Function>
void TestingFunction(Function func, const string& func_name, const int& line)
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

#define ASSERT(real_argument, expected_argument) TestingFunction(real_argument, expected_argument, __FILE__, __FUNCTION__, __LINE__)

#define RUN_TEST(function)TestStartingFunction(function, (#function), __LINE__)
bool TestAddUser()
{


}





void TestServer()
{
	
}
