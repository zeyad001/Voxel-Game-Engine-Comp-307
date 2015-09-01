#include "EventMessenger.h"

EventMessenger::EventMessenger()
{
}

EventMessenger::~EventMessenger()
{
    for(int i = 0;i < listeners.size();i++)
    {
       
    }
}

    void EventMessenger::registerEvent(std::string s)
    {
        listeners[s] = list();
    }
    void EventMessenger::registerListener(std::string s,Listener* l)
    {
      listeners[s].push_back(l);
    }
    void EventMessenger::removeListener(std::string s,Listener* l)
    {
            list listen  = listeners[s];
            int i = 0;
            bool found = false;
            for(Listener* li : listen)
            {
                if(li == l)
                {
                    found = true;
                    break;
                }
                i++;
                
            }
            if(found){
            listen.erase(listen.begin() + i);
            }
            
            
    }
   
      void EventMessenger::pushEvent(std::string s,Event& e)
      {
           list listen  = listeners[s];
           for(Listener* li : listen)
            {
                
                li->notify(e);
               
                
            }
          
      }
    