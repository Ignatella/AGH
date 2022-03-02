/* Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał
   a wynik jego działania był taki sam, jak podany na końcu tego pliku.

 * Zdefiniuj klasę Fraction reprezentujacą ułamek zwykły.
   posiadającą dwa pola prywatne _l i_m typu int.

 * Zdefiniuj niezbędne konstruktory i metody pomocnicze.
   Ułamek jest upraszczany na etapie konstruktora (funkcja simplify).
   W ramach uproszczenia, w komentarzu umieszczono kod funkcji nwd,
   służacej do wy;iczenia największego wspólnego dzielnika.
   
 * Zaimplementuj operatory dodawania +, mnożenia *
   (również w wersji liczba * ułamek), operator +=
   operator przypisania =, operator liczby przeciwnej -, 
   ostream << oraz konwersję do double Fraction.
   Zdecyduj, które operatory napisać jako metody klasy
   a które jako zewnętrzne funkcje.
  
 * W wybranych miejscach po odkomentowaniu program nie powinien się kompilować.
   Należy zadbać o to, aby wysłać wersję, która się kompiluje.
 * W innych przypadkach pliku main.cpp, NIE WOLNO modyfikować.
 * Proszę pamietać o dokumentacji kodu.
 * Skonfiguruj plik konfiguracyjny cmake albo napisz Makefile tak, aby:
   - plikiem wynikowym był main
   - program kompilował się z flagami -std=c++11 -Wall - pedantic.
   - były zdefiniowane cele użytkownika run, clean, check oraz all (main+run)

 * Kody źródłowe powinny znajdować się w katalogu nazwisko_lab11 
 * do którego nikt oprócz właściciela nie ma praw dostępu.
 * UWAGA! Wysyłamy spakowany katalog, nie oddzielne pliki!!!!!!
 * Wcześniej kasujemy niepotrzebne pliki.
 
 * Podczas wykonywania zadania nie wolno korzystać z internetu, notatek,
 * ani żadnych innych materiałów. 
*/

#include "fraction.h"
#include <iostream>

using namespace std;


int main ()
{
  Fraction f1(6,8);
  const Fraction f2(3,2);
  Fraction f3(6,2);
  cout << "Ułamki po skróceniu w konstruktorze:" << endl; 
  cout << "f1 = " << f1 << endl; 
  cout << "f2 = " << f2 << endl; 
  cout << "f3 = " << f3 << endl; 

  double val = f1;
  cout << "Ułamek dziesiętny f1: " << val << endl; 
 
  cout << "**********  Prosta arytmetyka *************" << endl; 
  Fraction f4=f1*f2;
  f3=f1*f4;
  cout << "Iloczyn: " << f1 << " * " << f2 <<" = " << f4 << endl; 
  cout << "Iloczyn: " << f1 << " * " << f4 <<" = " << f3 << endl;
 
  cout << "Iloczyn: " << "3 * " << f2 <<" = " << 3*f2 << endl; 
  cout << "Suma: " << f1 << " + " << f2 <<" = " << f1+f2 << endl;

  f3=f1+f4;
  f3+=-3;
  cout << "Suma: " << f1+f4 <<" + (-3) = " << f3 << endl; 
  cout << "Suma: " << f1+f4 <<" + (-3) = " << static_cast<float>(f3) << endl;

  f3 = -f1;
  cout << "f3 = -f1   " << f3 << endl;; 
//Zadania do poeksperymentowania po skończeniu pierwszej części
  f1=f2; // OK
  // f1+f2=f4; // ma się nie kompilować po odkomentowaniu

  Fraction tab[2]; // OK
  tab[0] = f1; //OK
  f1 = tab[0]; //OK
  // f2 = tab[0]; //ma się nie kompilować po odkomentowaniu
  // ponieważ chcemy zapobiec modyfikowaniu obiektów const
  return 0;
}

/* Oczekiwany wynik: ./main
Ułamki po skróceniu w konstruktorze:
f1 = 3/4
f2 = 1 1/2
f3 = 3
Ułamek dziesiętny f1: 0.75
**********  Prosta arytmetyka *************
Iloczyn: 3/4 * 1 1/2 = 1 1/8
Iloczyn: 3/4 * 1 1/8 = 27/32
Iloczyn: 3 * 1 1/2 = 4 1/2
Suma: 3/4 + 1 1/2 = 2 1/4
Suma: 1 7/8 + (-3) = -1 1/8
Suma: 1 7/8 + (-3) = -1.125
f3 = -f1   -3/4
*/
