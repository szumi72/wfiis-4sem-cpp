
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Image.h"

int main() {

    std::srand(std::time(nullptr));

    Image A(3, 3);
    Image B(3, 3);

    for(int y=0; y<3; y++) {
        for(int x=0; x<3; x++) {
            A(x,y) = {static_cast<unsigned char>(rand() % 256), static_cast<unsigned char>(rand() % 256), static_cast<unsigned char>(rand() % 256), 255};
            B(x,y) = {static_cast<unsigned char>(rand() % 256), static_cast<unsigned char>(rand() % 256), static_cast<unsigned char>(rand() % 256), 255};
        }
    }

    std::cout << "Obraz A:\n" << A << "\n";
    std::cout << "Obraz B:\n" << B << "\n";



    std::cout << "=== Konstruktor kopiujący ===\n";
    Image C = A;
    std::cout << "C jako kopia A:\n" << C << "\n";
    std::cout << "C == A?" << (C == A ? " tak" : " nie") << "\n";

    A(0,0) = {255,0,0,255};
    std::cout << "Po zmianie A(0,0) na czerwony:\n";
    std::cout << "A(0,0): " << A(0,0) << "\n";
    std::cout << "A:\n" << A << "\n";
    std::cout << "C:\n" << C << "\n";    
    std::cout << "C == A?" << (C == A ? " tak" : " nie") << "\n";



    std::cout << "=== Operator kopiujący ===\n";
    Image D(5,5);
    D = B;
    std::cout << "D jako kopia B:\n" << D << "\n";
    std::cout << "D == B?" << (D == B ? " tak" : " nie") << "\n";

    B(0,0) = {255,0,0,255};
    std::cout << "Po zmianie B(0,0) na czerwony:\n";
    std::cout << "B(0,0): " << B(0,0) << "\n";
    std::cout << "B:\n" << B << "\n";
    std::cout << "D:\n" << D << "\n";      
    std::cout << "D == B?" << (D == B ? " tak" : " nie") << "\n";



    std::cout << "=== Test dodawania i odejmowania ===\n";
    Image G = A + B;
    std::cout << "A + B:\n" << G << "\n";

    Image H = A - B;
    std::cout << "A - B:\n" << H << "\n";

    G += H;
    std::cout << "G += H\n" << G << "\n";

    H -= G;
    std::cout << "H -= G\n" << H << "\n";


    std::cout << "=== Test skalowania jasności ===\n";
    Image I = A * 0.5;
    std::cout << "A * 0.5:\n" << I << "\n";

    I *= 5;
    std::cout << "I *= 5:\n" << I << "\n";

    std::cout << "=== Test konkatenacji ===\n";
    Image J = A | B;
    std::cout << "A | B:\n" << J << "\n";
    
    J |= A;
    std::cout << "J |= A\n" << J << "\n";


    return 0;
}

