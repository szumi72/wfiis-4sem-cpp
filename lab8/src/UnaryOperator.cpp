#include "UnaryOperator.h"
#include "Constant.h"
#include<iostream>

UnaryOperator::UnaryOperator(std::string o):operator_(o){}    
double UnaryOperator::eval(){
    if(operator_ == "~" )return ((-1)*(child_->eval()));
    return 0;
}
    
double UnaryOperator::eval(const Context& c){
    if(operator_ == "~" )return ((-1)*(child_->eval(c)));
    return 0;
}
    
Expression& UnaryOperator::operator[](int ){
    return *child_;
}
    
const Expression& UnaryOperator::operator[](int )const{
    return *child_;
}
   
void UnaryOperator::addChild(std::unique_ptr<Expression> ptr){
    child_ = std::move(ptr);
}

std::string UnaryOperator::toString()const{
    return "(-"+ child_->toString() + ")";
}

std::unique_ptr<Expression> UnaryOperator::simplify(){

    auto c= child_->simplify();
    Constant* ptr = dynamic_cast<Constant*>(c.get());
    if(ptr){
        return std::make_unique<Constant>(this->eval());
    }

    auto newNode = std::make_unique<UnaryOperator>(operator_);
    newNode->addChild(std::move(c));
    return newNode;
}
    