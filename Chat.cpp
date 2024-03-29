//
// Created by niccolo on 12/07/19.
//

#include "Chat.h"

Chat::Chat(User &m, User &o) : me(m), other(o) {
    messages.reserve(100);
}

User Chat::getOther() const {
    return other;
}

User Chat::getMe() const {
    return me;
}

void Chat::addMessage(const Message &m) {
    if ((me.getName() == m.getSender() && other.getName() == m.getReceiver()) ||
        (me.getName() == m.getReceiver() && other.getName() == m.getReceiver())) {
        messages.push_back(m);
        other.getChat(me).messages.push_back(m);
    }
}

void Chat::deleteMessage(int pos) {
    if (pos < messages.size())
        messages.erase(messages.begin() + pos);
}

bool Chat::searchMessage(const Message &m) {
    std::vector<Message>::const_iterator i = messages.begin();
    bool found = false;
    while (!found && i != messages.end()) {
        if (i->operator==(m))
            found = true;
        i++;
    }
    return found;
}

bool Chat::searchMessage(float hour) {
    std::vector<Message>::const_iterator i = messages.begin();
    bool found = false;
    while (!found && i != messages.end()) {
        if (i->getHour() == hour)
            found = true;
        i++;
    }
    return found;
}

void Chat::setAllRead() {
    for (std::vector<Message>::iterator i = messages.begin(); i != messages.end(); i++)
        i->setRead(true);
}

int Chat::getUnread() const {
    int unread = 0;
    for (std::vector<Message>::const_iterator i = messages.begin(); i != messages.end(); i++) {
        if (!i->isRead())
            unread++;
    }
    return unread;
}