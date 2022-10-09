/*
  Tematem zadania sa szablony funkcji ze specjalizacją. Zastosowane sa tutaj szablony o argumentach, ktore nie sa typami. Małą trudność może sprawic przekazanie tablicy o znanym rozmiarze jako argument funkcji.
  Zadanie można wykonać w klasie albo przestrzeni obj
 */

#include <iostream>
#include "obj.h"
int main()
{
  const int a[6] = {2, 4, 5, 7, 9, 10};
  const double aS1 = obj::srednia<int>(a, 6);
  const double aS2 = obj::srednia(a);
  const int aMin = obj::min(a, 6);
  const int aMax = obj::max(a);
  const int aMin2 = obj::min(a[4], a[1]);
  const int *aMax2 = obj::max(a + 4, a + 1);
  std::cout << "Srednia z int: " << aS1 << " " << aS2 << std::endl;
  std::cout << "Min: " << aMin << " Max: " << aMax << " Min2: " << aMin2 << " Max2: " << *aMax2 << std::endl;

  double d[5] = {0, 0.7, 9.1, 3.1, 2.2};
  const double dS1 = obj::srednia<double>(d, 5);
  const double dS2 = obj::srednia(d);
  const double dMin = obj::min(d);
  const double dMax = obj::max(d, 5);
  double *dMin2 = obj::min(d + 1, d + 3);
  double dMax2 = obj::max(*(d + 1), *(d + 3));
  std::cout << "Srednia z double: " << dS1 << " " << dS2 << std::endl;
  std::cout << "Min: " << dMin << " Max: " << dMax << " Min2: " << *dMin2 << " Max2: " << dMax2 << std::endl;

  const double e[5] = {0, 0.7, 9.1, -3.1};
  const double eS1 = obj::srednia<double>(e, 5);
  const double eS2 = obj::srednia(e);
  const double eMin = obj::min(e);
  const double eMax = obj::max(e);
  std::cout << "Srednia z const double: " << eS1 << " " << eS2 << std::endl;
  std::cout << "Min: " << eMin << " Max: " << eMax << std::endl;

  const bool wp = obj::czyWszystkiePierwsze<2, 6>(a); // wszystkie miedzy indeksami [2, 6]
  bool wnp = obj::czyWszystkiePierwsze<2, 4>(a);      // wszystkie miedzy indeksami [2, 4]
  std::cout << "Czy wszystkie liczby w zakresie pierwsze: " << obj::text(wp) << " " << obj::text(wnp) << std::endl;

  try
  {
    wnp = obj::czyWszystkiePierwsze<4, 2>(a);  // błąd - kolejność indeksów
    wnp = obj::czyWszystkiePierwsze<4, 12>(a); // błąd - indeksy spoza zakresu
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }

  // dla wytrwałych (3 punkty)
  const char *s[] = {"Ula", "Ala", "Ania", "Zuza", "Piotr", "Kuba"};
  std::cout << "Max1: " << obj::max(s[0], s[2]) << " Max2: " << obj::max(s[2], "Ada") << " Max3: " << obj::max(s, 6) << std::endl;
  std::cout << "Min1: " << obj::min(s[0],s[2]) << " Min2: " << obj::min(s[2],"Ada") << " Min3: " << obj::min(s,6) << std::endl;

  return 0;
}

/* oczekiwany wynik
Srednia z int: 6.16667 6.16667
Min: 2 Max: 10 Min2: 4 Max2: 9
Srednia z double: 3.02 3.02
Min: 0 Max: 9.1 Min2: 0.7 Max2: 3.1
Srednia z const double: 1.34 1.34
Min: -3.1 Max: 9.1
Czy wszystkie liczby w zakresie pierwsze: FALSE TRUE
Nieprawidlowy zakres!
Nieprawidlowy zakres!
Max1: Ula Max2: Ania Max3: Zuza
// Min1: Ania Min2: Ada Min3: Ala
*/
