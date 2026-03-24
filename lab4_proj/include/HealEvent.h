#ifndef HEALEVENT_H
#define HEALEVENT_H
#include "Event.h"

class HealEvent: public Event{
public:
    HealEvent(int id, int dmg):Event(id),_healPower(dmg){
        _name = "Heal Event";        
    } 
    int getHealingPower()const {return _healPower;} 
    std::ostream& print(std::ostream& o)const override;
private:
    int _healPower;
};

#endif