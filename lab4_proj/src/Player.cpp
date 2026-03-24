#include "Player.h"

void Player::pickItem(std::string str){
    _inventory.push_back(str); 
    _bus.emit(std::make_unique<PickItemEvent>(_id,str));       
}