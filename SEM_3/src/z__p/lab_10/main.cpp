/* Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał
   a wynik jego działania był taki sam, jak podany na końcu tego pliku.

 * Zdefiniuj klasę Point przechowującą współrzędne punktu oraz jego nazwę.
   Można dokonać tego modyfikując klasę Element z poprzednich zajęć,
   zostawiając wskaźnik next na następny element, ale pole _name
   ma być dynamicznie alokowane w konstruktorze.
   Wszystkie pola w klasie są prywatne.
   Zdefiniuj konstruktory i metody:
     - konstruktor bezparametrowy (wpółrzedne ustawione na 0, nazwa na nullptr),
     - konstruktor ustawiający współrzędne, nazwa domyślnie nadana "Miejsce nieznane",
     - konstruktor ustawiający nazwę i współrzędne,
     - konstruktor kopiujący obiekt typu Point,
     - konstruktor przenoszący obiekt typu Point
     - destruktor zwalniający pamięć _name,
     - funkcje getX, getX, getName - zwracające warości prywatnych pól,
     - changeName - zmieniającą nazwę obiektu,
     - fullPrint - drukującą obiekt w postaci: name (x, y).
       Jeśli _name jest równy NULL, w miejsce nazwy wypisuje NULL
   Zdefiniuj funkcje: 
     - compareX, compareY - porównującą p1 i p2 i zwracającą:
         * wartość dodatnią (np 1) dla porządku rosnącego,
         * zero dla równych wartości,
         * wartość ujemną (np -1) dla porządku malejącego.
     - compareXY - porównującą wartości punktu wg X i Y
       i zwracającą 9 unikatowych wartości wg zasady 10x+y.
     - directions - przyjmującą jako argument wskaźnik do funkcji z rodziny compare
       wypisującą odpowiedni tekst w zależności od tego, która funkcja została podana
       jako argument wywołania funkcji.
       W przypadku compareXY podaje tylko 4 kierunki pośrednie typu pn-zach, pd-wsch itp
       a jeśli punkty mają tę samą współrzędną X albo Y, wypisuje komunikaty
       jak po wywołaniu compareX i compareY. 
       Wykorzystaj switch case zamiast zagnieżdżonych if.
       Wartości zwracane przez compareX, compareY, compareXY 
       dla poszczególnych kierunków zostały dla ułatwienia wypisane. 
       UWAGA! jeśli nie potrafisz zaimplementować funkcji ze wskaźnikiem funkcyjny
       zakomentuj blok wersja podstawowa, odkomentuj blok koło ratunkowe, 
       gdzie funkcja zamiast wskaźnika do funkcji pobiera napis.

 * Pliku main.cpp, NIE WOLNO modyfikować bez zgody prowadzącego.
 * Proszę pamietać o dokumentacji kodu.
 * Skonfiguruj plik konfiguracyjny cmake albo napisz Makefile tak, aby:
   - plikiem wynikowym był main
   - program kompilował się z flagami -std=c++11 -Wall - pedantic.
   - były zdefiniowane cele użytkownika run, clean, check oraz all (main+run)

 * Kody źródłowe powinny znajdować się w katalogu nazwisko_lab9 
 * do którego nikt oprócz właściciela nie ma praw dostępu.
 * UWAGA! Wysyłamy spakowany katalog, nie oddzielne pliki!!!!!!
 * Wcześniej kasujemy niepotrzebne pliki.
 
 * Podczas wykonywania zadania nie wolno korzystać z internetu, notatek,
 * ani żadnych innych materiałów. 
*/

#include "point.h"
#include <iostream>

using namespace std;

