#pragma once
#include <string>
#include<map>
#include<memory>
#include<iostream>


//Bazowa klasa abstrakcyjna
class Expression{
public:
    //mapowanie nazwy zmiennej na wartość
    using Context = std::map<std::string, double>;   
    //zwraca "dzieci" wyrażenia jeżeli je ma
    virtual Expression& operator[](int k)=0;
    virtual const Expression& operator[](int k)const=0;
    //wykonuje dane wyrażenie z zadanym kontekstem
    virtual double eval(const Context& c) = 0;
    //wykonuje dane wyrażenie z zadanym kontekstem
    virtual double eval() = 0;
    //wirtualny destruktor
    virtual ~Expression() = default;
    //metoda wypisywania wyrazenia
    virtual std::string toString()const=0;
    //upraszcza działania
    virtual std::unique_ptr<Expression> simplify() = 0;
protected:
  
    
};