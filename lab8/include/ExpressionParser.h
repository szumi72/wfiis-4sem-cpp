#pragma once
#include <stack>
#include "Lexer.h"
#include "Constant.h"
#include "Variable.h"
#include "BinaryOperator.h"
#include "UnaryOperator.h"
#include <memory>

//parser do wyrażeń
class ExpressionParser{
public:
    //statyczna metoda powoduje parsowanie argumentu
    static std::unique_ptr<Expression> parseRPN(const std::string& wyr);
    

};