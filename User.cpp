//
// Created by niccolo on 12/07/19.
//

#include "User.h"

std::string User::getName() const {
    return userName;
}

void User::newChat(User &other) {
    userChats->newChat(*this, other);
    other.userChats->newChat(other, *this);
}

bool User::deleteChat(User &other) {
    return userChats->deleteChat(*this, other);
}

Chat &User::getChat(User &other) {
    return *(userChats->chats[other.getName()]);
}

void User::readChat(User &other) {
    userChats->chats[other.getName()]->setAllRead();
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

int User::getUread() const {
    return userChats->getUnread();
}