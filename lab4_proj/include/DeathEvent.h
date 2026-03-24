#ifndef DEATHEVENT_H
#define DEATHEVENT_H
#include "Event.h"

class DeathEvent: public Event{
public:
    DeathEvent(int id):Event(id){
        _name = "Death Event";        
    }    
    std::ostream& print(std::ostream& o)const override;    
};

#endif