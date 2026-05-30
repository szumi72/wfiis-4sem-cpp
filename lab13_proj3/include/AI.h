#pragma once
#include "Charactrer.h"
#include<iostream>


//klasa reprezentujaca niegrywalne postacie posiadjące AI
class NPC: public Charactrer{
public:
    NPC(const std::string& n,Faction fr, AI a,int hp, int man,std::unique_ptr<Class> cls):Charactrer(n,fr,hp,man,std::move(cls)),ai(a){}
    virtual void debugInfo()const override{
        std::cout<<"\n\nAI:\n\n\tEntityID: "<<id<<"\n\tName: "<<name<<"\n\tFaction: "<<factionToString(fraction)<<"\n\tAI: "<<AIToString(ai)<<"\n\tHealth: "<<health<<"\n\tMana: "<<mana<<"\n\tClass: "<<classType->getClassName()<<std::endl;
    }
protected:
    AI ai;
};
