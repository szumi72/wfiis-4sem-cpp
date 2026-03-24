#ifndef DAMAGEEVENT_H
#define DAMAGEEVENT_H
#include "Event.h"

class DamageEvent: public Event{
public:
    DamageEvent(int id, int dmg):Event(id),_damage(dmg){
        _name = "Damage Event";        
    }    
    std::ostream& print(std::ostream& o)const override;
    int getDamage()const{return _damage;}
    
private:
    int _damage;
};

#endif