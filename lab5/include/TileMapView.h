#ifndef TILEMAPVIEW_H
#define TILEMAPVIEW_H
#include<vector>

class TileMap;
struct Tile;

/**
 * @brief Widok na fragment mapy TileMap.
 *
 * Nie przechowuje kopii danych, a jedynie referencję do mapy źródłowej.
 * Umożliwia dostęp do wybranego obszaru mapy z użyciem lokalnych współrzędnych.
 */
class TileMapView{
public:
    TileMapView()=default;
    TileMapView(TileMap& fromMap,int x1,int x2,int y1,int y2): _map(fromMap),offsetX1(x1),offsetX2(x2),offsetY1(y1),offsetY2(y2){}

    /**
     * @brief Dostęp do kratki w widoku poprzez indeks liniowy.
     *
     * @param x Indeks elementu
     * @return Referencja do kratki w mapie
     */
    Tile& operator[](int x);
    const Tile& operator[](int x)const;

    /**
     * @brief Dostęp do kratki w widoku poprzez lokalne współrzędne.
     *
     * @param x Współrzędna pozioma (lokalna)
     * @param y Współrzędna pionowa (lokalna)
     * @return Referencja do kratki w mapie
     */
    Tile& operator()(int x, int y);
    const Tile& operator()(int x, int y)const;   
    
    /**
     * @brief Iterator umożliwiający liniowe przechodzenie po widoku mapy.
     *
     * Iteruje po elementach widoku w sposób wierszami (row-major).
     * Nie przechowuje kopii danych, operuje bezpośrednio na widoku.
     */
    class Iterator{
    public:
        Iterator(TileMapView* v,int x, int y):_view(v),_currentX(x),_currentY(y){}

        /**
         * @brief Przechodzi do poprzedniego elementu widoku.
         *
         * @return Referencja do iteratora po dekrementacji
         */
        Iterator& operator--(){            
            int width = (_view->offsetX2-_view->offsetX1+1);
            _currentX--;
            if (_currentX < 0) {
                _currentX = width - 1;
                _currentY--;
            }
            return *this;
        }

        /**
         * @brief Przechodzi do następnego elementu widoku.
         *
         * @return Referencja do iteratora po inkrementacji
         */
        Iterator& operator++(){ 
            int width = (_view->offsetX2-_view->offsetX1+1);
            _currentX++;
            if (_currentX == width) {
                _currentX = 0;
                _currentY++;
            }
            return *this;
        }

        /**
         * @brief Dereferencja iteratora.
         *
         * @return Referencja do aktualnej kratki
         */
        Tile& operator*(){
            return (*_view)(_currentX,_currentY);
        }
        const Tile& operator*()const{
            return (*_view)(_currentX,_currentY);
        }

        /**
         * @brief Porównuje dwa iteratory.
         *
         * @param other Drugi iterator
         * @return true jeśli wskazują na ten sam element
         */
        bool operator==(const Iterator& other){
            if(_currentX == other._currentX && _currentY == other._currentY && _view == other._view){
                return true;
            }
            return false;
        }

        bool operator!=(const Iterator& other){
            if(_currentX == other._currentX && _currentY == other._currentY){
                return false;
            }
            return true;
        }

    private:
        TileMapView* _view;
        int _currentX;
        int _currentY;

    };
    /**
     * @brief Zwraca iterator na początek widoku.
     *
     * @return Iterator wskazujący pierwszy element
     */
    Iterator begin(){
        return Iterator(this,0,0);
    }

    /**
     * @brief Zwraca iterator za ostatnim elementem widoku.
     *
     * @return Iterator wskazujący pozycję za końcem
     */
    Iterator end(){
        return Iterator(this,(0),(offsetY2-offsetY1+1));
    }

private:
    TileMap& _map;
    int offsetX1;
    int offsetX2;
    int offsetY1;
    int offsetY2;
    
};

#endif 