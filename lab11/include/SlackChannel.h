#pragma once 
#include "HTTPChannel.h"

//klasa wysyłająca na kanał slack
class SlackChannel:public HTTPChannel{
public:
    //metoda robi odpowiedni format komunikatu i przesyła go do HTTP
    void send(const std::string& a,const std::string& b)const override{
        std::string paylode = "channel="+a+"&message+"+b;
        std::string url = "https://slack.example/send";
        HTTPChannel::send(url,paylode);
        
    }
};