#include "BinaryOperator.h"
#include "Constant.h"
#include "UnaryOperator.h"
#include <iostream>

BinaryOperator::BinaryOperator(std::string o) : operator_(o) {}
double BinaryOperator::eval()
{
    if (leftChild_ && rightChild_)
    {
        if (operator_ == "+")
            return (leftChild_->eval() + rightChild_->eval());
        if (operator_ == "-")
            return (leftChild_->eval() - rightChild_->eval());
        if (operator_ == "/")
            return (leftChild_->eval() / rightChild_->eval());
        if (operator_ == "*")
            return (leftChild_->eval() * rightChild_->eval());
    }
    else
    {
        std::cout << "BinaryOperator's child is null" << std::endl;
    }
    return 0;
}

double BinaryOperator::eval(const Context &c)
{
    if (leftChild_ && rightChild_)
    {
        if (operator_ == "+")
            return (leftChild_->eval(c) + rightChild_->eval(c));
        if (operator_ == "-")
            return (leftChild_->eval(c) - rightChild_->eval(c));
        if (operator_ == "/")
            return (leftChild_->eval(c) / rightChild_->eval(c));
        if (operator_ == "*")
            return (leftChild_->eval(c) * rightChild_->eval(c));
    }
    else
    {
        std::cout << "BinaryOperator's child is null" << std::endl;
    }
    return 0;
}

Expression &BinaryOperator::operator[](int k)
{
    if (k == 0)
    {
        return *leftChild_;
    }
    if (k == 1)
    {
        return *rightChild_;
    }
    else
    {
        return *this;
    }
}

const Expression &BinaryOperator::operator[](int k) const
{
    if (k == 0)
    {
        return *leftChild_;
    }
    if (k == 1)
    {
        return *rightChild_;
    }
    else
    {
        return *this;
    }
}

void BinaryOperator::addLeftChild(std::unique_ptr<Expression> ptr)
{
    leftChild_ = std::move(ptr);
}
void BinaryOperator::addRightChild(std::unique_ptr<Expression> ptr)
{
    rightChild_ = std::move(ptr);
}

std::string BinaryOperator::toString()const{
    return "("+leftChild_->toString()+" "+ operator_ + " " + rightChild_->toString()+")";
    
}

std::unique_ptr<Expression> BinaryOperator::simplify(){
    auto l = leftChild_->simplify();
    auto r = rightChild_->simplify();

    Constant* lp = dynamic_cast<Constant*>(l.get());
    Constant* rp = dynamic_cast<Constant*>(r.get());   
    if (lp && rp) {
        double v1 = lp->eval();
        double v2 = rp->eval();
        if (operator_ == "+") return std::make_unique<Constant>(v1 + v2);
        if (operator_ == "-") return std::make_unique<Constant>(v1 - v2);
        if (operator_ == "*") return std::make_unique<Constant>(v1 * v2);
        if (operator_ == "/") return std::make_unique<Constant>(v1 / v2);
    }
  
    if (operator_ == "+") {
        if (lp && lp->eval() == 0) return r; 
        if (rp && rp->eval() == 0) return l; 
    }

    
    if (operator_ == "-") {
        if (rp && rp->eval() == 0) return l;
        if (lp && lp->eval() == 0) {           
            auto neg = std::make_unique<UnaryOperator>("-");
            neg->addChild(std::move(r));
            return neg;
        }
    }    
    if (operator_ == "*") {
        if (lp && lp->eval() == 0) return std::make_unique<Constant>(0); 
        if (rp && rp->eval() == 0) return std::make_unique<Constant>(0); 
        if (lp && lp->eval() == 1) return r; 
        if (rp && rp->eval() == 1) return l; 
    }    
    if (operator_ == "/") {
        if (rp && rp->eval() == 1) return l;
    }    
    auto newNode = std::make_unique<BinaryOperator>(operator_);
    newNode->addLeftChild(std::move(l));
    newNode->addRightChild(std::move(r));
    return newNode;
}
