/*
 Zadanie ma na celu przećwiczenie różnego rodzaju konwersji jawnych i niejawnych oraz jak im zapobiegać oraz przecwiczenie przeładowania prostych operatorów.

 Prosze zdefiniować klasy Wymierne i Zespolone (re i im), reprezentujące odpowiednio  liczby wymierne (licznik/mianownik) oraz zespolone (Re, Im)

 UWAGA!!!
 * W zadaniu trzeba zdefiniować zarowno konstruktory jak i operotory konwertujace.
 * wszystki pola są prywatne (warto je odróżniać poprzez _ np _re, _im, wówczas funkcje dostępowe mogą mieć taką samą nazwę Re(), Im())
 * Konstruktory z listami inicjalizacyjnymi  (inline) operatory i gettery, settery proszę zdefiniowac w pliku nagłówkowym.
 W pliku cpp jedynie funkcje Print i Pomnoz/Dodaj. To znacznie uprości zadanie.
 * std::move w Zespolone nie może działać na standardowym konstruktorze przenoszącym, bo output będzie niepoprawny.

 Blok "CONST WYMIERNE" warty ok. 2 punkty może sprawić problemy, dlatego można go wyłączyć, dodając do opcji kompilacji -DBASIC

 Blok ERROR ma się nie kompilować i zgłaszać  błąd- sprawdz: make error albo odkomentuj linię #define ERROR (za brak -1 pkt)
 
 Błąd:
 error: invalid initialization of reference of type ‘const Wymierne&’ from expression of type ‘int’
   Wymierne W5 = Pomnoz(10, 5);

 Proszę nie zapomnieć o dokumentacji doxygen
*/

// Po wywołaniu make error albo odkomentowaniu tej linii powinien pojawić się błąd
// #define ERROR

#include <iostream>
#include <math.h>
#include "Wymierne.h"
#include "Zespolone.h"

int main()
{

  std::cout << "\n*** WYMIERNE ***" << std::endl;

  Wymierne Raz(1, 2), Dwa(3, 4), Trzy, Cztery(2, 0);
  Raz.Print("Raz = ");
  Dwa.Print("Dwa = ");
  Trzy.Print("Trzy = ");
  Cztery.Print("Cztery = ");

  const Wymierne W1 = Pomnoz(Raz, Dwa);
  W1.Print("W1 = ");
  double L1 = W1;
  std::cout << L1 << std::endl;

  Wymierne W2 = Pomnoz(Raz, static_cast<Wymierne>(5));
  W2.Print("W2 = ");

  Wymierne W3 = Pomnoz(static_cast<Wymierne>(10), static_cast<Wymierne>(5));
  W3.Print("W3 = ");

  double L2 = sqrt(W3);
  std::cout << L2 << std::endl;

  W2.Mianownik(0);
  W2.Print("W2 = ");
  W2.Mianownik(8);
  W3.Set(W1);
  W2.Print("W2 = ");
  W3.Print("W3 = ");

  std::cout << "\n*** ZESPOLONE ***" << std::endl;

  Zespolone Z = Dwa;
  Z.Print("Z = ");
  std::cout << "---Im = " << Z.Im() << std::endl;

  Zespolone Z1 = Dodaj(Zespolone(1), static_cast<Zespolone>(4));
  Z1.Print("Z1 = ");

  Zespolone Z2 = Dodaj(Zespolone(1, 5), static_cast<Zespolone>(Dwa));
  Z2.Print("Z2 = ");

  Zespolone Z3 = Dodaj(static_cast<Zespolone>(Wymierne(10, 3)), Wymierne(1, 3));
  Z3.Print("Z3 = ");

  Zespolone Z4 = Dodaj(1, 2); // w przypadku problemów z tą linią zakomentuj ją i odkomentuj następną
  // Zespolone Z4 = Dodaj(static_cast<Zespolone>(1), static_cast<Zespolone>(2));   //wersja rezerwowa (-2 pkt)
  Z4.Print("Z4 = ");

  Zespolone Z5(std::move(Z4));
  Z4.Print("Z4 = ");

  Dodaj(Z5, Z2).Print("Z5+Z2 = ");

#ifndef BASIC // (ok. 2 pkt)
  std::cout << "\n*** WYMIERNE CONST ***" << std::endl;
  W1.Licznik(7);
  W1.Print("W1 = ");
  const Wymierne W4(W1);
  W4.Print("W4 = ");
  W4.Set(Pomnoz(W2, W3));
  W4.Print("W4 = ");
#endif

  std::cout << std::endl;

#ifdef ERROR //błąd konwersji (1 pkt)
  Wymierne W5 = Pomnoz(10, 5);
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
W2 = 5/2
W3 = 50
7.07107
W2 = 5
W2 = 5/8
W3 = 3/8

*** ZESPOLONE ***
Z = 0.75
---Im = 0
Z1 = 5
Z2 = 1.75 + 5i
Z3 = 3.66667
Z4 = 3
Z4 = 0
Z5+Z2 = 4.75 + 5i

*** WYMIERNE CONST ***
W1 = 7/8
W4 = 7/8
W4 = 15/64

*/