#include "PickItemEvent.h"

std::ostream& PickItemEvent::print(std::ostream& o)const {     
    return o<<"Name: "<<_name<<", target ID: "<<_targetId << " item: "<<_item <<std::endl;
} 