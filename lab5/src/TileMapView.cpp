#include "TileMapView.h"
#include "TileMap.h"

Tile& TileMapView::operator()(int x, int y){
    return _map(x+offsetX1,y+offsetY1);
}

const Tile& TileMapView::operator()(int x, int y)const{
    return _map(x+offsetX1,y+offsetY1);
}

const Tile& TileMapView::operator[](int x)const{
    int width = offsetX2 - offsetX1 + 1;
    int col = x % width;
    int row = x / width;
    int globalX = col + offsetX1;
    int globalY = row + offsetY1;
    return _map(globalX, globalY);
}

Tile& TileMapView::operator[](int x){
    int width = offsetX2 - offsetX1 + 1;
    int col = x % width;
    int row = x / width;
    int globalX = col + offsetX1;
    int globalY = row + offsetY1;
    return _map(globalX, globalY);
}