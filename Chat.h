//
// Created by niccolo on 12/07/19.
//

#ifndef CHATPROJECT_CHAT_H
#define CHATPROJECT_CHAT_H


#include <vector>
#include "User.h"
#include "Message.h"

class User;

class Message;

class Chat {
public:
    Chat(User &m, User &o) : me(m), other(o) {
        messages.reserve(100);
    }

    ~Chat() {
        messages.erase(messages.begin(), messages.end());
    }

    User &getOther() const;

    User &getMe() const;

    void addMessage(const Message &m);

    void deleteMessage(int pos);

    bool searchMessage(const Message &m);

    bool searchMessage(float hour);
private:
    User &me;
    User &other;
    std::vector<Message> messages;
};

#endif //CHATPROJECT_CHAT_H
