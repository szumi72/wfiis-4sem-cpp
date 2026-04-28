

#include <iostream>

#include "Tensor.h"

int main() {

    Tensor t({2, 3, 4}, true); // wymiary + zerowanie pamięci

    std::cout << "Przypisanie i dostęp przez operator()\n" << std::endl;
    t({1, 2, 3}) = 42;
    std::cout << "t({1, 2, 3}) = 42: " <<  t({1, 2, 3}) << std::endl;

    // Wypełnienie całej pamięci wzorem
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            for (size_t k = 0; k < 4; ++k) {
                t({i,j,k}) = i * 100 + j * 10 + k;
            }
        }
    }


    std::cout << "\n\nTest wypełnienia\n" << std::endl;
    std::cout << "Powinniśmy zobaczyć (z dowolnym formatowaniem :)):" << std::endl;
    std::cout << "wymiary - 2, 3, 4" << std::endl;
    std::cout << "stridy - 12, 4, 1" << std::endl;
    std::cout << "dane (pionowe kreski oznaczają stridy, pomijając ten jednostkowy):" << std::endl;
    std::cout << "| |000, 001, 002, 003|, |010, 011, 012, 013|, |020, 021, 022, 023| |" << std::endl;
    std::cout << "| |100, 101, 102, 103|, |110, 111, 112, 113|, |120, 121, 122, 123| |" << std::endl;
    std::cout << "\n\nTest printDebugInfo()\n" << std::endl;

    t.printDebugInfo();


    std::cout << "\n\nTest widoku\n" << std::endl;
    std::cout << "Utworzenie, wypisanie i nadpisanie przez widok (jedna redukcja)" << std::endl;

    auto t_view2D = t[1];
    std::cout << "t_view2D({2, 3}) = 100 + 20 + 3 = 123? : " << t_view2D({2, 3}) << std::endl;
    
    t_view2D({2, 3}) = 24;
    std::cout << "t_view2D({2, 3}) = 24? : " << t_view2D({2, 3}) << std::endl;
    std::cout << "t({1, 2, 3}) = 24? : " << t({1, 2, 3}) << std::endl;

    
    std::cout << "\n\nTest widoku - redukcja do 1 wymiaru\n" << std::endl;

     auto t_view1D = t[1][2];
    

     std::cout << "t_view1D({1}) = 100 + 20 + 1 = 121? : " << t_view1D({1}) << std::endl;
     std::cout << "t_view1D(1) = 100 + 20 + 1 = 121? : " << t_view1D(1) << std::endl;

    t_view1D(1) = 42;
    std::cout << "t_view1D(1) = 42? : " << t_view1D(1) << std::endl;
    std::cout << "t({1, 2, 1}) = 42? : " << t({1, 2, 1}) << std::endl;


    std::cout << "\n\nTest konwersji widoku na tensor 2D\n" << std::endl;

    auto t_2D_from_view = t[0].asTensor(); 
    std::cout << "Powinniśmy zobaczyć (z dowolnym formatowaniem :)):" << std::endl;
    std::cout << "wymiary - 3, 4" << std::endl;
    std::cout << "stridy - 4, 1" << std::endl;
    std::cout << "dane (pionowe kreski oznaczają stridy, pomijając ten jednostkowy):" << std::endl;
    std::cout << "| |000, 001, 002, 003|, |010, 011, 012, 013|, |020, 021, 022, 023| |" << std::endl;
    std::cout << "\n\nprintDebugInfo()\n" << std::endl;
    t_2D_from_view.printDebugInfo();


    std::cout << "\n\nTest konwersji widoku na tensor 1D\n" << std::endl;
    auto t_1D_from_view = t[0][1].asTensor();
    std::cout << "Powinniśmy zobaczyć (z dowolnym formatowaniem :)):" << std::endl;
    std::cout << "wymiary - 4" << std::endl;
    std::cout << "stridy - 1" << std::endl;
    std::cout << "dane: 010, 011, 012, 013" << std::endl;
    std::cout << "\n\nprintDebugInfo()\n" << std::endl;
    t_1D_from_view.printDebugInfo();

}


