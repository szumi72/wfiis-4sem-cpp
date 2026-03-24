#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include<vector>

class Player: public Entity{
public:
    Player(int idx,int hp,EventBus& b):Entity(idx ,hp, b){}
    //add Item(std::string) to player Inventory
    void pickItem(std::string str);
private:
    std::vector<std::string>_inventory;
};

#endif 