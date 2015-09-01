#ifndef EVENTMESSENGER_H
#define EVENTMESSENGER_H
#include <vector>
#include <map>
#include <string>
#include "Listener.h"


typedef std::vector<Listener*> list;
class EventMessenger
{
public:
    EventMessenger();
    ~EventMessenger();
    std::map<std::string,list> listeners;
    void registerEvent(std::string);
    void registerListener(std::string,Listener*);
    void removeListener(std::string,Listener*);
    void pushEvent(std::string s,Event& e);
    static EventMessenger* getEventMessenger();
    
private:
    static EventMessenger messenger;
    
    

};

#endif // EVENTMESSENGER_H
