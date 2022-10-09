/*
  Celem zadania jest napisanie plimorficznego wektora. 
  W wektorze tym trzymac bedziemy wskazniki do obiektow pewnej hierarchii klas.
  Klasa nadrzędna tej hierarchii posiada pole nazwy "Wrappera" i metody wirtualne. 
  Wszystkie nagłówki klas hierarchicznych proszę zdefiniować w jednym pliku.
 */

#include <iostream>

#include "Wrapper.h"
#include "PVec.h"

int main()
{
  PVec a;
  PVec b;
  b.push_back(new IntWrapper(54))
      .push_back(new IntWrapper(14))
      .push_back(new IntWrapper(-76));

  std::cout << b;
  b.printType();

  a << new IntWrapper(45);
  a << new FloatWrapper(23.67);
  a << new FloatWrapper(12.67);
  a << new StringWrapper("Iks");
  a << new IntWrapper(1234);
  a << new StringWrapper("Koniec!");

  std::cout << const_cast<PVec &>(a);
  a[3].print(std::cout);
  std::cout << std::endl;
  std::cout << a[3].type() << std::endl;
  std::cout << "--- Testujemy operator ++" << std::endl;
  for (int i = 0; i < a.size(); i++)
    a[i]++;
  std::cout << a;
  a.printType();
  std::cout << std::endl;
}

/* oczekiwany output

[ 54 14 -76 ]
[ Int Int Int ]
[ 45 23.67 12.67 Iks 1234 Koniec! ]
Iks
String
--- Testujemy operator ++
[ 46 24.67 13.67 IKS 1235 KONIEC! ]
[ Int Float Float String Int String ]

*/