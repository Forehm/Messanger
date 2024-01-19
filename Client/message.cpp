#include "message.h"


std::string Message::GetMessageText() const
{
    return message_data.message();
}

int Message::GetSenderId() const
{
    return message_data.sender_id();
}

std::string Message::GetSenderName() const
{
    return message_data.sender_name();
}

int Message::GetReceiverId() const
{
    return message_data.receiver_id();
}

std::string Message::GetDateOfSending() const
{
    return message_data.date_of_sending();
}

std::string Message::GetTimeOfSending() const
{
    return message_data.time_of_sending();
}
