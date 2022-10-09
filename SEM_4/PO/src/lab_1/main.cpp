/*
Zdefiniuj klasę Point przechowującą współrzędne punktu oraz jego nazwę. Pole nazwy może być typu std::string, by uniknąć alokacji pamięci.
Zdefiniuj wszystkie potrzebne konstruktory i metody.
* W zadaniu mamy dwa konstruktory nazwane - setPoint ustawia współrzędne (x,y), setContrary ustawia współrzędne na przeciwne (-x,-y). Z uwagi na te same argumenty w obu przypadkach, nie możemy tego zrobić zwykłymi konstruktorami. 
* Każdy powstający obiekt jest numerowany od 1
* fullPrint - drukuje obiekt w postaci: 
  Nr_objektu. name (x, y) 
* changeName zmienia nazwę istniejącego obiektu
* newMoved tworzy i zwraca nowy obiekt o podanej nazwie, który przesuwa obiekt o podane współrzędne (UWAGA: nie zmienia obiektu, na którym metoda jest wywoływana)
* Wszystkie pola i metody oraz konstruktory w klasie nie wywoływane jawnie w main.cpp są prywatne (chodzi o konstruktory pomocnicze dla konstruktorów nazwanych)
* Za brak stosowania list inicjalizacyjnych oraz konstruktorów przenoszących i delegowanych w przyszłości będą odejmowane punkty. W tym zadaniu jakość i przejrzystość kodu jest bardzo ważna. 
* Zarówno w pliku h jak i cpp należy grupować i oddzielać komentarzem kosktruktory, gettery, pozostałe funkcje.

 * Pliku main.cpp, NIE WOLNO modyfikować bez zgody prowadzącego.
 * Proszę pamiętać o dokumentacji kodu (doxygen)
*/

#include "Point.h"

int main() {
  {
   std::cout << "\n****** Konstruktory ETAP 1 *****\n";
   Point krakow("Krakow",19.938333,50.0614),//x=długość,y=szerokość
         tarnow("Tarnow",20.9889,50.0139),
         poznan("Poznan",16.9211,52.4144),
         zielonki("Zielonki",19.938333,50.118611),
         nyc("Nowy Jork", -74.0059,40.7127),
         pusty;

   krakow.fullPrint();
   tarnow.fullPrint();
   poznan.fullPrint();
   zielonki.fullPrint();
   nyc.fullPrint();
   pusty.fullPrint();

  std::cout << "\n****** Konstruktory ETAP 2 *****\n";
  const double x = 20.259722, y = 50.0614;
  Point noname1=Point::setPoint(x,y);
  const Point noname2=Point::setContrary(23.0124,45.4523);
  noname1.fullPrint();
  noname2.fullPrint();

  noname1.changeName("Wola Batorska");
  noname1.fullPrint();
  Point batorska = noname1;
  batorska.fullPrint();
 
  Point moved = pusty.newMoved("New Moved",-50,-30); //tworzymy nowy "New Moved" na podstawie przesuniecia o (-50,-30)
  moved.fullPrint();
  Point nowy1=std::move(moved);
  nowy1.fullPrint();
  moved.fullPrint();

  const Point kopia = std::move(pusty.newMoved("Nowe Miasto",-50,-30));
  kopia.fullPrint();
  std::move(Point::setContrary(x,y)).fullPrint();

std::cout<<"\n***** Podsumowanie *****\n";
std::cout << "Liczba obiektow: " << Point::number << std::endl;
}

std::cout<<"--- Czyszczenie\n";
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

*/