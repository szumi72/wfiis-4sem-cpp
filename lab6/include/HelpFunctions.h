#ifndef HELPFUNCTIONS_H
#define HELPFUNCTIONS_H
#include<string>
#include<algorithm>

std::string little(std::string s){
    for(size_t i=0;i<s.length();i++){
        s[i]=std::tolower(s[i]);       
    }
    return s;
}

std::string removePrefix(const std::string& s, const std::string& pref){
    bool falg=true;
    for(size_t i=0;i<pref.size();i++){
        if(s[i]==pref[i]){
            continue;
        }else{
            falg = false;
            break;
        }
    }   
    std::string s1=s;
    if(falg == true){
        s1.erase(0,pref.length());
    }
    return s1;
}

#endif