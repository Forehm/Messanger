#pragma once
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>


namespace cryptography
{


	struct PasswordHash
	{
		uint64_t password_content_hash;
		uint64_t password_length_hash;
		uint64_t password_summary_hash;

		bool operator == (const PasswordHash& other_hash) const;
	};


	PasswordHash HashPassword(const std::string& password);


	class GivenerEncrypter
	{
	private:
		std::string alphabet_ = "qwertyuiopasdfghjklzxcvbnm_,.!():?-+=1234567890%*QWERTYUIOPASDFGHJKLZXCVBNM";
		std::string key_ = "";
		std::vector<std::string> square_;

		void FillSquare(std::string alphabet_copy);

	public: 

		GivenerEncrypter(const std::string& key);

		GivenerEncrypter(const std::string& alphabet, const std::string& key);

		void SetKey(const std::string& key);

		std::string Encrypt(std::string& message);

		std::string Decrypt(std::string& message);

	};


}