
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "ComparatorBuilder.h" 
int main() {

   
    // Testy poszczególnych komparatorów

    {
        CaseInsensitiveLess cmp;

        std::cout << cmp("mario", "Zelda") << " (oczekiwane: 1)\n";
        std::cout << cmp("Zelda", "mario") << " (oczekiwane: 0)\n";
        std::cout << cmp("Mario", "mario") << " (oczekiwane: 0)\n";
    }

    {
        CaseSensitiveLess cmp;

        std::cout << cmp("Mario", "mario") << " (oczekiwane: 1)\n";
        std::cout << cmp("mario", "Mario") << " (oczekiwane: 0)\n";
    }

    {
        LengthLess cmp;

        std::cout << cmp("Link", "Zelda") << " (oczekiwane: 1)\n";
        std::cout << cmp("Zelda", "Link") << " (oczekiwane: 0)\n";
        std::cout << cmp("Link", "link") << " (oczekiwane: 0)\n";
    }

    // Test komparatora z dekoratorem

    {
        CaseInsensitiveLess base;
        IgnorePrefixComparator cmp(base, "The ");

        std::cout << cmp("The Witcher", "Zelda") << " (oczekiwane: 1)\n";
        std::cout << cmp("Zelda", "The Witcher") << " (oczekiwane: 0)\n";
        std::cout << cmp("The Witcher", "the witcher") << " (oczekiwane: 0)\n";
    }

    
    // Test złożenia komparatorów

    {
        CaseInsensitiveLess ci;
        CaseSensitiveLess cs;
        LengthLess len;

        CompositeComparator cmp;
        cmp.add(&ci);
        cmp.add(&cs);
        cmp.add(&len);

        std::cout << cmp("mario", "Mario") << " (oczekiwane: 0)\n";
        std::cout << cmp("Mario", "mario") << " (oczekiwane: 1)\n";
        std::cout << cmp("Link", "link") << " (oczekiwane: 1)\n";
    }


    // I w końcu builder
    
    {
        std::vector<std::string> names = {
            "Zelda", "mario", "Link", "kirby", "Bowser",
            "link", "Mario", "The Witcher", "the witcher" 
        };


   

         ComparatorBuilder builder;  
        auto cmp = builder
            .caseInsensitive()
            .thenCaseSensitive()
            .thenByLength()
            .ignorePrefix("The ")   
            .build();

    //     /////////////////////////////////////////////////////////


        std::sort(names.begin(), names.end(), cmp);

        std::cout << "\nPosortowane:\n";
        for (const auto& n : names)
            std::cout << n << "\n";


        std::cout << "\nOczekiwana kolejność:\n";
        std::cout << "Bowser\n";
        std::cout << "kirby\n";
        std::cout << "Link\n";
        std::cout << "link\n";
        std::cout << "Mario\n";
        std::cout << "mario\n";
        std::cout << "The Witcher\n";
        std::cout << "the witcher\n";
        std::cout << "Zelda\n";
    }

    return 0;
}

