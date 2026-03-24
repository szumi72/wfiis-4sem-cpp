#include "DeathEvent.h"

std::ostream& DeathEvent::print(std::ostream& o)const {     
    return o<<"Name: "<<_name<<", target ID: "<<_targetId<<std::endl;
} 