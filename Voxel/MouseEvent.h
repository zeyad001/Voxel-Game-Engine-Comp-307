#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H
#include "Event.h"
class MouseEvent : public Event
{
public:
    MouseEvent(int x,int y);
    ~MouseEvent();
    int x,y;

};

#endif // MOUSEEVENT_H
