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

#define ASSERT(real_argument, expected_argument) TestingFunction(real_argument, expected_argument, __FILE__, __FUNCTION__, __LINE__)

bool TestAddUser()
{


}





void TestServer()
{
	
}
