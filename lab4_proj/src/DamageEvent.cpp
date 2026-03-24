#include "DamageEvent.h"

std::ostream& DamageEvent::print(std::ostream& o)const{     
    return o<<"Name: "<<_name<<", target ID: "<<_targetId << " damage dealt:  "<<_damage <<std::endl;
} 