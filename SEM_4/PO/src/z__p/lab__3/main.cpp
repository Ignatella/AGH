/*
Prosze napisac klase ComplexNumber, ktora reprezentuje liczbę zespoloną.
Metody post- i preinkrementacji zwiekszaja o 1 tylko czesc rzeczywista liczby zespolonej.
Iloczyn liczb zespolonych nalezy obliczyc korzystajac ze wzoru:
(A1 + i*A2)*(B1 + i*B2) = A1*B1 - A2*B2 + i*(A1*B2 + A2*B1)
Porownujac dwie liczby zespolone prosze porownac ich moduły, czyli wartości
R = re*re + im*im.
UWAGA!!!
Po odkomentowaniu #DEFINE ERROR, powinien pojawić się błąd kompilacji dokladnie w tej linii. Brak blędu oznacza -2 punkty.
*/

#include <iostream>
#include "ComplexNumber.h"

//#define ERROR

int main()
{
  using namespace std;

  const ComplexNumber Z1(2., 8);
  const ComplexNumber Z2(1, 16.);

  ComplexNumber Z3 = static_cast<ComplexNumber>(3); // im=0
#ifdef ERROR
  ComplexNumber Z3_ = 3.;
#endif

  cout << "Z1: " << Z1 << "\nZ2: " << Z2 << "\nZ3: " << static_cast<double>(Z3) << "\n";

  cout << "\n*** Dodawanie ***\n";
  ComplexNumber S1 = Z1 + Z2,
                S2 = 1 + ComplexNumber(0, 2);
  cout << "S1: " << S1 << "\nS2: " << S2 << "\n";

  const ComplexNumber &S2Ref = S2 = S1 = Z1 * Z2;
  cout << "S1: " << S1 << "\tS2: " << S2 << "\tS2Ref: " << S2Ref << "\n";

  cout << "\n*** S2*=3 ***\n";
  S2 *= 3;
  cout << "S1: " << S1 << "\tS2: " << S2 << "\tS2Ref: " << S2Ref << "\n";

  ComplexNumber S3(ComplexNumber(2, -1) + Z1 * Z2 - (S2++) + (++S1));
  cout << "S1: " << S1 << "\tS2: " << S2 << "\tS3: " << S3 << "\n";

  // cout << Z1 * Z2 << "           " << S2 << "      " << S1 << std::endl;

  cout << "\n*** Zmniejszamy IM: S3[IM]-=3 ***\n";
  S3[(Z1 < S3) ? 1 : 0] -= 3; // równoznaczne z S3[1] += 3;
  cout << "S3: " << S3 << "\n";

  cout << "*** Zmniejszamy RE: S3[RE]-=5 ***\n";
  S3[(S3 < Z1) ? 1 : 0] -= 5; // równoznaczne z S3[0] += 5;
  cout << "S3: " << S3 << "\n";

  return 0;
}
/*
Z1: 2 + 8i
Z2: 1 + 16i
Z3: 3
*** Dodawanie ***
S1: 3 + 24i
S2: 1 + 2i
S1: -126 + 40i  S2: -126 + 40i  S2Ref: -126 + 40i
*** S2*=3 ***
S1: -126 + 40i  S2: -378 + 120i S2Ref: -378 + 120i
S1: -125 + 40i  S2: -377 + 120i S3: 128 + -41i
*** Zmniejszamy IM: S3[IM]-=3 ***
S3: 128 + -44i
*** Zmniejszamy RE: S3[RE]-=5 ***
S3: 123 + -44i
*/