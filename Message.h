//
// Created by niccolo on 12/07/19.
//

#ifndef CHATPROJECT_MESSAGE_H
#define CHATPROJECT_MESSAGE_H

#include <string>
#include "User.h"

class Message {
public:
    Message(std::string s, std::string r, std::string t, float h) :
            sender(s), receiver(r), text(t), hour(h) {}

    ~Message() {}

    std::string getSender() const;

    std::string getReceiver() const;

    std::string getText() const;

    bool operator==(const Message &m) const;

    float getHour() const;
private:
    std::string sender;
    std::string receiver;
    std::string text;
    float hour;
};

#endif //CHATPROJECT_MESSAGE_H
