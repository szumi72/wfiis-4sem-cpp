#pragma once
#include "Channel.h"
#include<vector>

//klasa sluzaca do obslugi wielu kanałów
class MultiChannel: public Channel{
public:
    MultiChannel()=default;
    void addChannel(Channel* c){
        channels.push_back(c);
    }
    //nadpisana metoda send uruchamia send dla wszystkich kanałów
    void send(const std::string& a,const std::string& b)const override{
        for(auto& c:channels){
            if(c){
                c->send(a,b);
                std::cout<<std::endl;
            }
        }
    }
private:
    std::vector<Channel*> channels;
};