/* 
 Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał,
 a wynik jego działania był taki sam, jak podany na końcu tego pliku.

 Struktura MapPoint (pliki MapPoint.h, MapPoint.cpp) reprezentuje punkt na mapie składający się z nazwy, długości (longitude) i szerokości (latitude) geograficznej.
 
 Funkcje construct i clear to funkcje tworzące i usuwające punkt.
 Funkcja construct przyjmuje dodatnie i ujemne wartości wspórzędnych i na ich podstawie wnioskujemy strony świata. Odpowiednio zgodnie z układem współrzędnych dla długości ujemnych mamy W, a dla szerokości ujemnych mamy S.
 
 Funkcja movePoint zmienia współrzedne punktu, przesuwając go o wartości podane w argumentach funkcji. 
 
 Funkcja inTheMiddle powinna tworzyć nowy punkt na mapie o zadanej nazwie i położeniu, które jest średnią arytmetyczną z położeń podanych punktów czyli x = (x1 + x2)/2 itp. Proszę uważać w przypadku różnych półkul.
 
 Funkcja closestFrom pobiera 3 argumenty. Pierwszy argument jest punktem referencyjnym. Z dwóch kolejnych wybiera ten, który jest najbliżej punktu referencyjnego. 
 Odległość między punktami (angularDistance) obliczamy jako pierwiastek z sumy kwadratów odległości względem południków i równoleżników, czyli sqrt(delta_x*delta_x + delta_y*delta_y).
 Funkcja obliczająca pierwiastek nazywa się: sqrt(double) i znajduje się w bibliotece "cmath".

 Po zdefiniowaniu w CMakeLists.txt BASIC (odkomentowaniu linii 11), kompiluje się tylko wersja podstawowa na 50% punktów. To pomoże Wam w stopniowaniu postępów pracy.
 Sposób rozwiązania 2 części jest dowolny, premiowana będzie pomysłowość i optymalność rozwiązania. Rozwiązania "na piechotę" będą miały mniejsza wartość punktową za kod. 

 Proszę zadbać o dobre zarządzanie pamięcią. Pamięc alokujemy za pomocą malloc (nie znamy jeszcze new).
 Uruchom make check (valgrind ./main), aby sprawdzić, czy nie ma żadnych błędów ani wycieków pamięci.
 Pliku main.cpp, nie wolno modyfikować.
*/

#include <iostream>
#include "MapPoint.h"

#ifndef BASIC
#include "MapDist.h"
#endif

int main()
{
  const double longitude = 19.938333;
  const double latitude = 50.061389;
  MapPoint *krakow = construct("Krakow", longitude, latitude); //kierunki E N
  print(krakow);
  MapPoint *nyc = construct("Nowy Jork", -74.0059, 40.7127); //kierunki W N
  print(nyc);
  MapPoint *sydney = construct("Sydney", 151.102, -33.454); // kierunki E S
  print(sydney);
  MapPoint *porto = construct("Porto", 41.162142, 8.621953); // kierunki E N
  const MapPoint &portugalCity = *porto;
  print(&portugalCity);

  const double longitudeShift = 4.1234;
  const double latitudeShift = -25.987;
  std::cout << "*** Po przesunieciu ***\n";
  movePoint(porto, longitudeShift, latitudeShift);
  print(&portugalCity);
  std::cout << "*** Po przesunieciu ***\n";
  movePoint(porto, -90.5710, 34.7300);
  print(&portugalCity);

#ifndef BASIC
  const MapPoint &cl = closestFrom(krakow, nyc, sydney);
  std::cout << "Blizej Krakowa jest " << cl.name << std::endl;
  MapPoint mp = inTheMiddle(nyc, sydney, "Kenia");
  print(&mp);
#endif

  std::cout << "*** Czyszczenie ***\n";
  clear(krakow, nyc, porto);
  clear(sydney);
  std::cout << "*** Koniec ***\n";
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
Blizej Krakowa jest Nowy Jork
Wspolrzedne dla Kenia: 38.5481E, 3.62935N
*** Czyszczenie ***
Usuwanie Krakow
Usuwanie Nowy Jork
Usuwanie Porto
Usuwanie Sydney
*** Koniec ***
*/