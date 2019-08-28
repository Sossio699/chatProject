//
// Created by niccolo on 12/07/19.
//

#include "User.h"

std::string User::getName() const {
    return userName;
}

void User::newChat(User &other) {
    userChats->newChat(*this, other);
}

void User::deleteChat(User &other) {
    userChats->deleteChat(*this, other);
}

Chat &User::getChat(User &other) {
    return *(userChats->chats[other.getName()]);
}

bool User::operator==(const User &u) const {
    if (userName == u.userName)
        return true;
    return false;
}

bool User::searchMessage(const User &u, const Message &m) {
    bool found = false;
    if ((m.getSender() == u.userName || m.getReceiver() == u.userName) &&
        (m.getSender() == userName || m.getReceiver() == userName)) {
        for (auto i : userChats->chats) {
            if (i.second->searchMessage(m))
                found = true;
        }
        return found;
    }
    return false;
}