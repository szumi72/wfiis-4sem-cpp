#pragma once
#include <string>

//klasa bazowa dla klasy postaci
class Class{
public:
    virtual ~Class()=default;
    virtual std::string getClassName()const = 0;
};

//klasa wojownika
class Warrior:public Class{
public:
    std::string getClassName()const override{
        return "Warrior";
    }
};

//klasa maga
class Mage:public Class{
public:
    std::string getClassName()const override{
        return "Mage";
    }
};

//klasa łucznika
class Archer:public Class{
public:
    std::string getClassName()const override{
        return "Archer";
    }
};

//klasa stworzenia
class Creature:public Class{
public:
    std::string getClassName()const override{
        return "Creature";
    }
};

