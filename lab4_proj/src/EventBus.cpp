#include "EventBus.h"

void EventBus::processEvents() {
    while (!_eventQueue.empty()) {            
        const Event* currentEvent = _eventQueue.front().get();           
        for (const auto& callback : _subscribers) {
            callback(*currentEvent);
        }
        _eventQueue.pop();
    }
}