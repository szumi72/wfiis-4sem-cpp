#ifndef EVENTBUS_H
#define EVENTBUS_H
#include<queue>
#include<functional>
#include <memory>
#include "DamageEvent.h"
#include "HealEvent.h"
#include "PickItemEvent.h"
#include "DeathEvent.h"

class EventBus {
public:
    //adds System to subscriber vector    
    void subscribe(std::function<void(const Event&)> callback) {
        _subscribers.push_back(callback);
    }
    //adds Event to the eventQueue   
    void emit(std::unique_ptr<Event> event) {        
        _eventQueue.push(std::move(event));
    }
    //runs all events in the eventQueue by every System in subscriber vector
    void processEvents();
private:    
    std::queue<std::unique_ptr<Event>> _eventQueue;   
    std::vector<std::function<void(const Event&)>> _subscribers;

};

#endif 