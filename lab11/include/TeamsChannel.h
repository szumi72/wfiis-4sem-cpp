#pragma once
#include "HTTPChannel.h"

//klasa wysyłająca HTTP na kanał grupowy 
class TeamsChannel:public HTTPChannel{
public:

    //metoda robi odpowiedni format komunikatu i przesyła go do HTTP
    void send(const std::string& a,const std::string& b)const override{
        
        std::string paylode = "channel="+a+"&message+"+b;
        std::string url = "https://teams.example/send";
        HTTPChannel::send(url,paylode);
    }

};