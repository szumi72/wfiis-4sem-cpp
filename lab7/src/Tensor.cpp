#include "Tensor.h"
#include "TensorView.h"

Tensor::Tensor(std::vector<int> params,bool flag):dims(params){
        int sum=1;
        for(auto t: dims){
            sum*=t;
            
        }
        data.resize(sum);

        if(flag){
            for(size_t i=0;i<data.size();i++){
                data[i] = 0;
            
            }
        }

        strides.resize(dims.size());        
        strides[strides.size()-1]=1;
        for(int i=(strides.size()-2);i>=0;i--){
            strides[i]=strides[i+1]*dims[i+1];
        }        
    }

    int Tensor::getIndex(const std::vector<int>& val)const{
        int idx = 0;
        for(int i=0;i<val.size();i++){
            idx += val[i] * strides[i];
        }
        return idx;
    }

    int& Tensor::operator()(std::vector<int> values){
        return data[getIndex(values)];
    }

    const int& Tensor::operator()(std::vector<int> values)const{
        return data[getIndex(values)];
    }

    int& Tensor::operator()(int k){
        return data[k];
    }

    const int& Tensor::operator()(int k)const{
        return data[k];
    }

    void Tensor::printDebugInfo(){
        
        std::cout<<"\ndims: ";
        for(size_t i=0;i<strides.size();i++){
            std::cout<<dims[i]<<" ";
        }
        std::cout<<"\nstrides: ";
        for(size_t i=0;i<strides.size();i++){
            std::cout<<strides[i]<<" ";
        }
        std::cout<<"\ndata: ";
        for(int d:data){
            std::cout<<d<<" ";
        }
        std::cout<<"\n";
    }

    TensorView Tensor::operator[](int k){
        
        return TensorView(this,std::vector<int>{k});
    }
    std::vector<int> Tensor::getDims(){
        return dims;
    }