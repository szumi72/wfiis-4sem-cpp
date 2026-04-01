#ifndef TILEMAP_H
#define TILEMAP_H
#include<vector>
#include<iostream>
#include "TileMapView.h"

/**
 * @brief Typ terenu dla pojedynczej kratki mapy.
 *
 * Określa podstawowe właściwości terenu, takie jak koszt ruchu
 * oraz możliwość przejścia.
 */
enum FieldType{fields,hills,mountains};

/**
 * @brief Reprezentuje pojedynczą kratkę mapy.
 *
 * Przechowuje informacje o typie terenu oraz dodatkowych cechach,
 * takich jak obecność rzeki, dostęp do morza, las czy droga.
 * Może również zawierać informację o specjalnym obiekcie (np. miasto).
 */
struct Tile{
    Tile()=default;
    /**
     * @brief Konstruktor inicjalizujący dane kratki.
     *
     * @param a Czy kratka znajduje się w pobliżu rzeki
     * @param b Czy kratka ma dostęp do morza
     * @param c Czy kratka jest zalesiona
     * @param d Czy kratka zawiera drogę
     * @param e Czy kratka zawiera dodatkowy obiekt
     * @param m Typ ruchu
     */
    Tile(bool a,bool b,bool c,bool d,bool e,FieldType m):near_river(a),sea_access(b),has_forest(c),has_road(d),addition(e),type((m)){}
    bool near_river;
    bool sea_access;
    bool has_forest;
    bool has_road;
    bool addition;
    FieldType type;
    int getMovementCost() const {
        switch(type) {
            case fields: return 5;
            case hills: return 15;
            case mountains: return 0;
        }
        return 0;
    }    
    /**
     * @brief Porównuje dwie kratki mapy.
     *
     * @param other Druga kratka do porównania
     * @return true jeśli kratki mają identyczne właściwości, false w przeciwnym razie
     */
    bool operator==(const Tile& other)const{
       return near_river == other.near_river &&
       sea_access == other.sea_access &&
       has_forest == other.has_forest &&
       has_road == other.has_road &&
       addition == other.addition;
       
    }
    
};

/**
 * @brief Wypisuje informacje o kratce do strumienia.
 *
 * @param o Strumień wyjściowy
 * @param t Kratka do wypisania
 * @return Referencja do strumienia
 */
inline std::ostream& operator<<(std::ostream& o,const Tile& t){
    return o<<"["<<t.near_river<<","<<t.sea_access<<","<<t.has_forest<<","<<t.has_road<<"]"<<std::endl;        
}


/**
 * @brief Reprezentuje dwuwymiarową mapę złożoną z kratek.
 *
 * Udostępnia dostęp do elementów zarówno poprzez indeks liniowy,
 * jak i współrzędne (x, y). Przechowuje dane w sposób ciągły w pamięci.
 */
class TileMap{
public:
    
    /**
     * @brief Tworzy mapę o zadanych wymiarach.
     *
     * @param x Szerokość mapy
     * @param y Wysokość mapy
     */
    TileMap(int x, int y):_width(x),_length(y){
        map.resize(_width*_length);
    }
    TileMap(const TileMap& other):_width(other._width),_length(other._length){
        map.resize(_width*_length);
    }

    /**
     * @brief Dostęp do kratki poprzez indeks liniowy.
     *
     * @param x Indeks elementu
     * @return Referencja do kratki
     */
    Tile& operator[](int x){
        int y=(x/_width);
        int z = x%_width;
        return map[y*_width+z];
    }
    const Tile& operator[](int x)const{
        int y=(x/_width);
        int z = x%_width;
        return map[y*_width+z];
    }

    /**
     * @brief Dostęp do kratki poprzez współrzędne (x, y).
     *
     * @param x Współrzędna pozioma
     * @param y Współrzędna pionowa
     * @return Referencja do kratki
     */
    Tile& operator()(int x, int y){
        return map[y*_width+x];
    }
    const Tile& operator()(int x, int y)const{
        return map[y*_width+x];
    }
    TileMap& operator=(const TileMap& other){
        _width=other._width;
        _length=other._length;
        map=other.map;
        return *this;
    }

   
    /**
     * @brief Tworzy widok obejmujący całą mapę.
     *
     * @return Obiekt TileMapView reprezentujący całą mapę
     */
    TileMapView createView(){        
        return TileMapView(*this, 0,_width,0,_length);        
    }

    /**
     * @brief Tworzy widok na fragment mapy.
     *
     * Zakresy są inkluzywne (oba końce należą do widoku).
     *
     * @param x1 Minimalna współrzędna X
     * @param x2 Maksymalna współrzędna X
     * @param y1 Minimalna współrzędna Y
     * @param y2 Maksymalna współrzędna Y
     * @return Obiekt TileMapView reprezentujący wycinek mapy
     */
    TileMapView createView(int x1,int x2, int y1, int y2){ 
        
        return TileMapView(*this,x1,x2,y1,y2);  
        
    }
    
public:
    int _width;
    int _length;
    std::vector<Tile> map;
};

#endif