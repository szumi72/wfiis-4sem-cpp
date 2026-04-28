#pragma once
#include <memory>
#include "Expression.h"


//klasa reprezentująca działanie na 2 liczbach(lub zmiennych)
class BinaryOperator:public Expression{
public:
    BinaryOperator(std::string o);
    
    //wykonuje podstawowe operacje na swoich "dzieciach"
    double eval()override;
    
    //wykonuje podstawowe operacje na swoich "dzieciach" z zadanym kontekstem
    double eval(const Context& c)override;
    
    //zwraca lewe dziecko dla k=0 i prawe dla k=1 w innym przypadku referencje do siebie
    Expression& operator[](int k) override;
    
    const Expression& operator[](int k)const override;
    
    //przejmuje własność wyrażenia i przypisuje jako lewe dziecko
    void addLeftChild(std::unique_ptr<Expression> ptr);
    
    //przejmuje własność wyrażenia i przypisuje jako prawe dziecko
    void addRightChild(std::unique_ptr<Expression> ptr);

    std::string toString()const override;

    std::unique_ptr<Expression> simplify()override;
private:
    std::unique_ptr<Expression> leftChild_;
    std::unique_ptr<Expression> rightChild_;
    std::string operator_;
};