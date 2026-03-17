#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>

class Item{
public:
    Item(const std::string str):_itemName(str){}
    virtual ~Item(){}
    const std::string& name() const {
        return _itemName;
    }
    void setName(const std::string& name) {
        _itemName = name;
    }  
    virtual Item* clone() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual int getPower()const =0;
    friend std::ostream& operator<<(std::ostream& os, const Item& item) {
        item.print(os);
        return os;
    }
protected:
    std::string _itemName;
};


#endif