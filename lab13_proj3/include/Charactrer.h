#pragma once
#include<Entity.h>
#include<memory>
#include "Class.h"
#include "Enums.h"

class Charactrer:public Entity{
public:
    Charactrer(const std::string& n,Faction fr ,int hp, int man,std::unique_ptr<Class> cls):Entity(n),fraction(fr),health(hp),mana(man),classType(std::move(cls)){}
    virtual void debugInfo()const = 0;
protected:
    Faction fraction;
    int health;
    int mana;
    std::unique_ptr<Class> classType;
};