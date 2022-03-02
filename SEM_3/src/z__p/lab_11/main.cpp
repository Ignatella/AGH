/* Celem zadania jest przećwiczenie konwersji jawnych i niejawnych oraz jak im zapobiegać.
Proszę napisać klasę Vector, reprezentującą wektor n-wymiarowy.
Ma on metody wyliczające:
 - sum: sumę dwóch wektorów - uwaga, przy dodawaniu wektorów o różnych wymiarach, wektor krótszy traktujemy, jakby był rozszerzony
 do wielkości wektora dłuższego i uzupełniony o zera.
 - dot: iloczyn skalarny dwóch wektorów
		v * w = v1*w1 + v2*w2 + ... + vn*wn
 - norm: normę wektora
		|v| = sqrt( v1*v1 + v2*v2 + ... + vn*vn )
 - extended - powiększenie wektora do nowego rozmiaru z uzupełnieniem zerami
 - operator konwersji na double: zwraca normę
 - print do wypisania wektora

 UWAGA
 Konstruktor może przyjmować zarówno int, jak i double:
   int - ustala rozmiar vektora i wypełnia go zerami
   double - tworzy jednowymiarowy wektor o wartości double
 Blok error ma się nie kompilować i zgłaszać dwa błędy - sprawdz: make error albo odkomentuj linię #define ERROR (za brak -1.5 pkt)
 Wymagane utworzenie konstruktora przenoszącego (za brak -1 pkt)
*/

#include <iostream>
#include "Vector.h"

// Uruchomienie make error lub odkomentowanie poniższej linii MUSI powodować błąd kompilacji (w przeciwnym razie odejmowane są punkty)
// #define ERROR
int main()
{
	Vector v1(3), v0(3.);
	const Vector v2(4);

	v1.vec(0) = 4;
	v1.vec(1) = 1;
	const Vector v3 = v1;
	v1.vec(1) = 2;

	v1.print("v1 = ");
	v2.print("v2 = ");
	v3.print("v3 = ");
	v0.extended(4).print("v0 = ");
	v0.print("v0 = ");

	double prod = Vector::dot(v1, v3);
	std::cout << "Iloczyn skalarny v1 i V2: " << prod << std::endl;

	double norm = static_cast<double>(v3); // == v3.norm();
	std::cout << "Norma wektora |v3| = " << norm << ", " << v3.norm() << std::endl;

	Vector v4 = Vector::sum(v1, v3);
	v4.print("v1 + v3 = ");

	Vector v5 = std::move(Vector::sum(v1.extended(4), v2));
	v5.print("v1 + v2 = ");

	Vector::sum(v1, static_cast<Vector>(3.)).print("v1 + [3] = ");

	Vector v6 = Vector::sum(static_cast<Vector>(3.5), v3);
	v6.print("[3.5] + v3 = ");
	std::cout << std::endl;

#ifdef ERROR // make error - mają być dwa błędy
	Vector s = Vector::sum(v1, 3.5);
	Vector z = 5;
#endif
}
/* oczekiwany wynik

v1 = [4, 2, 0]
v2 = [0, 0, 0, 0]
v3 = [4, 1, 0]
v0 = [3, 0, 0, 0]
v0 = [3]
Iloczyn skalarny v1 i V2: 18
Norma wektora |v3| = 4.12311, 4.12311
v1 + v3 = [8, 3, 0]
v1 + v2 = [4, 2, 0, 0]
v1 + [3] = [7, 2, 0]
[3.5] + v3 = [7.5, 1, 0]

*/