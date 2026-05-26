#pragma once
#include<vector>
#include<functional>
#include<memory>
#include<iostream>

namespace Iterators{


//klasa obslugijaca reansformacje na vectorze
class VectorIterator{
public:
    VectorIterator(std::vector<int> v):data(v),takeParam(data.size()){      
    
    }

    //funkcja wywolujaca wszystkie dodane operacje na wektorze
    std::vector<int> collect(){
        std::vector<int> result;
        if(takeParam>data.size() || takeParam<=0){
            takeParam=data.size();
        }
        result.reserve(takeParam);
        for(size_t i=0;i<data.size();i++){
            bool ok=true;            
            for(auto& fun:filters){
                if(!fun(data[i])){
                    ok=false;
                    break;
                }               
            }
            if(ok==true){
                result.push_back(data[i]);  
                for(auto& map:maps){
                    result[result.size()-1] = (map(result[result.size()-1]));
                }              
            }  
            if(result.size()==takeParam){
                
                return result;
            }         
        }

        filters.clear();        
        maps.clear();       

        

        return result;
    }


    //dodaje filter do operacji do wykonania
    VectorIterator& filter(std::function<bool(int)> pred){
        fcount++;
        if(fcount > 5){
            std::cout<<"Za duzo filtrów, filter nie jest dodawany\n";
            fcount--;
            return (*this);
        }
        filters.emplace_back(pred);
        
        return (*this);
    }

    //dodaje map do operacji do wykonania
    VectorIterator& map(std::function<int(int)> map){
        mcount++;
        if(mcount > 5){
            std::cout<<"Za duzo map, mapa nie jest dodawana\n";
            mcount--;
            return (*this);
        }
        maps.emplace_back(map);
        return (*this);
    }

    //okresla ile parametrów mozna wziać
    VectorIterator& take(int k){
        
        takeParam=std::min(k,takeParam);
        //std::cout<<takeParam<<" "<<k<<"dddd\n";
        return (*this);
    }

private:
    std::vector<std::function<bool(int)>> filters;
    int fcount=0;
    std::vector<std::function<int(int)>> maps;
    int mcount=0;
    std::vector<int>& data;
    int takeParam;
};



}//Iterators