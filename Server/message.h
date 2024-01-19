#pragma once
#include <string>
#include <ctime>
#include <chrono>
#include <time.h>
#include <vector>
#include "message_data.pb.h"

const int DATE_COUNTDOWN_YEAR = 1900;

struct Message
{

	std::string GetMessageText() const;

	int GetSenderId() const;

	std::string GetSenderName() const;

	int GetReceiverId() const;

	std::string GetDateOfSending() const;

	std::string GetTimeOfSending() const;

	proto::MessageData message_data;
};








