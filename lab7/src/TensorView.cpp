#include "TensorView.h"
#include "Tensor.h"


TensorView::TensorView(Tensor* ten,std::vector<int> ofst):tensorData(ten),baseIndex(ofst){
    for(int i=ofst.size();i<ten->getDims().size();i++){
        dims.push_back(ten->getDims()[i]);
    }
}
int& TensorView::operator()(std::vector<int> v){
    if(v.size()==1){
        return (*this)(v[0]);
    }
    std::vector<int> v2;
    v2.resize(v.size()+baseIndex.size());
    int i=0;
    for(i;i<baseIndex.size();i++){
        v2[i]=baseIndex[i];
    }
    
    for(int j = 0; j < v.size(); j++){
        v2[baseIndex.size() + j] = v[j];
    }

    
    return (*tensorData)(v2);
}
const int& TensorView::operator()(std::vector<int> v)const{
    if(v.size()==1){
        return (*this)(v[0]);
    }
    std::vector<int> v2;
    v2.resize(v.size()+baseIndex.size());
    int i=0;
    for(i;i<baseIndex.size();i++){
        v2[i]=baseIndex[i];
    }    
    for(int j = 0; j < v.size(); j++){
        v2[baseIndex.size() + j] = v[j];
    }

    
    return (*tensorData)(v2);
}

TensorView TensorView::operator[](int k){
    auto newBase = baseIndex;
    newBase.push_back(k);
    return TensorView(tensorData, newBase);
    
}

int& TensorView::operator()(int k){
    std::vector<int> idx;
    idx = baseIndex;
    idx.push_back(k);
    return (*tensorData)(idx);
}

const int& TensorView::operator()(int k)const{
    std::vector<int> idx;
    idx = baseIndex;
    idx.push_back(k);
    return (*tensorData)(idx);
}

Tensor TensorView::asTensor(){
   Tensor result(dims, false);

    std::vector<int> current(dims.size(), 0);

    int total = 1;
    for(int d : dims) total *= d;

    for(int i = 0; i < total; i++){

        std::vector<int> full = baseIndex;
        full.insert(full.end(), current.begin(), current.end());

        result(current) = (*tensorData)(full);

        
        for(int j = dims.size() - 1; j >= 0; j--){
            current[j]++;
            if(current[j] < dims[j]) break;
            current[j] = 0;
        }
    }

    return result;
 }
