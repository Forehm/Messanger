#include "cryptography.h"

bool cryptography::PasswordHash::operator==(const PasswordHash& other_hash) const
{
	return password_content_hash == other_hash.password_content_hash &&
		password_length_hash == other_hash.password_length_hash &&
		password_summary_hash == other_hash.password_summary_hash;
}

cryptography::PasswordHash cryptography::HashPassword(const std::string& password)
{
	cryptography::PasswordHash final_hash{};
	const char* password_as_array = password.c_str();
	const size_t size = password.size();
	for (int i = 0; i < size; ++i)
	{
		final_hash.password_content_hash += static_cast<uint64_t>(password_as_array[i]);
		final_hash.password_length_hash += static_cast<uint64_t>(password_as_array[i]);
		final_hash.password_summary_hash += final_hash.password_content_hash * final_hash.password_length_hash;
	}
	for (int i = 0; i < size; ++i)
	{
		final_hash.password_content_hash *= static_cast<uint64_t>(password_as_array[i]) * static_cast<uint64_t>(password_as_array[i]);
	}
	final_hash.password_content_hash *= 64;
	for (int i = 0; i < size; ++i)
	{
		final_hash.password_length_hash *= std::pow((uint64_t)password_as_array[i], size);
	}
	final_hash.password_summary_hash *= (final_hash.password_content_hash + final_hash.password_length_hash * size);
	return final_hash;
}

bool cryptography::is_password_appropriate(const std::string& password)
{
	return password.size() >= 8 ? true : false;
}

void cryptography::GivenerEncrypter::FillSquare(std::string alphabet_copy)
{
	square_.push_back(alphabet_copy);

	char last_symbol = alphabet_copy[alphabet_copy.size() - 1];

	while (alphabet_copy[0] != last_symbol)
	{
		char symbol_to_shift = alphabet_copy[0];
		auto it = alphabet_copy.begin();
		alphabet_copy.erase(it);
		alphabet_copy.push_back(symbol_to_shift);
		square_.push_back(alphabet_copy);
	}
}

cryptography::GivenerEncrypter::GivenerEncrypter(const std::string& key) : key_(key)
{
}

cryptography::GivenerEncrypter::GivenerEncrypter(const std::string& alphabet, const std::string& key) : key_(key), alphabet_(alphabet)
{
	FillSquare(alphabet);
}

void cryptography::GivenerEncrypter::SetKey(const std::string& key)
{
	key_ = key;
}

std::string cryptography::GivenerEncrypter::Encrypt(std::string& message)
{
	srand(time(NULL));

	for (char& c : message)
	{
		if (c == ' ')
		{
			c = '_';
		}
	}

	std::string returning_message = "";
	int first_index = 0;
	int second_index = 0;
	int index_of_key = 0;

	for (const char& c : message)
	{
		if (index_of_key == key_.size())
		{
			index_of_key = 0;
		}

		for (size_t i = 0; i < alphabet_.size(); ++i)
		{
			if (alphabet_[i] == c)
			{
				first_index = i;
			}
		}

		for (size_t i = 0; i < alphabet_.size(); ++i)
		{
			if (square_[0][i] == key_[index_of_key])
			{
				second_index = i;
			}
		}

		returning_message += square_[first_index][second_index];

		++index_of_key;
	}

	return returning_message;
}

std::string cryptography::GivenerEncrypter::Decrypt(std::string& message)
{
	std::string returning_message = "";
	int first_index = 0;
	int second_index = 0;
	int index_of_key = 0;

	for (const char& c : message)
	{
		if (index_of_key == key_.size())
		{
			index_of_key = 0;
		}


		for (size_t i = 0; i < alphabet_.size(); ++i)
		{
			if (alphabet_[i] == key_[index_of_key])
			{
				first_index = i;
				break;
			}

		}

		for (size_t i = 0; i < alphabet_.size(); ++i)
		{
			if (square_[i][first_index] == c)
			{
				second_index = i;
			}

		}

		returning_message += alphabet_[second_index];
		++index_of_key;
	}

	for (char& c : returning_message)
	{
		if (c == '_')
		{
			c = ' ';
		}
	}

	return returning_message;
}
