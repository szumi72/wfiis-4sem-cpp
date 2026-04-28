#pragma once
#include "Expression.h"
#include<string>

//klasa reprezentująca wyrażenie zmiennej
class Variable:public Expression{
public:
    Variable(std::string name):name_(name){}
    double eval()override{
        return eval({});
    }
    double eval(const Context& c)override{
        return c.at(name_);
    }
    // Variable nie ma dzieci — operator[] nie powinien być używany
    Expression& operator[](int )override{
        return *this;
    }
    // Variable nie ma dzieci — operator[] nie powinien być używany
    const Expression& operator[](int )const override{
        return *this;
    }
    std::string toString()const override{
        return name_;
    }

    std::unique_ptr<Expression> simplify()override{
        return std::make_unique<Variable>(name_);
    }
private:
    std::string name_;
};