#pragma once
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include <iomanip>





namespace cryptography
{
   
	std::string hash_password(const std::string& password);

	bool HasMinLength(const std::string& password);

	class GivenerEncrypter
	{
	private:
		std::string alphabet_ = "qwertyuiopasdfghjklzxcvbnm_,.!():?-+=1234567890%*QWERTYUIOPASDFGHJKLZXCVBNM";
		std::string key_ = "";
		std::vector<std::string> square_;

		void FillSquare(std::string alphabet_copy);

	public: 
		GivenerEncrypter();

		GivenerEncrypter(const std::string& key);

		GivenerEncrypter(const std::string& alphabet, const std::string& key);

		void SetKey(const std::string& key);

		std::string Encrypt(std::string& message);

		std::string Decrypt(std::string& message);

	};


}
