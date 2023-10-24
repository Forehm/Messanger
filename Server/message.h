#pragma once
#include <string>
#include <ctime>
#include <chrono>
#include <time.h>
#include <vector>

const int DATE_COUNTDOWN_YEAR = 1900;

class Message
{
public:
	Message(const int sender_id, const int receiver_id, const std::string& sender_name, const std::string& message);

	Message(const std::vector<std::string>& parts);

	std::string Serialize() const;

	std::string GetMessageText() const;

	int GetSenderId() const;

	std::string GetSenderName() const;

	int GetReceiverId() const;

	std::string GetDateOfSending() const;

	std::string GetTimeOfSending() const;

private:
	void Deserialize(const std::vector<std::string>& parts);

	std::string message_;
	int sender_id_;
	std::string sender_name_;
	int receiver_id_;
	std::string date_of_sending_;
	std::string time_of_sending_;
};








