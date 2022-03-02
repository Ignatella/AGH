/*
 Celem zadania jest przećwiczenie różnego rodzaju konwersji  oraz definicji własnych przestrzeni nazw.
 Zadanie jest kontynuacją zadania z poprzednich zajęć, więc można z niego skorzystać.
 Prosze jednak wprowadzić istotne zmiany:
 * wszystkie konstruktory i gettery oraz operator są inline zdefiniowane w pliku nagłówkowym.
 * kostruktory kopiujące i przenoszące są tak naprawdę potrzebne tylko w klasie Zespolone.
 * nie ma żadnych przyjaźni, operujemy na getterach - a w różnych przestrzeniach nazw to tylko skomplikuje sprawy.
 * każda klasa wraz z funkcjami zewnetrznymi jest w osobnej przestrzeni nazw wymierne i zespolone.
 * proszę zwrócić na sposób drukowania wyników obu klas, do klasy Wymierne nalezy dołożyć skracanie ułamka:
 do wykorzystania w funkcji simplify

  int nwd(int m, int n){
  int oldm, oldn;
    while( m % n != 0 ){
        oldm = m;
        oldn = n;
      m = oldn;
      n = oldm % oldn;
  }
    return n;
  }

 Ponadto definiujemy nowy niezbędny kod w pliku Double.h (jest krótki, więc bez rozdzielania na cpp). Z uwagi na to, że może niektórym przysporzyć problemów, jest objęty w dyrektywy, ale bez niego za zadanie można dostać maksymalnie 5 punktów.
 Każde wyświetlenie obiektu jest zliczane.
 UWAGA -  licznik ten musi być elementem klasy i nie może być mutable - za użycie go zostaną odjęte punkty.

 UWAGA!!!
 Blok ERROR nadal ma się nie kompilować i zgłaszać jeden błąd sprawdz: make error albo odkomentuj linię #define ERROR (za brak -1 pkt)

 Proszę nie zapomnieć o dokumentacji doxygen
*/

// Po wywołaniu make error albo odkomentowaniu tej linii powinny pokawić się błąd
// #define ERROR

#include <iostream>
#include <math.h>
#include "Wymierne.h"
#include "Zespolone.h"
#ifndef BASIC
#include "Double.h"
#endif

int main()
{
  std::cout << "\n*** WYMIERNE ***" << std::endl;

  using wymierne::Pomnoz;
  using wymierne::Wymierne;

  Wymierne Raz(2, 4);
  const Wymierne Dwa(3, 4), Trzy, Cztery(2, 0);
  Raz.Print("Raz = ");
  Dwa.Print("Dwa = ");
  Trzy.Print("Trzy = ");
  Cztery.Print("Cztery = ");

  Wymierne W1 = Pomnoz(Raz, Dwa);
  W1.Print("W1 = ");
  double L1 = W1;
  std::cout << L1 << std::endl;

  Wymierne W2 = Pomnoz(Dwa, static_cast<Wymierne>(6));
  W2.Print("W2 = ");

  Wymierne W3 = Pomnoz(static_cast<Wymierne>(2), static_cast<Wymierne>(5));
  W3.Print("W3 = ");

  double L2 = pow(W3, -2);
  std::cout << L2 << std::endl;

  Dodaj(Raz, Dwa).Print("Raz+Dwa = ");
  Dodaj(static_cast<Wymierne>(2), Wymierne(3)).Print("2+3 = ");
  /////////////////////////////////////////////////////////////////
  std::cout << "\n*** ZESPOLONE ***" << std::endl;
  using zespolone::Zespolone;

  Zespolone Z1 = zespolone::Dodaj(Zespolone(1, 5), static_cast<Zespolone>(4));
  Z1.Print("Z1 = ");

  const Zespolone Z2 = static_cast<Zespolone>(Dwa);
  const_cast<Zespolone &>(Z2).Print();

  Zespolone Z3 = zespolone::Dodaj(Wymierne(10, 3), Wymierne(1, 3));
  Z3.Print("Z3 = ");

  Zespolone Z4 = zespolone::Dodaj(1.5, 2.5);
  Z4.Print("Z4 = ");

  Zespolone Z5(std::move(Z4));
  Z4.Print("Z4 = ");
  zespolone::Dodaj(Z5, Z1).Print("Z5+Z1 = ");

//////////////////////////////////////////////////////
#ifndef BASIC
  std::cout << "\n*****  DOUBLE  *****" << std::endl;
  std::cout << "----- Obiekt x -----\n";
  const Double x{3.};
  Print(x);
  x.SetX(Dodaj(x, x));
  Print(x);
  x.SetX(Dodaj(x, x));
  x.Print();

  std::cout << "----- Obiekt y -----\n";
  Double y = Dwa;
  y.Print();
  y.SetX(x);
  Print(y);
  y.SetX(static_cast<Double>(Wymierne(4, 5)));
  Print(y);
#endif

  std::cout << std::endl;
//////////////////////////////////////////////////////
#ifdef ERROR
  Pomnoz(10, 5).Print("");
#endif

  return 0;
}

/* Oczekiwany wynik:

*** WYMIERNE ***
Raz = 1/2
Dwa = 3/4
Trzy = 0
Cztery = 2
W1 = 3/8
0.375
W2 = 9/2
W3 = 10
0.01
Raz+Dwa = 5/4
2+3 = 5

*** ZESPOLONE ***
Z1 = 5 + 5i
Z2 = 0.75
Z3 = 3.66667
Z4 = 4
Z4 = 0
Z5+Z1 = 9 + 5i

*****  DOUBLE  *****
----- Obiekt x -----
Print nr 1. Val = 3
Print nr 2. Val = 6
Print nr 3. Val = 12
----- Obiekt y -----
Print nr 1. Val = 0.75
Print nr 2. Val = 12
Print nr 3. Val = 0.8

*/
