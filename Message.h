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
            sender(s), receiver(r), text(t), hour(h) {
        if (!correctHour())
            hour = 0;
    }

    ~Message() {}

    std::string getSender() const;

    std::string getReceiver() const;

    std::string getText() const;

    bool operator==(const Message &m) const;

    float getHour() const;

    bool isRead() const;

    void setRead(bool r);

private:
    std::string sender;
    std::string receiver;
    std::string text;
    float hour;
    bool read = false;

    bool correctHour() {
        if (hour < 0 || hour > 24)
            return false;
        int h = (int) hour;
        if (hour - h > 0.59)
            return false;
        return true;
    }
};

#endif //CHATPROJECT_MESSAGE_H
