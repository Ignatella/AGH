/* 
  Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał, a wynik jego działania był taki sam, jak podany na końcu tego pliku.
 Zadanie opiera się na znanej już Wam treści (można korzystać ze źródeł lab3), lecz tym razem mamy klasy, konstruktory, destruktory, klasy i funkcje zaprzyjaźnione.

 Klasa MapPoint (pliki MapPoint.h, MapPoint.cpp) reprezentuje punkt na mapie składający się z nazwy (może być typu string), długości (longitude) i szerokości (latitude) geograficznej. Są to prywatne składowe klasy.
 
 Konstruktory i destruktory (dawne construct i clear) tworzą i usuwają punkt.
 Konstruktor posiada różne wersje.
  Pierwsza przyjmuje współrzędne w postaci dodatniej (unsigned) oraz strony świata w postaci char ('E', 'W' dla długości i 'N', 'S' dla szerokości).
  Druga przyjmuje dodatnie i ujemne wartości wspórzędnych i na ich podstawie wnioskujemy strony świata. Odpowiednio zgodnie z układem współrzędnych dla długości ujemnych mamy W, a dla szerokości ujemnych mamy S.
  UWAGA! Oznaczeń znakowych półkul nie przechowujemy, tak jak w zadaniu, które już robiliśmy. Po prostu w określonych przypadkach w pierwszym konstruktorze zmieniamy znak.
  Bezparametrowa ustawia punkt na (0,0) i nazwę na "Punkt".
 
 Funkcja składowa movePoint zmienia współrzedne punktu, przesuwając go o wartości podane w argumentach funkcji. Proszę pamiętać o ew. zmianach stron świata po przesunięciu.

Funkcja skladowa closestFrom pobiera 3 argumenty. Pierwszy argument jest punktem referencyjnym. Z dwóch kolejnych wybiera ten,który jest najbliżej punktu referencyjnego. Funkcja wykorzystuje angularDistance.
 
Funkcja zaprzyjaźniona inTheMiddle powinna tworzyć nowy punkt na mapie o zadanej nazwie i położeniu, które jest średnią arytmetyczną z położeń podanych punktów czyli x = (x1 + x2)/2 itp. Proszę uważać w przypadku różnych półkul.

Klasa MapDist (pliki MapDist.h, MapDist.cpp) reprezentuje odległość pomiędzy dwoma punktami. Odległość wzdłuż południków lub równoleżników należy obliczyć po prostu odejmując od siebie współrzędne punktów końcowego i początkowego (konstruktor działa podobnie jak funkcja distance).

Funkcja angularDistance oblicza pierwiastek z sumy kwadratów odległości względem południków i równoleżników, czyli sqrt(delta_x*delta_x + delta_y*delta_y).
Funkcja obliczająca pierwiastek nazywa się: sqrt(double) i znajduje się w bibliotece "cmath".

Za brak prywatnych danych będą obniżane punkty. Można zaprzyjaźnić klasy.
Proszę zadbać o dobre zarządzanie pamięcią.
Pliku main.cpp, nie wolno modyfikować.
*/

#include <iostream>
#include "MapPoint.h"
#include "MapDist.h"

int main()
{
  const double longitude = 19.938333;
  const double latitude = 50.061389;
  MapPoint krakow("Krakow", longitude, latitude); //kierunki E N
  krakow.print();
  MapPoint *nyc = new MapPoint("Nowy Jork", 74.0059, 'W', 40.7127, 'N');
  nyc->print();
  MapPoint sydney("Sydney", 151.102, -33.454); // kierunki E i S jak ujemna to S
  sydney.print();
  MapPoint *porto = new MapPoint("Porto", 41.162142, 8.621953); // kierunki E i N
  const MapPoint &portugalCity = *porto;
  portugalCity.print();

  const double longitudeShift = 4.1234;
  const double latitudeShift = -25.987;
  std::cout << "*** Po przesunieciu ***\n";
  porto->movePoint(longitudeShift, latitudeShift);
  portugalCity.print();
  std::cout << "*** Po przesunieciu ***\n";
  porto->movePoint(-90.5710, 34.7300);
  portugalCity.print();

  const MapDist d = distance(*nyc, sydney);
  const MapDist d1(*nyc, sydney); //to samo co distance
  std::cout << "Odleglosci miedzy NYC i Sydney: \nRoznica dlugosci: " << d1.getlongitude() << "\nRoznica szerokosci: " << d1.getlatitude() << "\nOdleglosc: " << d.angularDistance() << std::endl;

  const MapPoint &cl = krakow.closestFrom(nyc, &sydney);
  std::cout << "Blizej Krakowa jest " << cl.getName() << std::endl;

  MapPoint mp = inTheMiddle(nyc, &sydney, "Kenia");
  mp.print();

  std::cout << "*** Czyszczenie ***\n";
  // Tu wywołują się destruktory
  delete nyc;
  delete porto;
}
/** Wynik działania programu:
./main
Wspolrzedne dla Krakow: 19.9383E, 50.0614N
Wspolrzedne dla Nowy Jork: 74.0059W, 40.7127N
Wspolrzedne dla Sydney: 151.102E, 33.454S
Wspolrzedne dla Porto: 41.1621E, 8.62195N
*** Po przesunieciu ***
Wspolrzedne dla Porto: 45.2855E, 17.365S
*** Po przesunieciu ***
Wspolrzedne dla Porto: 45.2855W, 17.365N
Odleglosci miedzy NYC i Sydney: 
Roznica dlugosci: 225.108
Roznica szerokosci: 74.1667
Odleglosc: 237.011
Blizej Krakowa jest Nowy Jork
Wspolrzedne dla Kenia: 38.5481E, 3.62935N
*** Czyszczenie ***
Usuwanie Nowy Jork
Usuwanie Porto
Usuwanie Kenia
Usuwanie Sydney
Usuwanie Krakow
*/