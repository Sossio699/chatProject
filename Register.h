//
// Created by niccolo on 12/07/19.
//

#ifndef CHATPROJECT_REGISTER_H
#define CHATPROJECT_REGISTER_H

#include <map>
#include "Chat.h"

class User;

class Chat;

class Register {
public:
    Register() {}

    ~Register() {
        chats.clear();
    }

    void newChat(User &me, User &other);

    void deleteChat(User &me, User &other);

    std::map<std::string, Chat *> chats;
};

#endif //CHATPROJECT_REGISTER_H
