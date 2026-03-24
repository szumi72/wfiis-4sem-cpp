#include "HealEvent.h"

std::ostream& HealEvent::print(std::ostream& o)const{     
    return o<<"Name: "<<_name<<", target ID: "<<_targetId << " hit points restored: "<<_healPower <<std::endl;
} 