/*
Celem zadania jest przećwiczenie różnego rodzaju konwersji  oraz definicji prostych operatorów +, *, [] oraz =
Zadanie jest częściowo kontynuacją zadania z poprzednich zajęć, więc można z niego skorzystać, wprowadzając odpowiednie zmiany i kasując niepotrzebne funkcje.
Klasa liczb zespolonych posiada prywatne re i im oraz niezbędne konstruktory, operatory konwersji i operatory +, =. Proszę zdefiniować operaror + wewnątrz klasy, wówczas nie będziemy musieli korzystać z getRe i getIm.

Klasa Vector tworzy dynamicznie wektor o zadanym rozmiarze i wypełnia go zerami (nie wolno korzystać z std::vector). 
Konstruktor przyjmujący dwie wartości double będzie przydatny w konwersji Complex -> Vector, kiedy to tworzymy wektor dwuwymiarowy [re,im]. 
Z kolei konwersja Vector -> Complex tworzy z wektora dwuwymiarowego liczbę zespoloną.
Ponadto definiujemy:
norm: norma wektora
		|v| = sqrt( v1*v1 + v2*v2 + ... + vn*vn )
operator konwersji na double: zwraca normę
operator [] dostępu do i-tego elementu
operator * : iloczyn skalarny dwóch wektorów 
		v * w = v1*w1 + v2*w2 + ... + vn*wn
operator + sumuje wszystkie składowe wektora
    v + w = [v1+w1, v2+w2, v3+w3]
W przypadku dodawania wektorów o różnych wymiarach, ten mniejszy traktowany jest, jakby został dopełniony zerami
wskazówka - jeśli operaror[] wyjdzie poza zakres wektora, zwróć zero - jest to najprostszy sposób rozwiązania tego problemu.
Warto też korzystać ze skróconego if: r = ((a>b) ? a : b)
Operatory + i * proszę zdefioniować poza klasą.
Część BASIC jest na maksymaknie 5-6 punktów.

W części ostatniej w zespolonych dodajemy pole licznika zliczającego każde wydrukowanie obiektu na ekran.
UWAGA -  licznik ten musi być elementem klasy i nie może być mutable - za użycie go zostaną odjęte punkty.
Dodatkowo definiujemy operator = dla klasy Vector oraz dodajemy nową wersję operatora [], który pozwoli na zmianę wartości w obiekcie const.

Wszyskie proste konstruktory z listami inicjalizacyjnymi i destruktory,gettery, settery proszę zdefiniować w pliku nagłówkowym. 
Proszę pamiętać o porządku w kodzie.

Proszę nie zapomnieć o make error - powinno zwrócić dwa błędy konwersji oraz o właściwym gospodarowaniu pamięcią w klasie Vector.
*/

#include <iostream>
#include "Vector.h"
#include "Complex.h"

// #define ERROR

int main() {
//////////////////////////////////////////////////////////
  std::cout << "\n*** WEKTOR ***"<< std::endl;
  // using vector::Vector;
	
  Vector V1(3),V2(2);	// wektor o podanym wymiarze, zainicjowany zerami
	const Vector V0(3.,2.);	//wektor duwymiarowy, zainicjowany wartościami double

	V1[0] = 4;
	V1[1] = 3;
	const Vector V3 = V1;
	V1[1] = 2;

	V1.print("V1 = ");
	V2.print("V2 = ");
	V3.print("V3 = ");
  V0.print("V0 = ");
  
	double norm = static_cast<double>(V3); // == v3.norm();
	std::cout << "Norma wektora |V3| = " << norm << ", " << V3.norm() << std::endl;

  double prod = V1 * V3; 
	std::cout << "Iloczyn skalarny V1 * V3: " << prod << std::endl;  
	
	Vector V4 = V1+V3; 
	V4.print("V1 + V3 = ");

	(V1+Vector(3.,1.)).print("V1 + [3,1] = ");

/////////////////////////////////////////////////////////
  std::cout << "\n*** ZESPOLONE ***"<< std::endl;
  // using complex::Complex;

  Complex Z1 = Complex(1, 5) + static_cast<Complex>(4);
  Z1.print("Z1 = ");
  
  const Complex Z2 = static_cast<Complex>(V3);
  Z2.print("Z2 = "); 
  (Z1+Z2).print("Z1 + Z2 = ");

  Complex Z3 = static_cast<Complex>(Vector(2.5, 3.5)) + static_cast<Complex>(Vector(1.5, 3.));  
  Z3.print("Z3 = ");

  Complex Z4(std::move(Z3));
  Z3.print("Z3 = ");
  (Z4 + Z1).print("Z4 + Z1 = ");

  Z3 = 1.5 + 2.5; // te dwie linie ew. mogę pozwolić zakomentować
  Z3.print("Z3 = "); // ale wynik < 50%

//////////////////////////////////////////////////////
// #ifndef BASIC  // można komentować pojedyncze linie
  std::cout << "\n*** WEKTOR I ZESPOLONE ***"<< std::endl;
  V2 = static_cast<Vector>(Complex(3.5)) + V3;
	V2.print("[3.5] + v3 = ");
  const Vector  V5 = Z1 + Z3;
  V5.print("V5 = ");
  V5[1]=1.5;
  V5.print("V5 = ");
  V4 = Complex(3.5,2.) + Z3;
  V4.print("V4 = ");
  V4 = Vector(std::move(V2));
  V4.print("V4 = ");
  V2.print("V2 = ");
  Z3 = static_cast<Complex>(V1);
  Z3.print("Z3 = ");
// #endif
 
 std::cout << std::endl;
////////////////////////////////////////////////////// 
#ifdef ERROR // make error - dwa błędy konwersji (1p)
	Vector z= 5.;
  Complex x = V1;
#endif
}

/* oczekiwany wynik
--------- wersja BASIC -----
*** WEKTOR ***
V1 = [4, 2, 0]
V2 = [0, 0]
V3 = [4, 3, 0]
V0 = [3, 2]
Norma wektora |V3| = 5, 5
Iloczyn skalarny V1 * V3: 22
V1 + V3 = [8, 5, 0]
V1 + [3,1] = [7, 3, 0]

*** ZESPOLONE ***
Z1 = 5 + 5i
Z2 = 4 + 3i
Z1 + Z2 = 9 + 8i
Z3 = 4 + 6.5i
Z3 = 0
Z4 + Z1 = 9 + 11.5i
Z3 = 4

--------- wersja pełna -----
*** WEKTOR ***
V1 = [4, 2, 0]
V2 = [0, 0]
V3 = [4, 3, 0]
V0 = [3, 2]
Norma wektora |V3| = 5, 5
Iloczyn skalarny V1 * V3: 22
V1 + V3 = [8, 5, 0]
V1 + [3,1] = [7, 3, 0]

*** ZESPOLONE ***
[Print 1] Z1 = 5 + 5i
[Print 1] Z2 = 4 + 3i
[Print 1] Z1 + Z2 = 9 + 8i
[Print 1] Z3 = 4 + 6.5i
[Print 2] Z3 = 0
[Print 1] Z4 + Z1 = 9 + 11.5i
[Print 3] Z3 = 4

*** WEKTOR I ZESPOLONE ***
[3.5] + v3 = [7.5, 3, 0]
V5 = [9, 5]
V5 = [9, 1.5]
V4 = [7.5, 2]
V4 = [7.5, 3, 0]
V2 = []
[Print 4] Z3 = 4 + 2i
*/
