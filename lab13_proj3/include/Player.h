#pragma once
#include "Charactrer.h"
#include<iostream>

class Player:public Charactrer{
public:
    Player(const std::string& n,Faction fr ,int hp, int man,std::unique_ptr<Class> cls):Charactrer(n,fr,hp,man,std::move(cls)){}

    virtual void debugInfo()const override{
        std::cout<<"\n\nPlayer:\n\n\tEntityID: "<<id<<"\n\tName: "<<name<<"\n\tFaction: "<<factionToString(fraction)<<"\n\tHealth: "<<health<<"\n\tMana: "<<mana<<"\n\tClass: "<<classType->getClassName()<<std::endl;
    }
};