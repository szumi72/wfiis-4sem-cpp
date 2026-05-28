#pragma once
#include <string>

class Class{
public:
    virtual ~Class()=default;
    virtual std::string getClassName()const = 0;
};

class Warrior:public Class{
public:
    std::string getClassName()const override{
        return "Warrior";
    }
};

class Mage:public Class{
public:
    std::string getClassName()const override{
        return "Mage";
    }
};

class Archer:public Class{
public:
    std::string getClassName()const override{
        return "Archer";
    }
};

class Creature:public Class{
public:
    std::string getClassName()const override{
        return "Creature";
    }
};

