/*Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał
  a wynik jego działania był taki sam, jak podany na końcu tego pliku.
  Kody źródłowe powinny znajdować się w katalogu nazwisko1_nazwisko2_lab10.

  Pracujemy w grupach dwuosobowych, bazując na zadaniach z lab8 i lab9.
  Łączymy dwie klasy, tworząc jednokierunkową listę punktów, dokonujemy modyfikacji,
  przeciążamy operatory, wykorzystując napisane wcześniej funkcje.
  UWAGA! Do zadania wykorzystujemy tylko klasę Punkt (bez funkcji zewnętrznych)
  oraz czyścimy kod klasy IntLinkedList, usuwając niepotrzebne funkcje,
  np. te działające tylko na elementach listy typu Integer.
  Zadanie jest podzielone na etapy, można zakomentarzować dalsze etapy,
  chcąc uruchomić wcześniejsze.

  Zmiany w Point: (Etap 1)
  * dodać pole prywatne - wskaźnik na Point i zmodyfikować konstruktory
    oraz destruktor,
  * przeładować operatory == i < lub > do porównywania dwóch punktów
    - punkty są porównywane wg pierwszej współrzędnej, a gdy te są równe
    wg kolejnej,
  * przeładować operator << albo dodać funkcję print wypisującą współrzędne
    bez znaku końca linii.

  Zmiany w LinkedList: (nazwa zmieniona),
    Etap 1
    * zmodyfikować contains - pobiera Point i wykorzystuje operator == klasy Point,
    * zmodyfikować funkcje składowe append(Point&) i addSorted(Point&)
      i inne funkcje potrzebne do uruchomienia pierwszej części zadania.
    Etap 2
    * dopisać operator << - działanie print (cout<<L1),
    * dopisać operator --(int) postinkrementacja - działanie removeLast (L1--)
      w przypadku braku tego operatora odkomentuj removeLast,
    * dopisać operator += - działanie addSorted w opcji true dla punktu (L1+=x).
    Etap 3
    * dodać konstruktor przenoszący (obiekt po przeniesieniu jest listą pustą o nazwie "LX"
      - czyli rezultat działania konstruktora domyślnego),
    * dopisać operator += - działanie addSorted w opcji true dla listy (L1+=L2).
    Etap 4
    * dopisać operator = - przypisanie listy (L1=L2),
    * dopisać operator + - działanie addSorted w opcji true dodającej dwie listy (L1+L2).

    UWAGA! Wszystkie operatory mają działać niezależnie od funkcji, których działanie wykonują,
    aby można je całkowicie zastąpić i usunąć.
    Operatory powinny zostać zaimplementowane jako funkcje składowe klasy lub zaprzyjaźnione.

 * Pliku main.cpp, NIE WOLNO modyfikować z wyjątkiem komentarzy dopuszczonych przez prowadzącego.
 * Proszę pamietać o dokumentacji kodu.
 * Skonfiguruj plik konfiguracyjny cmake albo napisz Makefile tak, aby:
   - plikiem wynikowym był main
   - program kompilował się z flagami -std=c++11 -Wall - pedantic.
   - były zdefiniowane cele użytkownika run, clean, check oraz all (main+run)

 * Kody źródłowe powinny znajdować się w katalogu nazwisko1_nazwisko2_lab10
   do którego nikt oprócz właściciela nie ma praw dostępu.
 * UWAGA! Wysyłamy spakowany katalog, nie oddzielne pliki!!!!!!
   Wcześniej kasujemy niepotrzebne pliki!
*/

#include "point.h"
#include "linkedList.h"
#include <iostream>

using namespace std;

int main()
{

  Point a("A", 1, 2), b("B", -1, -1), c("C", -1, 1),
      d("D", 1, -1),
      e("E", 1, 1),
      x("X", -1, 1.5),
      y("Y", -1.5, 1),
      z("Z", 1, 1.5);

  cout << "*********** Test połączenia klas ***********\n"; // Etap 1
  LinkedList L1("L1"), L2("L2"), L3("L3");
  L1.append(a);
  L1.append(b);
  L1.append(c);
  print(L1);
  L2.addSorted(a);
  L2.addSorted(b);
  L2.addSorted(c);
  L2.addSorted(d);
  L2.addSorted(e);
  print(L2);

  cout << "\n*********** Test operatorów -- += (L2+=z,a L3+=x,y,z,y) ***********\n"; // Etap 2
  L2 += z;
  L2 += a;

  cout << L2;
  L2--;
  L2.removeLast();
  cout << L2;
  cout << L2--;
  cout << L2;
  L3 += x;
  L3 += y;
  L3 += z;
  L3 += y;
  cout << L3;

  cout << "\n*********** Test L5+=L3, L4(move L1) ***********\n"; // Etap 3
  LinkedList L4 = move(L1), LX, L5("L5"), L6("L6");
  cout << L3 << L4 << L1;
  L5 += L3;
  L5 += L4;
  L5 += L3;
  cout << L5;

  cout << "\n*********** Test L6=L2+L3 ***********\n"; // Etap 4
  cout << L2 << L3;
  cout << L6;
  cout << "\n*********** KONIEC ***********\n";
  return 0;
}

/* Oczekiwany wynik: ./main

*********** Test połączenia klas ***********
L1=[A(1,2), B(-1,-1), C(-1,1)]
L2=[B(-1,-1), C(-1,1), D(1,-1), E(1,1), A(1,2)]

*********** Test operatorów -- += (L2+=z,a L3+=x,y,z,y) ***********
L2=[B(-1,-1), C(-1,1), D(1,-1), E(1,1), Z(1,1.5), A(1,2)]
L2=[B(-1,-1), C(-1,1), D(1,-1), E(1,1), Z(1,1.5)]
L3=[Y(-1.5,1), X(-1,1.5), Z(1,1.5)]

*********** Test L5+=L3,L4(L1) ***********
L3=[Y(-1.5,1), X(-1,1.5), Z(1,1.5)]
L1=[A(1,2), B(-1,-1), C(-1,1)]
LX=[]
L5=[Y(-1.5,1), B(-1,-1), C(-1,1), X(-1,1.5), Z(1,1.5), A(1,2)]

*********** Test L6=L2+L3 ***********
L2=[B(-1,-1), C(-1,1), D(1,-1), E(1,1), Z(1,1.5)]
L3=[Y(-1.5,1), X(-1,1.5), Z(1,1.5)]
L6=[Y(-1.5,1), B(-1,-1), C(-1,1), X(-1,1.5), D(1,-1), E(1,1), Z(1,1.5)]

*********** KONIEC ***********
Destruktor L6: Lista pusta
Destruktor L5: Lista pusta
Destruktor LX: Lista pusta
Destruktor L1: Lista pusta
Destruktor L3: Lista pusta
Destruktor L2: Lista pusta
Destruktor LX: Lista pusta
*/
