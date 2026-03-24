#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
class Enemy: public Entity{
public:
    Enemy(int idx,int hp,EventBus& b):Entity(idx ,hp, b){}

private:
};

#endif 