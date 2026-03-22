#ifndef IMAGE_H
#define IMAGE_H
#include <vector>
#include <iostream>

struct Pixel{
    int r=0,g=0,b=0,a=0;
    Pixel()=default;    
    
    friend std::ostream& operator<<(std::ostream& o, const Pixel& p){
        return o<<" {"<<p.r<<" "<<p.g<<" "<<p.b<<" "<<p.a<<"} ";
    }
    
    Pixel& operator+=(const Pixel& other){        
        r = r+other.r;
        b=b+other.b;
        g = g+other.g;
        a = a+other.a;
        return (*this);
    }    
    Pixel operator+(const Pixel& other) const{
        Pixel temp = (*this);
        temp += other;        
        return temp;
    } 
    Pixel& operator-=(const Pixel& other){        
        r = r-other.r;
        b=b-other.b;
        g = g-other.g;
        a = a-other.a;
        return (*this);
    }
    Pixel operator-(const Pixel& other)const{
        Pixel temp = (*this);
        temp -= other;
        return temp;
    }    
     Pixel& operator*=(float f){        
        r = r*f;
        b = b*f;
        g = g*f;
        a = a*f;
        return (*this);
    }    
    Pixel operator*(float f) const{
        Pixel temp = (*this);
        temp *=f;        
        return temp;
    }
    bool operator==(const Pixel& other)const{
        bool flag=false;
        if(r==other.r && g== other.g && b==other.b && a==other.a){
            flag=true;
        }
        return flag;
    }
};

class Image{
public:
    Image(int a,int b):_height(a),_width(b),_data(a*b, Pixel()){}
    Image(const Image& other){
        _width=other._width;
        _height=other._height;
        _data = other._data;       
    }

    ~Image(){}
    Pixel& operator()(int x,int y){
        return _data[x*_width + y];
    }

    Pixel operator()(int y, int x) const {
        return _data[y * _width + x];
    }

    bool operator==(const Image& other)const{       
        if(_width != other._width || _height != other._height){
            return false;
        }
        for(int i=0;i<_height*_width;i++){ 
            if(_data[i] == other._data[i]){

            }
            else{
                return false;
            }        
                                 
        }
        return true;
    }

    Image& operator=(const Image& other){
        if(this==&other){
            return (*this);
        }
        _width = other._width;
        _height = other._height;
        _data = other._data;
        return (*this);
    }

    Image& operator+=(const Image& image){        
        for(int i=0;i<image._height*image._width;i++){            
            _data[i] += image._data[i];                      
        }      
        return (*this);
    }

    Image operator+(const Image& image)const{
        Image temp = (*this);
        temp+=image;        
        return temp;
    }

    Image& operator-=(const Image& image){        
        for(int i=0;i<image._height*image._width;i++){            
            _data[i] -= image._data[i];                      
        }
        return (*this);
    }
    Image operator-(const Image& image)const{
        Image temp = (*this);
        temp-=image;        
        return temp;
    }    
    Image& operator*=(float f){        
        for(int i=0;i<_height*_width;i++){            
            _data[i] *= f ;                      
        }
        return (*this);
    }
    
    Image operator*(float f)const{
        Image temp = (*this);
        temp*=f;        
        return temp;
    }
    Image operator|(const Image& other)const{
      
        int newH = _height > other._height? _height : other._height;
        int newW = _width + other._width;
    
        Image temp(newH, newW);    
        for (int y = 0; y < newH; ++y) {
            for (int x = 0; x < newW; ++x) {
                
                if (x < _width) {                
                    if (y < _height) {
                        temp(y, x) = (*this)(y, x);
                    }
                } else {               
                    int otherX = x - _width;
                    if (y < other._height) {
                        temp(y, x) = other(y, otherX);
                    }
                }
            }
        }
        return temp;
    }
    Image& operator|=(const Image& other) {        
        Image temp = (*this) | other;        
        this->_data = temp._data;
        this->_width = temp._width;
        this->_height = temp._height;        
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Image& image){
        for(int i=0;i<image._height;i++){
            for(int j=0;j<image._width;j++){
                os<<image._data[i*image._width+j];
            }
            os<<std::endl;
        }
        return os;
    }

private:
    int _height;
    int _width;     
    std::vector<Pixel> _data;

};


#endif