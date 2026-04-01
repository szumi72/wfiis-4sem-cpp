#include "TileMap.h"
#include "TileMapView.h"

#include <iostream>

int main() {

    TileMap tile_map(4, 4);    
    for (int row = 0; row < 4; ++row) {
        for (int column = 0; column < 4; ++column) {

            bool near_river = (row % 2 == 0);
            bool sea_access = (row % 2 == 1);
            bool has_forest = (column % 2 == 0);
            bool has_road = (column % 2 == 1);

            tile_map(row, column) = Tile(near_river,sea_access,has_forest,has_road,false,hills);
           
        }
    }


    std::cout << "Test implementacji TileMap" << std::endl;
    std::cout << "Operatory dostępu i mapowanie (powinno być true): "
        << ((tile_map[2] == tile_map(0, 2)) || (tile_map[2] == tile_map(2, 0))) << std::endl; 

    const TileMap const_tile_map = tile_map;
    std::cout << "Operatory dostępu (const) (powinno być true): " 
        << ((const_tile_map[2] == const_tile_map(0, 2)) || (const_tile_map[2] == const_tile_map(2, 0))) << std::endl; 

    TileMapView entire_map_view = tile_map.createView();
    TileMapView map_view = tile_map.createView(1, 2, 2, 3);

    std::cout << "Test implementacji TileMapView" << std::endl;
    std::cout << "Test zakresu i offsetów (powinny być true): " 
        << (tile_map(1, 2) == map_view(0, 0)) << ", " 
        << (tile_map(2, 3) == map_view(1, 1)) << ", " 
        << (tile_map(0, 0) == entire_map_view(0, 0))  << ", " 
        << (tile_map(3, 3) == entire_map_view(3, 3)) 
        << std::endl;

   
    std::cout << "Operatory dostępu i mapowanie (powinno być true): "
        << ((map_view[1] == map_view(0, 1)) || (map_view[1] == map_view(1, 0))) << std::endl; 
    const TileMapView const_map_view = map_view;
    std::cout << "Operatory dostępu (const) (powinno być true): " 
        << ((const_map_view[1] == const_map_view(0, 1)) || (const_map_view[1] == const_map_view(1, 0))) << std::endl; 

    std::cout << "Przed zmianą mapy (powinno być true): " << (tile_map(1, 2) == map_view(0, 0)) << std::endl;

    tile_map(1, 2) = tile_map(3, 3); 

    std::cout << "Po zmianie (powinno być true): " << (tile_map(1, 2) == map_view(0, 0)) << std::endl;



    std::cout << "Test granic iteratora:" << std::endl;
    auto first = map_view.begin();
    auto last = map_view.end();
    --last;

    std::cout << "Początek: " << (*first == map_view(0, 0)) << std::endl;
    std::cout << "Koniec: " << (*last == map_view(1, 1)) << std::endl;
     

    std::cout << "Wypisanie z użyciem iteratora" << std::endl;
    int count = 0;
    for(auto tile_it = map_view.begin(); tile_it != map_view.end(); ++tile_it) {
        std::cout << *tile_it << std::endl;
        ++count;
    }
    std::cout << "Ilość wypisanych elementów (powinny być 4): " << count << std::endl;


    return 0;
}

