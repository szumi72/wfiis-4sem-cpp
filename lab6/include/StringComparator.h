#ifndef STRINGCOMPARATOR_H
#define STRINGCOMPARATOR_H
#include<string>
#include "HelpFunctions.h"
#include <iostream>
#include <functional>
#include <vector>


//klasa bazowa comparatorów stringów
class StringComparator{
public:
    virtual bool operator()(const std::string& s1,const std::string& s2) const=0;
    virtual ~StringComparator(){}
 

};




class CaseSensitiveLess: public StringComparator{
public:
    bool operator()(const std::string& s1,const std::string& s2) const override{
        
        return s1<s2;
    }
};

class CaseInsensitiveLess: public StringComparator{
public:
    bool operator()(const std::string& s1,const std::string& s2)const override{
        
        std::string temp1 = little(s1);
        std::string temp2 = little(s2);
        return temp1<temp2;
    }
};


class LengthLess: public StringComparator{
    public:
    bool operator()(const std::string& s1,const std::string& s2)const override{
        
        return s1.length()<s2.length();
    }
};

class IgnorePrefixComparator:public StringComparator{
public:
    IgnorePrefixComparator(const StringComparator& cmp,std::string pref):_cmp(cmp),_pref(pref){}
    bool operator()(const std::string& s1,const std::string& s2)const override{
        const std::string& temp1 = removePrefix(s1,_pref);
        const std::string& temp2 = removePrefix(s2,_pref);
       return _cmp(temp1,temp2);
    }
    
private:
    const StringComparator& _cmp;
    std::string _pref;
};

//łączy dodane comparatory, rozpatruje kolejny jeśli dla poprzedniego napisy są takie same
class CompositeComparator: public StringComparator{
public: 
    void add(StringComparator* cmp){
        _col.push_back(cmp);
    }
    bool operator()(const std::string& s1,const std::string& s2) const override{
        if(_col.empty()){
            return false;
        }
        for(size_t i=0;i<_col.size();i++){
            if(!((*_col[i])(s1,s2) || (*_col[i])(s2,s1))){
                continue;
            }
            else{
                return (*_col[i])(s1,s2);
            }
        }  
        return false;    
    }

private:
    std::vector<StringComparator*> _col;
};

#endif