
#include <iostream>

#include <vector>
#include <memory>

#include "Expression.h"
#include "ExpressionParser.h"

int main() {

    auto expr1 = ExpressionParser::parseRPN("2 3 + 4 *");
    std::cout << "expr1 = (2 + 3) * 4 -> " << expr1->toString() << std::endl;

    auto expr2 = ExpressionParser::parseRPN("x 2 + x *");
    std::cout << "expr2 = (x + 2) * x -> " << expr2->toString() << std::endl;

    auto expr3 = ExpressionParser::parseRPN("5 1 2 + 4 * + 3 -");
    std::cout << "expr3 = 5 + ((1 + 2) * 4) - 3 -> " << expr3->toString() << std::endl;



    auto expr4 = ExpressionParser::parseRPN("x ~");
    std::cout << "expr4 = -x -> " << expr4->toString() << std::endl;
    std::cout << "expr4(x = 3) = -3? " << expr4->eval({ {"x", 3} }) << std::endl;

    auto expr5 = ExpressionParser::parseRPN("x 2 + ~");
    std::cout << "expr5 = -(x + 2) -> " << expr5->toString() << std::endl;
    std::cout << "expr5(x = 3) = -(3 + 2) = -5? " << expr5->eval({ {"x", 3} }) << std::endl;



    auto expr6 = ExpressionParser::parseRPN("2 5 + 3 +"); // (2 + 5) + 3
    auto simplified6 = expr6->simplify();

    std::cout << "((2 + 5) + 3) -> (10?) : " << simplified6->toString() << std::endl;


    auto expr7 = ExpressionParser::parseRPN("2 5 + 3 + x *"); // ((2 + 5) + 3) * x
    auto simplified7 = expr7->simplify();

    std::cout << "((2 + 5) + 3) * x ->  (10 * x?) : " << simplified7->toString() << std::endl;




    auto expr8 = ExpressionParser::parseRPN("x 0 +");
    std::cout << "x + 0 -> " << expr8->simplify()->toString() << " (x?)" << std::endl;

    auto expr9 = ExpressionParser::parseRPN("0 x +");
    std::cout << "0 + x -> " << expr9->simplify()->toString() << " (x?)" << std::endl;

    auto expr10 = ExpressionParser::parseRPN("x 0 *");
    std::cout << "x * 0 -> " << expr10->simplify()->toString() << " (0?)" << std::endl;

    auto expr11 = ExpressionParser::parseRPN("x 1 *");
    std::cout << "x * 1 -> " << expr11->simplify()->toString() << " (x?)" << std::endl;

    auto expr12 = ExpressionParser::parseRPN("1 x *");
    std::cout << "1 * x -> " << expr12->simplify()->toString() << " (x?)" << std::endl;

    auto expr13 = ExpressionParser::parseRPN("x 1 /");
    std::cout << "x / 1 -> " << expr13->simplify()->toString() << " (x?)" << std::endl;

    auto expr14 = ExpressionParser::parseRPN("0 x -");
    std::cout << "0 - x -> " << expr14->simplify()->toString() << " (-x?)" << std::endl;




    auto expr15 = ExpressionParser::parseRPN("2 3 + 0 + x * 1 *"); // ((2+3)+0)*x*1
    auto simplified15 = expr15->simplify();

    std::cout << "((2 + 3) + 0) * x * 1 ->  (5 * x?) : " << simplified15->toString() << std::endl;
}

