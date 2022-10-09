/* Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał
   a wynik jego działania był taki sam, jak podany na końcu tego pliku.
   Celem zadania jest przećwiczenie operatora[] oraz
   operatora() i jego wykorzystania w połączeniu z std::function.

   Proszę zdefiniować trzy klasy reprezentujące funkcje matematyczne:
   - Linear -- funkcja liniowa a*x+b
   - Sqrt -- pierwiastek z liczby
   - Sin -- sin(a*x+b)

   Mają one przeciążony operator(), który zwraca odpowiednią wartość funkcji.
   Proszę zdefiniować je we wspólnych plikach funtions.h i funtions.cpp

   Proszę także zaimplementować klasę FunctionVector, która przyjmuje
   i przechowuje obiekty funkcyjne oraz pozwala na rekursywne obliczenie
   wyniku kolejnych wywołań, np. dla trzech funkcji w wektorze:
      FunctionVector f;
      f.insert(f1); f.insert(f2); f.insert(f3)  //  f = [f1, f2, f3]
      f.calc(x) = f3 (f2 (f1(x)))
   oraz zwraca wyniki pośrednich obliczeń przez operator[]
      f[0] = f1(x)
      f[1] = f2 (f1(x))
      f[2] = f3 (f2 (f1(x)))
   UWAGA: zalecane użycie std::vector

 * Pliku main.cpp, NIE WOLNO modyfikować bez zgody prowadzącego.
 * Proszę pamietać o dokumentacji kodu.
 * Skonfiguruj plik konfiguracyjny cmake albo napisz Makefile tak, aby:
   - plikiem wynikowym był main
   - program kompilował się z flagami -Wall -g - pedantic.
   - były zdefiniowane cele użytkownika run, clean, check oraz all (main+run)

 * Kody źródłowe powinny znajdować się w katalogu nazwisko_lab13
 * do którego nikt oprócz właściciela nie ma praw dostępu.
 * UWAGA! Wysyłamy spakowany katalog, nie oddzielne pliki!!!!!!
 * Wcześniej kasujemy niepotrzebne pliki.

 * Podczas wykonywania zadania nie wolno korzystać z internetu, notatek,
 * ani żadnych innych materiałów.
*/

#include "functions.h"
#include "functionVector.h"
#include <iostream>
#define _USE_MATH_DEFINES

double my_abs(double x)
{
  return x >= 0 ? x : -x;
}

int main()
{
  Linear lin(-0.25, -1.);
  const Sqrt squareroot;
  Sin sinus(M_PI, M_PI / 3.);

  double x = 10;
  std::cout << "\n*** Wyniki pojedynczych funkcji dla x=10 *** " << std::endl;
  std::cout << "Sinus:\t\t" << sinus(x) << std::endl;
  std::cout << "Pierwiastek:\t" << squareroot(x) << std::endl;
  std::cout << "Funkcja liniowa: " << lin(x) << std::endl;

  FunctionVector fs;
  fs.insert(sinus);
  fs.insert(squareroot);
  fs.insert(lin);
  fs.insert(my_abs);

  // test operatora () do zagnieżdżania funkcji
  double result1 = fs.calc(x);
  double result2 = my_abs(lin(squareroot(sinus(x))));
  std::cout << "\n*** Obliczamy abs(-0.25*sqrt(sin(pi*x+pi/3))+1) *** " << std::endl;
  std::cout << "--- Dla x=10 :\t" << result1 << ", " << result2 << std::endl;

  x = 0.5;
  std::cout << "--- Dla x=0.5 :\t" << fs.calc(x) << ", " << my_abs(lin(squareroot(sinus(x)))) << std::endl;

  // test operatora [] zwracającego wyniki paośrednich obliczeń
  std::cout << "\n*** Wyniki posrednie dla x=0.5: *** " << std::endl;
  double sinx = sinus(x);
  std::cout << "--- f1 = sin(pi*x+pi/3): " << sinx << ", " << fs[0] << std::endl;
  std::cout << "--- f2 = sqr(f1):\t" << squareroot(sinx) << ", " << fs[1] << std::endl;
  std::cout << "--- f3 = -0.25*f3+1:\t" << lin(squareroot(sinx)) << ", " << fs[2] << std::endl;
  std::cout << "--- f4 = abs(f3):\t" << my_abs(lin(squareroot(sinx))) << ", " << fs[3] << std::endl;
}
/* Oczekiwany wynik: ./main
*** Wyniki pojedynczych funkcji dla x=10 ***
Sinus:          0.866025
Pierwiastek:    3.16228
Funkcja liniowa: -3.5

*** Obliczamy abs(-0.25*sqrt(sin(pi*x+pi/3))+1) ***
--- Dla x=10 :  1.23265, 1.23265
--- Dla x=0.5 : 1.17678, 1.17678

*** Wyniki posrednie dla x=0.5: ***
--- f1 = sin(pi*x+pi/3): 0.5, 0.5
--- f2 = sqr(f1):       0.707107, 0.707107
--- f3 = -0.25*f3+1:    -1.17678, -1.17678
--- f4 = abs(f3):       1.17678, 1.17678
*/
