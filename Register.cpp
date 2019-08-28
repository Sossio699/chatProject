//
// Created by niccolo on 12/07/19.
//

#include "Register.h"

void Register::newChat(User &me, User &other) {
    chats[other.getName()] = new Chat(me, other);
    other.userChats->chats[me.getName()] = chats[other.getName()];
}

void Register::deleteChat(User &me, User &other) {
    for (const auto &i : chats)
        if (i.first == other.getName())
            chats.erase(other.getName());
}