#pragma once 
#include <iostream>
#include "Entity.h"

class Tree:public Entity{
public:
    Tree(const std::string& n):Entity(n){}
    virtual void debugInfo()const override{
        std::cout<<"\n\nPlayer:\n\n\tEntityID: "<<id<<"\n\tName: "<<name<<std::endl;
    }
};