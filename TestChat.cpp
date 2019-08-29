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
    u.getChat(v).addMessage(m);
    ASSERT_EQ(u.getChat(v).searchMessage(m), v.getChat(u).searchMessage(m));
}

TEST(Chat, SearchMessage) {
    Register r;
    Register s;
    User u("first", r);
    User v("second", s);
    Message m("first", "second", "hello", 17.32);
    u.newChat(v);
    u.getChat(v).addMessage(m);
    ASSERT_EQ(u.searchMessage(v, m), v.searchMessage(u, m));
    Message n("second", "first", "hi", 17.40);
    v.getChat(u).addMessage(n);
    Chat c = v.getChat(u);
    ASSERT_EQ(c.searchMessage(17.32), true);
    ASSERT_EQ(c.searchMessage(17.41), false);
}

TEST(Chat, Deleting) {
    Register r;
    Register s;
    User u("first", r);
    User v("second", s);
    Message m("first", "second", "hello", 17.32);
    u.newChat(v);
    u.getChat(v).addMessage(m);
    u.getChat(v).deleteMessage(0);
    ASSERT_EQ(false, u.getChat(v).searchMessage(m));
    ASSERT_EQ(u.deleteChat(v), true);
    ASSERT_EQ(u.deleteChat(v), false);
    ASSERT_EQ(v.getChat(u).searchMessage(m), true);
}