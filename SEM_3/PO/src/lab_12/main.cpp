/* 
 Zmodyfikuj klasę Fraction z wcześniejszych zajęc, reprezentujacą ułamek zwykły.
 Zaimplementuj niezbędne operatory oraz konstruktory.

 UWAGA!
 * Operator konwersji na double musi być explicit.
 * Proszę nie powielać wersji operatorów, kiedy możemy skorzystać z konwersji.
 * Wersja BASIC jest na maksymalnie 6-7 punktów w zależności od kodu i dokumentacji.
 * Klasa FVector przechowuje ułamki, zaleca się skorzystanie z std::vector albo std::array i algorytm std::sort z <algorithm>.
 * Można zdefiniować całość w pliku FVector.h
 * W przypadku wersji BASIC nie ma potrzeby tworzenia tego pliku - wystarczy włączyć opcję komplilacji z -DBASIC
 * Sposób wyswietlania ulamków (ułamek niewłaściwy/wersja z całością) różni się w obu wersjach, na dole są podane oba warianty outputu.

 Pliku main.cpp, NIE WOLNO modyfikować. Do tego służy makefile.
*/

#include "Fraction.h"
#ifndef BASIC
  #include "FVector.h"
#endif

#include <iostream>

using std::cout;
using std::endl;

/* do wykorzystania w funkcji simplify
int nwd(int m, int n){
	int oldm, oldn;
    while( m % n != 0 ){
        oldm = m;
        oldn = n;
	    m = oldn;
	    n = oldm % oldn;
	}
    return n;
} */

int main ()
{
  Fraction f1(6,8);
  const Fraction f2(6,-4);
  Fraction f3(6,2);
  Fraction f4(-2,1);
  cout << "Ułamki po skróceniu w konstruktorze:" << endl; 
  cout << "f1 = " << f1 << endl; 
  cout << "f2 = " << f2 << endl; 
  cout << "f3 = " << f3 << endl; 
  cout << "f4 = " << f4 << endl; 

  double val = static_cast<double>(f1); 
  #ifdef ERROR
    double val = f1; //bez rzutowania musi zgłaszać błąd
  #endif
  
  cout << "Ułamek dziesiętny f1: " << val << endl; 
  
  cout << "**********  Prosta arytmetyka *************" << endl; 
  f4 = f2 * f1 * f4;
  const Fraction f5 = f2 * f4;
  cout << "f4 = " << f2 << " * " << f1  << " * -2 = " << f4 << endl; 
  cout << "f5 = " << f2 << " * " << f4 <<" = " << f5 << endl;
  f3 = f5;
  f3 *= 4; // to samo co f3*= static_cast<Fraction>(4);
  cout << "f3 = " << f5 <<" * 4 = " << f3 << endl; 
  cout << "f3 = " << f5 <<" * 4 = " << static_cast<double>(f3) << endl; 
  cout << "f1 + f2 = " << f2 << " + " << f1 <<" = " << f2+f1 << endl;

  f3= 1 + f3;
  cout << "f3 = " << "1 + " << f3 <<" = " << 1+f3 << endl; 

  f3 = -f2;
  cout << "f3 = -f2   " << f3 << endl;
  cout << "f3 = " << f3 << ", " << "f2 = " << f2 << endl; 
  f1 = f3 = Fraction(f2) * Fraction(1);
  cout << (f1 == f3 ? "f1 == f3" : "f1 != f3") << endl;
  cout << (f2 == -f3 ? "f2 == -f3" : "f2 != -f3") << endl;
  
#ifndef BASIC
  cout << "********** Sortowanie ulamkow *************" << endl;

  FVector vec {f1*f2}; // zalecane skorzystanie z std::vector
  vec += Fraction(3, -9);
  vec += f2; //dodanie elementu
  vec += f2+f1;
  cout << "Przed posortowaniem: " << vec;
  vec.sort();
  cout << "Po posortowaniu: " << vec;
#endif

  return 0;
}

/* Oczekiwany wynik
////////////  wersja basic ///////////
Ułamki po skróceniu w konstruktorze:
f1 = 3/4
f2 = -3/2
f3 = 3
f4 = -2
Ułamek dziesiętny f1: 0.75
**********  Prosta arytmetyka *************
f4 = -3/2 * 3/4 * -2 = 9/4
f5 = -3/2 * 9/4 = -27/8
f3 = -27/8 * 4 = -27/2
f3 = -27/8 * 4 = -13.5
f1 + f2 = -3/2 + 3/4 = -3/4
f3 = 1 + -25/2 = -23/2
f3 = -f2   3/2
f3 = 3/2, f2 = -3/2
f1 == f3
f2 != -f3

////////////  wersja pełna ///////////
Ułamki po skróceniu w konstruktorze:
f1 = 3/4
f2 = -1 1/2
f3 = 3
f4 = -2
Ułamek dziesiętny f1: 0.75
**********  Prosta arytmetyka *************
f4 = -1 1/2 * 3/4 * -2 = 2 1/4
f5 = -1 1/2 * 2 1/4 = -3 3/8
f3 = -3 3/8 * 4 = -13 1/2
f3 = -3 3/8 * 4 = -13.5
f1 + f2 = -1 1/2 + 3/4 = -3/4
f3 = 1 + -12 1/2 = -11 1/2
f3 = -f2   1 1/2
f3 = 1 1/2, f2 = -1 1/2
f1 == f3
f2 != -f3
********** Sortowanie ulamkow *************
Przed posortowaniem: [2 1/4, -1/3, -1 1/2, -3] 
Po posortowaniu: [-3, -1 1/2, -1/3, 2 1/4] 
*/
