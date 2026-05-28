#pragma once
#include<string>


class Entity{
public:
    static int count;
    Entity(const std::string& n):name(n),id(count){
        count++;
    }
    virtual ~Entity()=default;
    virtual void debugInfo()const = 0;
protected:
    std::string name;
    int id;
};

int Entity::count = 0;