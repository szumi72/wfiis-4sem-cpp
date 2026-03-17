#ifndef HEATLHPOTION_H
#define HEATLHPOTION_H
#include "Item.h"

class HealthPotion : public Item{
public:
    //konstruktor broni z parametrami str - nazwa  przedmiotu, val - punkty leczenia
    HealthPotion(const std::string str, int val):Item(str),_healingStrenght(val){}

    //zwraca ilosc odzyskiwanych punktow leczenia
    int getPower()const override{return _healingStrenght;}

    void print(std::ostream& o)const override{
        o<<"Name: "<<_itemName<<", Healing strength: "<<_healingStrenght<<std::endl;
    }

    Item* clone() const override{
        return new HealthPotion(*this);
    }

private:
    int _healingStrenght;
};


#endif