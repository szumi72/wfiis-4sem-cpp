#pragma once
#include "Channel.h"

//zwykly kanał do SMS obsluguje wysylanie sms
class SmsChannel:public Channel{
public:
    //metoda z channel do wywylania SMS
    void send(const std::string& a, const std::string& b)const override{
        std::cout<<"SMS to " <<a<<": "<<b;
    }
    
};