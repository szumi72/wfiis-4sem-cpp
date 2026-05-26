#pragma once
#include"Channel.h"
#include <iostream>

//klasa opakowująca wywsyłanie w HTTP request
class HTTPChannel:public Channel{
public:
    HTTPChannel()=default;
    //metoda send wysyła odpowiedni format
    void send(const std::string& url,const std::string& payload)const override{
        std::cout<<"HTTP request to "<<url<<payload;
    }
    virtual ~HTTPChannel()=default;
};