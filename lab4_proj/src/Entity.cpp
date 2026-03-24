#include "Entity.h"

void Entity::takeDamage(int dmg){
    _health-=dmg;
    _bus.emit(std::make_unique<DamageEvent>(_id,dmg));
    if(_health<0){
        _health = 0;
        _bus.emit(std::make_unique<DeathEvent>(_id));
    }
}
void Entity::heal(int power){
    _health+=power;
    _bus.emit(std::make_unique<HealEvent>(_id,power));
}