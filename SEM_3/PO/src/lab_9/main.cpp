/*
Zdefiniuj klasę Point przechowującą współrzędne punktu oraz jego nazwę. Pole nazwy może być typu std::string, by uniknąć alokacji pamięci.
Zdefiniuj wszystkie potrzebne konstruktory i metody.
* W zadaniu mamy dwa kontruktory nazwane - setPoint ustawia współrzędne (x,y), setContrary ustawia współrzędne na przeciwne (-x,-y). Z uwagi na te same argumenty w obu przypadkach, nie możemy tego zrobić zwykłymi konstruktorami. 
* Każdy powstający obiekt jest numerowany od 1
* fullPrint - drukuje obiekt w postaci: 
  Nr_objektu. name (x, y) 
* changeName zmienia nazwę istniejącego obiektu
* Wszystkie pola i metody oraz konstruktory w klasie nie wywoływane jawnie w main.cpp są prywatne (chodzi o konstruktory pomocnicze dla konstruktorów nazwanych)
* Za brak stosowania list inicjalizacyjnych oraz konstruktorów przenoszących i delegowanych będą odejmowane punkty. W tym zadaniu jakość i przejrzystość kodu jest bardzo ważna. 
* Zarówno w pliku h jak i cpp należy grupować i oddzielać konemtarzem kosktruktory, gettery, pozostałe funkcje.

Ponadto zdefiniuj funkcje (zadanie dostępne po odkomentowaniu definicji EKTRA w CMakeLists.txt albo Makefile)
  - compareX, compareY - porównującą p1 i p2 i zwracającą:
   * wartość dodatnią (np 1) dla porządku rosnącego,
   * zero dla równych wartości,
   * wartość ujemną (np -1) dla porządku malejącego.
  - directions - przyjmującą jako argument wskaźnik do funkcji z rodziny compare, wypisującą odpowiedni tekst zgodnie z outputem. 
     Wykorzystaj case zamiast zagnieżdżonego if.


 * Pliku main.cpp, NIE WOLNO modyfikować bez zgody prowadzącego.
 * Proszę pamiętać o dokumentacji kodu (doxygen)
*/

#include "Point.h"
#include <iostream>

int main()
{
  {
    std::cout << "\n****** Konstruktory ETAP 1 *****\n";
    Point krakow("Krakow", 19.938333, 50.0614), //x=długość,y=szerokość
        tarnow("Tarnow", 20.9889, 50.0139),
        poznan("Poznan", 16.9211, 52.4144),
        zielonki("Zielonki", 19.938333, 50.118611),
        nyc("Nowy Jork", -74.0059, 40.7127),
        pusty;

    krakow.fullPrint();
    tarnow.fullPrint();
    poznan.fullPrint();
    zielonki.fullPrint();
    nyc.fullPrint();
    pusty.fullPrint();

    std::cout << "\n****** Konstruktory ETAP 2 *****\n";
    const double x = 20.259722, y = 50.0614;
    Point noname1 = Point::setPoint(x, y);
    const Point noname2 = Point::setContrary(23.0124, 45.4523);
    noname1.fullPrint();
    noname2.fullPrint();

    noname1.changeName("Wola Batorska");
    noname1.fullPrint();
    Point batorska = noname1;
    batorska.fullPrint();

    Point moved = pusty.newMoved("New Moved", -50, -30);
    moved.fullPrint();
    Point nowy1 = std::move(moved);
    nowy1.fullPrint();
    moved.fullPrint();

    Point kopia = std::move(pusty.newMoved("Nowe Miasto", -50, -30));
    kopia.fullPrint();
    std::move(Point::setContrary(x, y)).fullPrint();
    const Point nowy2(std::move(Point::setContrary(x, y)));
    nowy2.fullPrint();

// Zadanie dodatkowe, jeśli starczy czasu albo do domu
#ifdef EKSTRA
    std::cout << "\n****** Etap EKSTRA *****\n";
    std::cout << "compareX=" << compareX(poznan, krakow) << " compareY=" << compareY(poznan, krakow) << std::endl;
    directions(poznan, krakow, compareX); //compareX, compareY to wskaźniki funkcyjne
    directions(poznan, krakow, compareY);

    std::cout << "compareX=" << compareX(tarnow, krakow) << " compareY=" << compareY(tarnow, krakow) << std::endl;
    directions(tarnow, krakow, compareX);
    directions(tarnow, krakow, compareY);

    std::cout << "compareX=" << compareX(poznan, nyc) << " compareY=" << compareY(poznan, nyc) << std::endl;
    directions(poznan, nyc, compareX);
    directions(poznan, nyc, compareY);

    std::cout << "compareX=" << compareX(nyc, krakow) << " compareY=" << compareY(nyc, krakow) << std::endl;
    directions(nyc, krakow, compareX);
    directions(nyc, krakow, compareY);

    std::cout << "compareX=" << compareX(krakow, zielonki) << " compareY=" << compareY(krakow, zielonki) << std::endl;
    directions(krakow, zielonki, compareX);
    directions(krakow, zielonki, compareY);

    std::cout << "compareX=" << compareX(krakow, batorska) << " compareY=" << compareY(krakow, batorska) << std::endl;
    directions(krakow, batorska, compareX);
    directions(krakow, batorska, compareY);
#endif

    std::cout << "\n***** Podsumowanie *****\n";
    std::cout << "Liczba obiektow: " << Point::number << std::endl;
  }

  std::cout << "--- Czyszczenie\n";
  std::cout << "Liczba obiektow: " << Point::number << std::endl;

  return 0;
}

/* Oczekiwany wynik:

****** Konstruktory ETAP 1 *****
1. Krakow (19.9383,50.0614)
2. Tarnow (20.9889,50.0139)
3. Poznan (16.9211,52.4144)
4. Zielonki (19.9383,50.1186)
5. Nowy Jork (-74.0059,40.7127)
6.  (0,0)

****** Konstruktory ETAP 2 *****
7. Punkt X (20.2597,50.0614)
8. Punkt X (-23.0124,-45.4523)
7. Wola Batorska (20.2597,50.0614)
--- Kopiujemy 7. Wola Batorska
9. Wola Batorska (20.2597,50.0614)
10. New Moved (-50,-30)
--- Przenosimy 10. New Moved
11. New Moved (-50,-30)
10.  (0,0)
--- Przenosimy 12. Nowe Miasto
13. Nowe Miasto (-50,-30)
13. Punkt X (-20.2597,-50.0614)

***** Podsumowanie *****
Liczba obiektow: 12
--- Czyszczenie
Liczba obiektow: 0


WERSJA EKSTRA
****** Etap EKSTRA *****
compareX=1 compareY=-1
Poznan - na zach. od Krakow
Poznan - na pn. od Krakow
compareX=-1 compareY=1
Tarnow - na wsch. od Krakow
Tarnow - na pd. od Krakow
compareX=-1 compareY=-1
Poznan - na wsch. od Nowy Jork
Poznan - na pn. od Nowy Jork
compareX=1 compareY=1
Nowy Jork - na zach. od Krakow
Nowy Jork - na pd. od Krakow
compareX=0 compareY=1
Krakow - na tej samej długości co Zielonki
Krakow - na pd. od Zielonki
compareX=1 compareY=0
Krakow - na zach. od Wola Batorska
Krakow - na tej samej szerokości co Wola Batorska
*/