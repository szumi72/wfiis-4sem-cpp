
#include <iostream>

#include "Querying.h"

int main() {

    std::vector<int> data = {5, 10, 15, 20, 25, 30, 50};

    Querying::CompositeQuery queries(5 /*pre-alocation size hint*/);
    queries.addQuery(std::make_unique<Querying::Simple::GreaterThan>(10));
    queries.addQuery(std::make_unique<Querying::Simple::LessThan>(30));


    std::cout << "Oryginał (10 < x < 30):\n";
    std::vector<int> result1 = Querying::filter(data, queries);

    std::cout << "Oczekujemy 15, 20 i 25.\n";
    for(auto const& r : result1)
        std::cout << r << "\n";


    std::cout << "Kopia ((10 < x < 30) && (x & 1) == 0 :)):\n";
    Querying::CompositeQuery queries_copy = queries;
    queries_copy.addQuery(std::make_unique<Querying::Simple::IsEven>());

    std::vector<int> result2 = Querying::filter(data, queries_copy);

    std::cout << "Oczekujemy 20.\n";
    for(auto const& r : result2)
        std::cout << r << "\n";


    std::cout << "Powtórka oryginału, cross-check:\n";
    std::vector<int> result3 = Querying::filter(data, queries);

    std::cout << "Oczekujemy 15, 20 i 25.\n";
    for(auto const& r : result3)
        std::cout << r << "\n";    

   

    std::cout << "x != 20:\n";
    Querying::CompositeQuery not_query;
    not_query.addQuery(std::make_unique<Querying::Simple::NotQuery>(new Querying::Simple::EqualTo(20)));

    std::vector<int> not_result = Querying::filter(data, not_query);

    std::cout << "Oczekujemy 5, 10, 15, 25, 30, 50.\n";
    for(auto const& r : not_result)
        std::cout << r << "\n";    


    return 0;
}

