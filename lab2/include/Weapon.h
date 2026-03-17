#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"

class Weapon: public Item{
public:
    //konstruktor broni z parametrami str - nazwa  przedmiotu, val - obrazenia broni
    Weapon(const std::string str, int val):Item(str),_weaponDamage(val){}

    //zwraca obrazenia broni
    int getPower()const override{return _weaponDamage;}

    void print(std::ostream& o)const override{
        o<<"Name: "<<_itemName<<", Damage: "<<_weaponDamage<<std::endl;
    }

    Item* clone() const override{
        return new Weapon(*this);
    }
private:
    int _weaponDamage;
};


#endif