int main()
{

  Point krakow("Krakow", 19.938333, 50.0614), //x=długość,y=szerokość
      tarnow("Tarnow", 20.9889, 50.0139),
      poznan("Poznan", 16.9211, 52.4144),
      batorska("Wola Batorska", 20.259722, 50.0614),
      zielonki("Zielonki", 19.938333, 50.118611),
      nyc("Nowy Jork", -74.0059, 40.7127),
      kopia(batorska),
      noname(23.0124, 45.4523), pusty;

  cout << "\n****** Konstruktory *****\n";
  pusty.fullPrint();
  noname.fullPrint();
  krakow.fullPrint();
  poznan.fullPrint();
  tarnow.fullPrint();
  nyc.fullPrint();
  zielonki.fullPrint();
  batorska.fullPrint();
  kopia.fullPrint();
  kopia.changeName("Nowa Batorska");
  kopia.move(-50, -30);
  kopia.fullPrint();
  Point nowy = std::move(kopia);
  nowy.fullPrint();
  kopia.fullPrint();

  // Do zakomentowania w przypadku wykorzystania koła ratunkowego
  cout << "\n****** Wersja podstawowa *****\n";
  cout << "X=" << compareX(poznan, krakow) << " Y=" << compareY(poznan, krakow) << " XY=" << compareXY(poznan, krakow) << endl;
  directions(poznan, krakow, compareX); //compareX, compareY, compareXY to wskaźniki funkcyjne
  directions(poznan, krakow, compareY);
  directions(poznan, krakow, compareXY);
  cout << "X=" << compareX(tarnow, krakow) << " Y=" << compareY(tarnow, krakow) << " XY=" << compareXY(tarnow, krakow) << endl;
  directions(tarnow, krakow, compareX);
  directions(tarnow, krakow, compareY);
  directions(tarnow, krakow, compareXY);
  cout << "X=" << compareX(poznan, nyc) << " Y=" << compareY(poznan, nyc) << " XY=" << compareXY(poznan, nyc) << endl;
  directions(poznan, nyc, compareX);
  directions(poznan, nyc, compareY);
  directions(poznan, nyc, compareXY);
  cout << "X=" << compareX(nyc, krakow) << " Y=" << compareY(nyc, krakow) << " XY=" << compareXY(nyc, krakow) << endl;
  directions(nyc, krakow, compareX);
  directions(nyc, krakow, compareY);
  directions(nyc, krakow, compareXY);
  cout << "X=" << compareX(krakow, zielonki) << " Y=" << compareY(krakow, zielonki) << " XY=" << compareXY(krakow, zielonki) << endl;
  directions(krakow, zielonki, compareX);
  directions(krakow, zielonki, compareY);
  directions(krakow, zielonki, compareXY);
  cout << "X=" << compareX(krakow, batorska) << " Y=" << compareY(krakow, batorska) << " XY=" << compareXY(krakow, batorska) << endl;
  directions(krakow, batorska, compareX);
  directions(krakow, batorska, compareY);
  directions(krakow, batorska, compareXY);
  directions(krakow, nowy, compareXY);
  /*
   //Do odkomentowania gdy korzystasz z koła ratunkowego
   
   cout << "\n****** Koło ratunkowe *****\n";
   string cmpX="compareX", cmpY="compareY", cmpXY="compareXY";
   cout<<"X="<<compareX(poznan,krakow)<<" Y="<<compareY(poznan,krakow)<<" XY="<<compareXY(poznan,krakow)<<endl;
   directions(poznan,krakow,cmpX);
   directions(poznan,krakow,cmpY);
   directions(poznan,krakow,cmpXY);
   cout<<"X="<<compareX(tarnow,krakow)<<" Y="<<compareY(tarnow,krakow)<<" XY="<<compareXY(tarnow,krakow)<<endl;
   directions(tarnow,krakow,cmpX);
   directions(tarnow,krakow,cmpY);
   directions(tarnow,krakow,cmpXY);
   cout<<"X="<<compareX(poznan,nyc)<<" Y="<<compareY(poznan,nyc)<<" XY="<<compareXY(poznan,nyc)<<endl;
   directions(poznan,nyc,cmpX);
   directions(poznan,nyc,cmpY);
   directions(poznan,nyc,cmpXY);
   cout<<"X="<<compareX(nyc,krakow)<<" Y="<<compareY(nyc,krakow)<<" XY="<<compareXY(nyc,krakow)<<endl;
   directions(nyc,krakow, cmpX);
   directions(nyc,krakow, cmpY);
   directions(nyc,krakow, cmpXY);
   cout<<"X="<<compareX(krakow,zielonki)<<" Y="<<compareY(krakow,zielonki)<<" XY="<<compareXY(krakow,zielonki)<<endl;
   directions(krakow,zielonki,cmpX);
   directions(krakow,zielonki,cmpY);
   cout<<"X="<<compareX(krakow,batorska)<<" Y="<<compareY(krakow,batorska)<<" XY="<<compareXY(krakow,batorska)<<endl;
   directions(krakow,batorska,cmpX);
   directions(krakow,batorska,cmpY);
   directions(krakow,batorska,cmpXY);
   directions(krakow,nowy,cmpXY);
   
*/
  return 0;
}

/* Oczekiwany wynik: ./main

****** Konstruktory *****
NULL (0,0)
Miejsce nieznane (23.0124,45.4523)
Krakow (19.9383,50.0614)
Poznan (16.9211,52.4144)
Tarnow (20.9889,50.0139)
Nowy Jork (-74.0059,40.7127)
Zielonki (19.9383,50.1186)
Wola Batorska (20.2597,50.0614)
Wola Batorska (20.2597,50.0614)
Nowa Batorska (-29.7403,20.0614)
Nowa Batorska (-29.7403,20.0614)
NULL (0,0)

****** Wersja podstawowa *****
X=1 Y=-1 XY=9
Poznan jest na zachód od Krakow
Poznan jest na północ od Krakow
Poznan jest na północny-zachód od Krakow
X=-1 Y=1 XY=-9
Tarnow jest na wschód od Krakow
Tarnow jest na południe od Krakow
Tarnow jest na południowy-wschód od Krakow
X=-1 Y=-1 XY=-11
Poznan jest na wschód od Nowy Jork
Poznan jest na północ od Nowy Jork
Poznan jest na północny-wschód od Nowy Jork
X=1 Y=1 XY=11
Nowy Jork jest na zachód od Krakow
Nowy Jork jest na południe od Krakow
Nowy Jork jest na południowy-zachód od Krakow
X=0 Y=1 XY=1
Krakow jest na tej samej długości co Zielonki
Krakow jest na południe od Zielonki
Krakow jest na południe od Zielonki
X=1 Y=0 XY=10
Krakow jest na zachód od Wola Batorska
Krakow jest na tej samej szerokości co Wola Batorska
Krakow jest na zachód od Wola Batorska
Krakow jest na północny-wschód od Nowa Batorska
*/
