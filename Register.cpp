//
// Created by niccolo on 12/07/19.
//

#include "Register.h"

void Register::newChat(User &me, User &other) {
    chats[other.getName()] = new Chat(me, other);
}

bool Register::deleteChat(User &me, User &other) {
    for (const auto &i : chats) {
        if (i.first == other.getName()) {
            chats.erase(other.getName());
            return true;
        }
    }
    return false;
}

int Register::getUnread() const {
    int unread = 0;
    for (const auto &i : chats)
        unread += i.second->getUnread();
    return unread;
}