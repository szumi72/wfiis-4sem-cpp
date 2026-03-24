#ifndef PICKITEMEVENT_H
#define PICITEMEVENT_H
#include "Event.h"

class PickItemEvent: public Event{
public:
    PickItemEvent(int id,const std::string& it):Event(id),_item(it){
        _name = "Pick Item Event";
    }    
    std::string getItemName()const{return _item;}
    std::ostream& print(std::ostream& o)const override;
private:
    std::string _item;
};

#endif