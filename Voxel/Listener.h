#ifndef LISTENER_H
#define LISTENER_H

#include "Event.h"

class Listener
{
public:
  
     virtual void notify(Event& e);
};

#endif // LISTENER_H
