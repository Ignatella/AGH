/*
Prosze napisac szablon Power, ktory na etapie kompilacji oblicza  potege danej liczby.
Podstawy poteg jak i wykladniki sa liczbami  calkowitymi, ktore moga przyjmowac wartosci dodatnie i ujemne.
W  przypadku podania wykladnika potegi rownego conajmniej 10, powinien  pojawic sie blad kompilacji z informacja, ze wykladnik jest zbyt  duzy.

UWAGA!
* Wszystkie obliczenia powinny wykonywac sie na etapie  kompilacji. Jezeli obliczenia nie beda wykonywane w czasie  kompilacji,
  rozwiazanie bedzie nie na temat i nie będzie miało wartości punktowej.
* Po odkomentowaniu ERROR powinien pojawic sie blad kompilacji, ktory w swoim komunikacie bedzie zawieral
  tresc "TooLargeNumberMustBeSmallerThan10".

*/

// #include"Main.h"
#include <iostream>
#include <exception>

// #define ERROR

template <int x>
struct ERR_MSG
{
};

template <int x, int a>
struct Power
{
  static_assert(a < 9, "TooLargeNumberMustBeSmallerThan10");

  static constexpr inline int getV()
  {
    if constexpr (a > 0)
    {
      return x * Power<x, a - 1>::Value;
    }

    return 0;
  }

  static const int Value = getV();
};

template <int x>
struct Power<x, 0>
{
  static const int Value = 1;
};

int main()
{
  std::cout << "Values\n";
  std::cout << "3^4 = " << Power<3, 4>::Value << "\n";
  std::cout << "3^(-4) = " << Power<3, -4>::Value << "\n";
  std::cout << "4^0 = " << Power<4, 0>::Value << "\n";
  std::cout << "(-2)^3 = " << Power<-2, 3>::Value << "\n";

  ERR_MSG<Power<-2, 3>::Value> msg1;

#ifdef ERROR
  std::cout << "1^10 = " << Power<1, 10>::Value << "\n";
#endif

  return 0;
}
/*
Values
3^4 = 81
3^(-4) = 0
4^0 = 1
(-2)^3 = -8
*/