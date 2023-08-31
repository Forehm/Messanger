#pragma once
#include <vector>
#include <string>




std::vector<std::string> ParseServerCommand(const std::string& command)
{
	std::vector<std::string> query_words;
	if (!command.empty())
	{
		std::string word = "";
		for (const char& c : command)
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

