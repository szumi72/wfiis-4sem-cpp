#pragma once
#include<string>


//bazowa klasa dla encji w swiecie
class Entity{
public:
    static int count;
    //przy konstruktorze jest nadawane unikatowe ID
    Entity(const std::string& n):name(n),id(count){
        count++;
    }
    virtual ~Entity()=default;
    //metoda do wyswietalnia info o danej encji
    virtual void debugInfo()const = 0;
protected:
    std::string name;
    int id;
};

int Entity::count = 0;