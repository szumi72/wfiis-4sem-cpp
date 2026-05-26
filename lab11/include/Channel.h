#pragma once
#include<string>
#include<iostream>

//klasa bazowa do wszystkich kanałów
class Channel{
public:
    Channel()=default;
    //wirtualna metoda do wysyłania powiadomien w kanale
    virtual void send(const std::string& a,const std::string& b)const=0;
    virtual ~Channel()=default;

};