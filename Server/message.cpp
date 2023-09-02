#include "message.h"

Message::Message(const int sender_id, const int receiver_id, const std::string& sender_name, const std::string& message) :
    message_(message), sender_name_(sender_name), sender_id_(sender_id), receiver_id_(receiver_id)
{
    time_t seconds = time(NULL);
    tm current_time;
    localtime_s(&current_time, &seconds);


    current_time.tm_mday < 10 ? date_of_sending_ += '0' + std::to_string(current_time.tm_mday)
        : date_of_sending_ += std::to_string(current_time.tm_mday);
    date_of_sending_ += '.';

    current_time.tm_mon < 10 ? date_of_sending_ += '0' + std::to_string(current_time.tm_mon)
        : date_of_sending_ += std::to_string(current_time.tm_mon);
    date_of_sending_ += '.';

    date_of_sending_ += std::to_string(current_time.tm_year + DATE_COUNTDOWN_YEAR);

    current_time.tm_hour < 10 ? time_of_sending_ += '0' + std::to_string(current_time.tm_hour)
        : time_of_sending_ += std::to_string(current_time.tm_hour);
    time_of_sending_ += ':';

    current_time.tm_min < 10 ? time_of_sending_ += '0' + std::to_string(current_time.tm_min)
        : time_of_sending_ += std::to_string(current_time.tm_min);
}

Message::Message(const std::vector<std::string>& parts)
{
    Deserialize(parts);
}

std::string Message::Serialize() const
{
    std::string result;
    result += std::to_string(sender_id_) + '~';
    result += std::to_string(receiver_id_) + '~';
    result += sender_name_ + '~';
    result += message_ + '~';
    result += date_of_sending_ + '~';
    result += time_of_sending_ + '~';
    return result;
}

std::string Message::GetMessageText() const
{
    return message_;
}

int Message::GetSenderId() const
{
    return sender_id_;
}

std::string Message::GetSenderName() const
{
    return sender_name_;
}

int Message::GetReceiverId() const
{
    return receiver_id_;
}

std::string Message::GetDateOfSending() const
{
    return date_of_sending_;
}

std::string Message::GetTimeOfSending() const
{
    return time_of_sending_;
}

void Message::Deserialize(const std::vector<std::string>& parts)
{
    sender_id_ = std::stoi(parts[0]);
    receiver_id_ = std::stoi(parts[1]);
    sender_name_ = parts[2];
    message_ = parts[3];
    date_of_sending_ = parts[4];
    time_of_sending_ = parts[5];
}