#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"
#include <vector>
#include<iostream>

class Inventory{
public:

    Inventory()=default;
    Inventory(const Inventory& other){
        for(auto s:other.items){
            items.push_back(s->clone());
        }
    }
    ~Inventory(){
        for(auto s:items){
            delete s;
        }
    }
    void add(Item* item){
        items.push_back(item);
    }
    Item& operator[](int k){
        return *items[k];
    }
    const Item& operator[](int k)const{
        return *items[k];
    }
    
    friend std::ostream& operator<<(std::ostream& o,const Inventory& item){   
        for(size_t i=0;i<item.items.size();i++){
            o<<*item.items[i];
        }
        return o;
    }

private:
    std::vector<Item*> items;
};


#endif