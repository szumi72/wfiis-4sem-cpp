#ifndef EVENT_H
#define EVENT_H
#include <string>
#include<iostream>

class Event{
public: 
    Event() = default;
    Event(int id):_targetId(id){}       
    virtual ~Event() = default;
    virtual std::ostream& print(std::ostream& o)const=0;
    int getTargetId()const{
        return _targetId;
    }
    std::string getName() const{
        return _name;
    }
    friend std::ostream& operator<<(std::ostream& o, const Event& event){
       return event.print(o);
    }
protected:
    int _targetId=0;
    std::string _name;
};


#endif