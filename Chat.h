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
    Chat(User &m, User &o);

    ~Chat() {
        messages.erase(messages.begin(), messages.end());
    }

    User getOther() const;

    User getMe() const;

    void addMessage(const Message &m);

    void deleteMessage(int pos);

    bool searchMessage(const Message &m);

    bool searchMessage(float hour);

    void setAllRead();

    int getUnread() const;

private:
    User &me;
    User &other;
    std::vector<Message> messages;
};

#endif //CHATPROJECT_CHAT_H
