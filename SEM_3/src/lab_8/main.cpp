/* Proszę zdefiniować klasę Student, reprezentującą studenta oraz klasę Grade reprezentującą ocenę danego studenta. 
 Klasa Grade oprócz oceny zawiera również opis oceny (w tym wypadku przedmiot) oraz identyfikator nadawany automatycznie od 1.
 Każdy student ma numer ID nadawany w konstruktorze. Student może mieć wiele ocen.

 UWAGA!!!
 W zadaniu nie wolno używać mutable. Użycie go oznacza 0 punktow za zadanie.

 UWAGA!!!
 Tablice powinny dostosowywać swój rozmiar do liczby przechowywanych obiektów.

 Pliku Main.cpp, nie wolno modyfikować.
*/

#include <iostream>
#include "Grade.h"
#include "Student.h"

int main()
{

  std::cout << "DANIEL\n";
  const Student daniel(2);
  daniel.print();

  const Grade danielMath("Matematyka", 4, daniel);
  daniel.print();

  const Grade danielPhysics("Fizyka", 5, daniel);
  daniel.print();
  danielMath.print();
  danielPhysics.print();

  std::cout << "\nMAREK\n";
  const Student marek(3);
  marek.print();

  const Grade marekPhysics("Fizyka", 3.5, marek);
  marek.print();
  marekPhysics.print();

  std::cout << "\nDANIEL i MAREK\n";
  marek.print();
  daniel.print();

  return 0;
}

/* Oczekiwany output:
DANIEL
Student ID=2 oceny:
Student ID=2 oceny: 4
Student ID=2 oceny: 4 5
ID=1 Matematyka ocena=4 student_ID=2
ID=2 Fizyka ocena=5 student_ID=2

MAREK
Student ID=3 oceny:
Student ID=3 oceny: 3.5
ID=3 Fizyka ocena=3.5 student_ID=3

DANIEL i MAREK
Student ID=3 oceny: 3.5
Student ID=2 oceny: 4 5
*/
