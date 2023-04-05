#pragma once
#include <iostream>
#include <string>

template<typename T, typename T1>
void TestingFunction(const T& first, const T1& second, const std::string& file,
	const std::string& function, const int& line)
{
	if (first != second)
	{
		cerr << "Error: " << file << ", " << function << ", " << line << ", " << first << " != " << second << endl;
	}
}

#define ASSERT(real_argument, expected_argument) TestingFunction(real_argument, expected_argument, __FILE__, __FUNCTION__, __LINE__)

bool TestAddUser()
{


}





void TestServer()
{
	
}
