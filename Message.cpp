//
// Created by niccolo on 12/07/19.
//

#include <iostream>
#include "Message.h"

std::string Message::getSender() const {
    return sender;
}

std::string Message::getReceiver() const {
    return receiver;
}

std::string Message::getText() const {
    return text;
}

bool Message::operator==(const Message &m) const {
    if (sender != m.sender)
        return false;
    else {
        if (receiver != m.receiver)
            return false;
        else {
            if (text != m.text)
                return false;
        }
    }
    return true;
}

float Message::getHour() const {
    return hour;
}