/* Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał
   a wynik jego działania był taki sam, jak podany na końcu tego pliku.

   Celem zadania jest napisanie kilku klas związanych relacją
   dziedziczenia.  Klasy te opisują elementarne kształty. Każdy kształt
   ma jakieś polimorficzne metody i konieczną infrastrukturę.

   UWAGA: Przed rozpoczeciem zadania proszę przeanalizować kod programu do końca.
   Wskazówka: Wzor na pole trojkata: sqrt(x(x-a)(x-b)(x-c))
   gdzie "x" to połowa obwodu trójkata.

 * Proszę pamietać o dokumentacji kodu.
 * Skonfiguruj plik konfiguracyjny cmake albo napisz Makefile tak, aby:
   - plikiem wynikowym był main
   - program kompilował się z flagami -Wall -g - pedantic.
   - były zdefiniowane cele użytkownika run, clean, check oraz all (main+run)
 */

#include <iostream>
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"

int main()
{
  Rectangle r(4, 2);
  Triangle t(3, 2, 4);
  const Circle c(3);

  print(r); // Prostokat o bokach: 4 2
  print(t); // Trojkat o bokach: 3 2 4
  print(c); // Kolo o promieniu: 3

  Shape *b = new Rectangle(7, 2);
  print(*b);
  delete b;

  b = new Circle(7);
  print(*b);
  delete b;

  const Shape *all[] = {&r, &r, &c, &t, &c}; // obiekty powtorzone celowo
  for (unsigned idx = 0; idx < sizeof(all) / sizeof(Shape *); ++idx)
  {
    const Shape *k = all[idx];
    k->print(std::cout);
    std::cout << k->area() << std::endl;
  }
}
/* Oczekiwany wynik ./main
Prostokat o bokach: 4 2
Trojkat o bokach: 3 2 4
Kolo o promieniu: 3
Prostokat o bokach: 7 2
Kolo o promieniu: 7
Prostokat o bokach: 4 2
8
Prostokat o bokach: 4 2
8
Kolo o promieniu: 3
28.2743
Trojkat o bokach: 3 2 4
2.90474
Kolo o promieniu: 3
28.2743

 */
