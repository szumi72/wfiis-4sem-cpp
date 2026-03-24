#ifndef SOUNDSYSTEM_H
#define SOUNDSYSTEM_H
#include"Event.h"
#include<iostream>

class SoundSystem{
public:
    static void handleEvent(const Event& event);
};

#endif 