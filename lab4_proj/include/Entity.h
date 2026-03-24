#ifndef ENTITY_H
#define ENTITY_H
#include "EventBus.h"


class Entity{
public:
    Entity(int i,int hp, EventBus& b):_id(i),_health(hp),_bus(b){}
    virtual ~Entity(){}
    //reduce health by dmg and emit DamageEvent
    void takeDamage(int dmg);
    //restore health by power and emit HealEvent
    void heal(int power);
    int getId()const{
        return _id;
    }
    int getHealth()const{
        return _health;
    }
    EventBus& getBus()const{
        return _bus;
    }

protected:
    int _id;
    int _health;
    EventBus& _bus;
};

#endif