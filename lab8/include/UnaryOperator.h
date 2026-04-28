#pragma once
#include <memory>
#include "Expression.h"

//klasa reprezentująca działanie na 1 liczbie
class UnaryOperator:public Expression{
public:
    UnaryOperator(std::string o);
    
    //wykonuje podstawowe operacje na swoich "dzieciach"
    double eval()override;
    
    //wykonuje podstawowe operacje na swoich "dzieciach" z zadanym kontekstem
    double eval(const Context& c)override;
    
    //zwraca dziecko dla 
    Expression& operator[](int k) override;
    
    const Expression& operator[](int k)const override;
    
    //przejmuje własność wyrażenia i przypisuje jako dziecko
    void addChild(std::unique_ptr<Expression> ptr);

    std::string toString()const override;

   std::unique_ptr<Expression> simplify()override;
    
private:
    std::unique_ptr<Expression> child_;
    std::string operator_;
};