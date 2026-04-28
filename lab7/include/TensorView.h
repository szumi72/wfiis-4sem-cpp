#pragma once
#include <vector>
class Tensor;

class TensorView{
public:
    TensorView(Tensor* ten,std::vector<int> ofst);
    int& operator()(std::vector<int> v);
    const int& operator()(std::vector<int> v)const;
    TensorView operator[](int k);
    int& operator()(int k);
    const int& operator()(int k)const;
    Tensor asTensor();
    
private:
    Tensor* tensorData;
    std::vector<int> dims;
    std::vector<int> baseIndex;
    

};