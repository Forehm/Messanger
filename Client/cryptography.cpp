#include "cryptography.h"



std::string cryptography::hash_password(const std::string& password)
{
	// Инициализация хэш-алгоритма
	uint32_t h0 = 0x67452301;
	uint32_t h1 = 0xEFCDAB89;
	uint32_t h2 = 0x98BADCFE;
	uint32_t h3 = 0x10325476;
	uint32_t h4 = 0xC3D2E1F0;

	// Пароль, представленный в байтах
	std::string message = password;

	// Добавление битов "1" в конец пароля
	message += '\x80';

	// Добавление нулевых битов, чтобы длина пароля была кратна 512 битам
	while ((message.length() * 8) % 512 != 448) {
		message += '\x00';
	}

	// Добавление длины сообщения в конец, представленное в битах
	uint64_t message_size_bits = password.length() * 8;
	std::stringstream ss;
	ss << std::hex << std::setfill('0') << std::setw(16) << message_size_bits;
	std::string message_size_hex = ss.str();
	for (int i = 0; i < 16; i += 2) {
		uint8_t byte = std::stoi(message_size_hex.substr(i, 2), nullptr, 16);
		message += byte;
	}

	// Вычисление хэш-значения блока сообщения
	for (size_t i = 0; i < message.length(); i += 64) {
		uint32_t w[80];
		uint32_t a = h0, b = h1, c = h2, d = h3, e = h4;

		for (int t = 0; t < 80; t++) {
			if (t < 16) {
				w[t] = message[i + t * 4 + 0] << 24 |
					message[i + t * 4 + 1] << 16 |
					message[i + t * 4 + 2] << 8 |
					message[i + t * 4 + 3];
			}
			else {
				w[t] = (((w[t - 3] ^ w[t - 8] ^ w[t - 14] ^ w[t - 16]) << 1) |
					((w[t - 3] ^ w[t - 8] ^ w[t - 14] ^ w[t - 16]) >> 31));
			}

			uint32_t f, k;
			if (t < 20) {
				f = (b & c) | ((~b) & d);
				k = 0x5A827999;
			}
			else if (t < 40) {
				f = b ^ c ^ d;
				k = 0x6ED9EBA1;
			}
			else if (t < 60) {
				f = (b & c) | (b & d) | (c & d);
				k = 0x8F1BBCDC;
			}
			else {
				f = b ^ c ^ d;
				k = 0xCA62C1D6;
			}

			uint32_t temp = (((a << 5) | (a >> 27)) + f + e + k + w[t]) & 0xFFFFFFFF;
			e = d;
			d = c;
			c = ((b << 30) | (b >> 2));
			b = a;
			a = temp;
		}

		h0 = (h0 + a) & 0xFFFFFFFF;
		h1 = (h1 + b) & 0xFFFFFFFF;
		h2 = (h2 + c) & 0xFFFFFFFF;
		h3 = (h3 + d) & 0xFFFFFFFF;
		h4 = (h4 + e) & 0xFFFFFFFF;
	}

	// Формирование и возврат хэш-значения в шестнадцатеричном виде
	std::stringstream result;
	result << std::hex << std::setfill('0') << std::setw(8) << h0
		<< std::setw(8) << h1 << std::setw(8) << h2
		<< std::setw(8) << h3 << std::setw(8) << h4;
	return result.str();
}

bool cryptography::HasMinLength(const std::string& password)
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

cryptography::GivenerEncrypter::GivenerEncrypter()
{
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
