//
// Created by niccolo on 27/08/19.
//

#include "gtest/gtest.h"
#include "../User.h"
#include "../Chat.h"
#include "../Register.h"
#include "../Message.h"

TEST(Chat, Constructors) {
    std::string n = "first";
    Register r;
    Register s;
    User u("first", r);
    User v("second", s);
    ASSERT_EQ(n, u.getName());
    Message m("first", "second", "hello", 0);
    ASSERT_EQ(m.getReceiver(), v.getName());
    Chat c(u, v);
    ASSERT_EQ(c.getMe(), u);
    ASSERT_EQ(c.getOther(), v);
}

TEST(Chat, SendMessage) {
    Register r;
    Register s;
    User u("first", r);
    User v("second", s);
    Message m("first", "second", "hello", 17.32);
    u.newChat(v);
    Chat c = u.getChat(v);
    c.addMessage(m);
    ASSERT_EQ(u.userChats->chats["second"]->searchMessage(m), v.userChats->chats["first"]->searchMessage(m));
}