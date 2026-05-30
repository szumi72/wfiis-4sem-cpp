#pragma once 
#include <iostream>
#include "Entity.h"

//klsa drzewa, statyczny obiekt w swiecie
class Tree:public Entity{
public:
    Tree(const std::string& n):Entity(n){}
    virtual void debugInfo()const override{
        std::cout<<"\n\nPlayer:\n\n\tEntityID: "<<id<<"\n\tName: "<<name<<std::endl;
    }
};