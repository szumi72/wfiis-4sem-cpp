#ifndef COMPARATORBULDER_H
#define COMPARATORBULDER_H
#include <vector>
#include "StringComparator.h"
#include <deque>

class ComparatorBuilder{
public:

    ComparatorBuilder(){
        // Rezerwujemy miejsce, żeby adresy wrapperów były stałe
        _wrappers.reserve(10);
    }
    //buduje comparator na podstawie dodanych wcześniej
    CompositeComparator build(){
        if(_data.empty()){
            return CompositeComparator();
        }
        CompositeComparator cmp;
        for(size_t i=0;i<_data.size();i++){
            cmp.add(_data[i]);
        }       
        
        return cmp;
    }
    //dodaje CaseInsensitive comparator
    ComparatorBuilder& caseInsensitive(){
        _data.emplace_back(&ci);
        return *this;
    }
    //dodaje CaseSensitive comparator
    ComparatorBuilder& thenCaseSensitive(){
        _data.emplace_back(&cs);
        return *this;
    }
    //dodaje Lenght comparator
    ComparatorBuilder& thenByLength(){
        _data.emplace_back(&len);
        return *this;
    }
    //opakowuje ostatnio dodant comparator w ignorePrefix
    ComparatorBuilder& ignorePrefix(std::string pref){

        auto last = _data.back();
        _data.pop_back();
        _wrappers.push_back(IgnorePrefixComparator(*last,pref));
        _data.push_back(&_wrappers.back());
        return *this;
    }


    ~ComparatorBuilder(){        
    }

private:    
    std::vector<StringComparator*> _data; 
    CaseInsensitiveLess ci;
    CaseSensitiveLess cs;
    LengthLess len;       
    std::vector<IgnorePrefixComparator> _wrappers;   
    
};

#endif