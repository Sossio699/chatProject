//
// Created by niccolo on 12/07/19.
//

#ifndef CHATPROJECT_USER_H
#define CHATPROJECT_USER_H

#include "Chat.h"
#include "Register.h"
#include "Message.h"
#include <string>
#include <list>

class Chat;

class Register;

class User {
public:
    User(std::string name) : userName(name) {}

    ~User() {}

    std::string getName() const;

    void newChat(User &other);

    void deleteChat(User &other);

    Chat &getChat(User &other);

    bool operator==(const User &u) const;

    bool searchMessage(const User &u, const Message &m);

    Register *userChats;

private:
    std::string userName;
};

#endif //CHATPROJECT_USER_H
