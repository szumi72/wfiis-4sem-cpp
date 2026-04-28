#pragma once
#include <string>
#include<vector>
#include<iostream>
#include <cctype>
#include <cstdlib>

//typ tokenu(typy wyrażeń)
enum class TokenType{
    Constant,
    Variable,
    BinaryOperator,
    UnaryOperator
};
//typ i wartość wyrażenia
struct Token{
    Token(TokenType type, std::string value):type_(type),value_(value){}
    TokenType type_;
    std::string value_;
};

//funkcja rozdzielająca string po spacjach i zwracająca std::vector stringów
std::vector<std::string> cutString(const std::string& s);

//rozróżnia typ tokenu na podstawie wartości stringa i zwraca vector tokenów
std::vector<Token> lexer(const std::string& s);