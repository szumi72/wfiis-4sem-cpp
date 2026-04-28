#include "ExpressionParser.h"

std::unique_ptr<Expression> ExpressionParser::parseRPN(const std::string &wyr)
{
    std::vector<Token> tokens = lexer(wyr);
    std::stack<std::unique_ptr<Expression>> stack;
    for (const auto &tok : tokens)
    {
        switch (tok.type_)
        {
        case TokenType::Constant:
        {
            stack.push(std::make_unique<Constant>(tok.value_));
            break;
        }
        case TokenType::Variable:
        {           
            stack.push(std::make_unique<Variable>(tok.value_));
            break;
        }
        case TokenType::UnaryOperator:
        {
            auto op = std::make_unique<UnaryOperator>(tok.value_);  
            auto child = std::move(stack.top());
            stack.pop();
            op->addChild(std::move(child));
            stack.push(std::move(op));
            break;
        }
        case TokenType::BinaryOperator:
            if (stack.size() >= 2)
            {
                auto right = std::move(stack.top());
                stack.pop();
                auto left = std::move(stack.top());
                stack.pop();                
                auto op = std::make_unique<BinaryOperator>(tok.value_);
                op->addLeftChild(std::move(left));
                op->addRightChild(std::move(right));
                stack.push(std::move(op));
            }
            break;
        }
    }
    
    return std::move(stack.top());
}