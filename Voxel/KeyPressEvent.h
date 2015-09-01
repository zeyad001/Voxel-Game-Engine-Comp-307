#ifndef KEYPRESSEVENT_H
#define KEYPRESSEVENT_H
#include "Event.h"
class KeyPressEvent : public Event
{
public:
    KeyPressEvent(char c);
    ~KeyPressEvent();
    char key;

};

#endif // KEYPRESSEVENT_H
