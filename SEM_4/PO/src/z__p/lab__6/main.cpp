/*
Celem zadania jest przećwiczenie przeciążania operatora() oraz std::function.
Proszę napisać klasę List zawierającą zbiór liczb.
W programie będziemy przeprowadzać operacje na
elementach List przy pomocy funkcji i funktorów.
Metoda filter wybiera z Listy elementy spełniające podane kryterium.
Klasa FilterCriteria przechowuje listę różnych kryteriów.
Uwagi:
- zalecane użycie std::vector (szybciej i prościej)
- powinna być tylko 1 wersja funkcji filter
- w funktorach można umieszczać definicje w ciele klasy (są krótkie)
*/

#include "List.h"
#include "FilterCriteria.h"
#include "Functors.h"
#include <iostream>

bool positive(int x)
{
    return x >= 0;
}

int main()
{
    List l1;
    for (int i = 0; i < 8; ++i)
    {
        int sign = i % 2 ? 1 : -1;
        l1.insert(i * sign);
    }
    l1.print("l1: ");
    l1[3] = 10;
    l1.print("l1: ");

    List l2 = l1.filter([](auto elem)
                        { return elem <= 5; });
    l2.print("l2 <= 5: ");
    l2 = l1.filter([](auto elem)
                   { return elem % 2; });
    l2.print("l2 nieparzyste: ");
    const List l3 = l1.filter(positive);
    l3.print("l3 >= 0: ");

    std::cout << "\nTest funktorow\n";
    DivisibleBy divisible(3);
    LowerThan lower(0);
    std::cout << std::boolalpha;
    std::cout << "Czy (9 % 3 == 0)? " << divisible(9) << std::endl;
    std::cout << "Czy (9 < 0)? " << lower(9) << std::endl;

    l2 = l1.filter(LowerThan(-2));
    l2.print("l2 < -2: ");
    l2 = l1.filter(lower);
    l2.print("l2 > 0: ");
    l2 = l1.filter(DivisibleBy(5));
    l2.print("l2 % 5 == 0: ");
    l2 = l1.filter(divisible);
    l2.print("l2 % 3 == 0: ");

    std::cout << "\nTest listy kryteriow\n";
    FilterCriteria criteria;
    criteria.add(lower);
    criteria.add(divisible);
    criteria.add(positive);

    for (int i = 0; i < criteria.size(); ++i)
    {
        l1.filter(criteria.get(i)).print();
    }
}

/* oczekiwany output
./main
l1:  [ 0 1 -2 3 -4 5 -6 7 ]
l1:  [ 0 1 -2 10 -4 5 -6 7 ]
l2 <= 5:  [ 0 1 -2 -4 5 -6 ]
l2 nieparzyste:  [ 1 5 7 ]
l3 >= 0:  [ 0 1 10 5 7 ]
Test funktorow
Czy (9 % 3 == 0)? true
Czy (9 < 0)? false
l2 < -2:  [ -4 -6 ]
l2 > 0:  [ -2 -4 -6 ]
l2 % 5 == 0:  [ 0 10 5 ]
l2 % 3 == 0:  [ 0 -6 ]
Test listy kryteriow
[ -2 -4 -6 ]
[ 0 -6 ]
[ 0 1 10 5 7 ]
*/