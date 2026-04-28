#pragma once
#include "Expression.h"

//klasa reprezentująca wyrażenie stałej liczby
class Constant: public Expression{
public:
    //zamienia stringa na wartość i przypisuje ją do value_
    Constant(const std::string& s):value_(std::strtod(s.c_str(),nullptr)){}
    Constant(double val):value_(val){}
    double eval()override{
        return value_;
    }
    //kontekst jest pomijany ponieważ constant jest stałą wartością
    double eval(const Context& )override{
        return eval();
    }
    // Constant nie ma dzieci — operator[] nie powinien być używany
    Expression& operator[](int ) override{
        return *this;
    }
    // Constant nie ma dzieci — operator[] nie powinien być używany
    const Expression& operator[](int )const override{
        return *this;
    }

    std::string toString()const override{
        return std::to_string(value_);
    }

    std::unique_ptr<Expression> simplify()override{
        return std::make_unique<Constant>(value_);
    }

private:
    double value_;
};