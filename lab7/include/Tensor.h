#pragma once
#include <vector>
#include<iostream>
#include "TensorView.h"

// class TensorView;

class Tensor{
public:
    Tensor(std::vector<int> params,bool flag);

    int getIndex(const std::vector<int>& val)const;

    int& operator()(std::vector<int> values);
    const int& operator()(std::vector<int> values)const;

    int& operator()(int k);
    const int& operator()(int k)const;
    void printDebugInfo();
    TensorView operator[](int k);
    std::vector<int> getDims();
private:
    std::vector<int> dims;
    std::vector<int> strides;
    std::vector<int> data;
};