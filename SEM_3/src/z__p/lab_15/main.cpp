/*
Celem zadania jest przećwiczenie różnego rodzaju konwersji  oraz definicji własnych przestrzeni nazw.
Zadanie jest kontynuacją zadania z poprzednich zajęć, więc można z niego skorzystać.
Prosze jednak wprowadzić istotne zmiany.
Ponadto proszę zdefiniować klasę liczb zespolonych, przechowującej prywatne _re i _im (double) oraz odpowiednie operatory konwersji i konstruktory pozwalające przekonwertować wektor dwuwymiarowy na zespolone i na odwrót

 Ponadto definiujemy nowy niezbędny kod w pliku Double.h (jest krótki, więc bez rozdzielania na cpp). Z uwagi na to, że może niektórym przysporzyć problemów, jest objęty w dyrektywy, ale bez niego za zadanie można dostać maksymalnie 5 punktów.
 Każde wyświetlenie obiektu jest zliczane.
 UWAGA -  licznik ten musi być elementem klasy i nie może być mutable - za użycie go zostaną odjęte punkty.
*/

#include <iostream>
#include "Vector.h"
#include "Complex.h"
#include "Double.h"

// #define ERROR

int main()
{
  //////////////////////////////////////////////////////////
  std::cout << "\n*** VECTOR ***" << std::endl;
  using vector::Vector;

  Vector V1(3), V0(3., 2.);
  const Vector V2(4);

  V1[0] = 4;
  V1[1] = 3;
  const Vector V3 = V1;
  V1[1] = 2;

  V1.print("V1 = ");
  V2.print("V2 = ");
  V3.print("V3 = ");
  V0.extended(4).print("V0 = ");
  V0.print("V0 = ");

  double prod = vector::dot(V1.extended(4), V3);
  std::cout << "Iloczyn skalarny V1 i V3: " << prod << std::endl;

  double norm = static_cast<double>(V3); // == v3.norm();
  std::cout << "Norma wektora |V3| = " << norm << ", " << V3.norm() << std::endl;

  Vector V4 = vector::sum(V1, V3);
  V4.print("V1 + V3 = ");

  Vector V5 = std::move(vector::sum(V1.extended(4), V2));
  V5.print("V1 + V2 = ");

  vector::sum(V1, static_cast<Vector>(3.)).print("V1 + [3] = ");

  Vector V6 = vector::sum(static_cast<Vector>(3.5), V3);
  V6.print("[3.5] + v3 = ");

  // //////////////////////////////////////////////////////////
  std::cout << "\n*** ZESPOLONE ***" << std::endl;
  using complex::Complex;

  Complex Z1 = complex::sum(Complex(1, 5), static_cast<Complex>(4));
  Z1.print("Z1 = ");

  const Complex &Z2 = static_cast<Complex>(V3);
  const_cast<Complex &>(Z2).print("Z2 = "); // print nie musi być const

  Complex Z3 = complex::sum(Vector(2.5, 3.5), Vector(1.5, 3.));
  Z3.print("Z3 = ");

  Complex Z4 = complex::sum(1.5, 2.5);
  Z4.print("Z4 = ");

  Complex Z5(std::move(Z4));
  Z4.print("Z4 = ");
  complex::sum(Z5, Z1).print("Z5+Z1 = ");

//////////////////////////////////////////////////////
#ifndef BASIC
  const Vector V7 = sum(static_cast<Vector>(Z1), static_cast<Vector>(Z3));
  V7.print("V7 = ");
  Vector V8 = sum(2, Z1);
  V8.print("V8 = ");

  std::cout << "\n*****  DOUBLE  *****" << std::endl;
  std::cout << "----- Obiekt x -----\n";
  const Double x{3.};
  print(x);
  x.setconstx(sum(x, x));
  // x.set(sum(x,x)); //zwróci bład
  print(x);
  x.setconstx(sum(x, x));
  x.print();

  std::cout << "----- Obiekt y -----\n";
  Double y = V1;
  y.print();
  y.setx(x);
  print(y);
  y.setx(static_cast<Double>(Vector(4., 3.)));
  print(y);
#endif

  std::cout << std::endl;
  //////////////////////////////////////////////////////

#ifdef ERROR // make error
  Vector s = Vector::sum(v1, 3.5);
  Vector z = 5;
  complex::sum(1.5, 2.5).print();
#endif
}
/* oczekiwany wynik

*** VECTOR ***
V1 = [4, 2, 0]
V2 = [0, 0, 0, 0]
V3 = [4, 3, 0]
V0 = [3, 2, 0, 0]
V0 = [3, 2]
Iloczyn skalarny V1 i V3: 22
Norma wektora |V3| = 5, 5
V1 + V3 = [8, 5, 0]
V1 + V2 = [4, 2, 0, 0]
V1 + [3] = [7, 2, 0]
[3.5] + v3 = [7.5, 3, 0]

*** ZESPOLONE ***
Z1 = 5 + 5i
Z2 = 4 + 3i
Z3 = 4 + 6.5i
Z4 = 4
Z4 = 0
Z5+Z1 = 9 + 5i
V7 = [9, 11.5]
V8 = [7, 5]

*****  DOUBLE  *****
----- Obiekt x -----
Print nr 1. Val = 3
Print nr 2. Val = 6
Print nr 3. Val = 12
----- Obiekt y -----
Print nr 1. Val = 4.47214
Print nr 2. Val = 12
Print nr 3. Val = 5

*/
