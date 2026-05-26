#pragma once
#include "Channel.h"
#include<memory>
#include<iostream>

//klasa służąca do wysyłania powiadomienia na przechowuwany adres kanału
class NotificationService{
public:
    //przypisanie kanału do serwisu powiadomien
    NotificationService(Channel* ptr){
        channel = ptr;
    }
    //alert wywysła powiadomienia na kanale który przechowuje
    void alert(const std::string& a, const std::string& b)const{
        channel->send(a,b);
        std::cout<<std::endl;
    }
private:
    Channel* channel;
    
};