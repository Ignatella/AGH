/* Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał
   a wynik jego działania był taki sam, jak podany na końcu tego pliku.

 * Częsta alokacja małych obiektów może być przyczyną niewydajnosci programów.
   W zadaniu mamy do czynienia z klasą kontenera pamięci, 
   ktorej obiekty chcemy alokować pojedynczo w większej ilości.

 * Należy zdefiniować klasę Container i przeciążyć operatory new, new[], delete, delete[],
   tak aby alokacja odbywała się w miarę potrzeby jednorazowo, a późniejsze wytworzenia 
   obiektów używały raz zaalokowanego, większego obszaru pamieci (tu tablicy int).
   Składnikiem klasy Container jest pojedynczy integer (prywatny), 
   do którego mamy dostęp za pomocą funkcji składowej value()
   Wskaźnik do zaalokowanego kontenera pamięci oraz jego zajętość są przechowywane 
   w zmiennych statycznych mem_ptr oraz mem_size
   (zdecyduj, czy lepiej zdefiniować je globalnie czy jako statyczne składowe klasy)
   MEM_MAX to stała globalna o wartości 100 - wielkość fizycznie alokowanego obszaru pamięci. 
   
   new Container(10) to zaalokowanie jednego elementu o wartości 10.
   new Container[10] to zaalokowanie wektora dziesięciu elementów o wartości 0 (konstruktor domyślny) 
   
   Przeładowany operator new/new[] ma:
   * sprawdzać, czy trzeba fizycznie zaalokować pamięć (mem_size=0, mem_ptr=0), w przypadku alokacji
     wypisać komunikat: "Pierwszy obiekt na stercie - alokuje kontener na 100 elementow",
   * sprawdzać, czy kontener nie jest pełny (mem_size=MEM_MAX), wypisać komunikat, wykorzystać throw(),
   * zmodyfikować mem_size oraz ustawiać wskaźnik w oparciu o mem_size i mem_ptr,
   * wypisać informacje typu: "--- Alokuje [10] --- Wolne miejsca: 90".
   
   Przeładowany operator delete/delete[] ma:
   * modyfikować mem_size,
   * w razie potrzeby usuwać kontener (mem_ptr)
     i wypisać komunikat: "Ostatni obiekt na stercie, zwalniam kontener",
   * wypisać informacje typu: "--- Zwalniam [10] --- Wolne miejsca: 10".

 * W powyższym rozwiązaniu należy samemu zadbać o usunięcie pamięci, 
   przez wywołanie delete. Nieusunięcie choć jednego wskaźnika skutkuje wyciekiem pamięci.
   Dlatego zdefiniuj drugą, prostą klasę ContainerAutoCleaner, dostarczajacą semantyki wskaźnika,
   ale dbajacą o usunięcie w destruktorze pamięci przy wyjściu z zakresu.
   Klasa posiada wskaźnik na Container, powinna miec przeładowany operator->, 
   konstruktor kopiuje wskaźnik, a destruktor zwalnia pamięć.
   Dla uproszczenia zdefiniuj tę klasę w pliku container.h

* Zadanie jest podzielone na etapy:
  1) Zdefiniowanie new i delete (Podstawa)
  2) Zdefiniowanie new[] i delete[] (Blok 1)
  3) Zdefiniowanie klasy ContainerAutoCleaner (Blok 2)
  Zadanie można wykonać częściowo w kombinacjach:
  Podstawa, Podstawa + Blok 1 albo Podstawa + Blok 2, odpowiednio zakomentowując Blok 1, Blok 2.

* Proszę pamietać o dokumentacji kodu.
 * Skonfiguruj plik konfiguracyjny cmake albo napisz Makefile tak, aby:
   - plikiem wynikowym był main
   - program kompilował się z flagami -Wall - pedantic.
   - były zdefiniowane cele użytkownika run, clean, check oraz all (main+run)

 * Kody źródłowe powinny znajdować się w katalogu nazwisko_lab12 
 * do którego nikt oprócz właściciela nie ma praw dostępu.
 * UWAGA! Wysyłamy spakowany katalog, nie oddzielne pliki!!!!!!
 * Wcześniej kasujemy niepotrzebne pliki.
 
 * Podczas wykonywania zadania nie wolno korzystać z internetu, notatek,
 * ani żadnych innych materiałów. 
 */
 
#include <iostream>
#include "container.h"


int main() {
//Podstawa
  Container* a = new Container(12);
  Container* b = new Container(13);
  // std::cout << "Pierwszy element: " << (b->mem_ptr)->value() << std::endl; //działa jesli mem_ptr jest statyczną składową klasy
  delete a;
  delete b;

  std::cout<<"\n*** Nowa alokacja ***\n";
  Container* x1 = new Container(10);
  std::cout << "x1 ="<< x1->value() << std::endl;
  Container* x2 = new Container(13);
  std::cout << "\n*** Manipulacje na pamieci ***" << std::endl; 
  x2->value() = 55;
  std::cout << "x2 = "<< x2 -> value() << std::endl; 
  std::cout << "x2-1 = "<< (x2-1) -> value() << std::endl; // normalnie takiej operacji nie powinnismy wykonywac
  std::cout << "x2+1 = "<< (x2+1) -> value() << std::endl;

// // Blok 1- alokacja z wykorzystaniem new[] w przypadku braku zakomentuj ten fragment
  Container* w1 = new Container[18];
  Container* w2 = new Container[50];
  Container* w3 = new Container[30];
//   // Container* x3 = new Container(30);  //Po odkomentowaniu powinien zgłosić wyjątek/segmentation fault
//   std::cout << "Pierwszy element: " << (w1->mem_ptr)->value() << std::endl;  //działa jesli mem_ptr jest statyczną składową klasy

  // std::cout << "\n*** Sprzatanie ***" << std::endl;
  // delete [] w1;
  // delete [] w2;
  // delete [] w3;
/*koniec Bloku 1 - alokacji z wykorzystaniem new[] */

//   delete x1;
//   delete x2;
//   std::cout<<"\n*** Nowa alokacja ***\n";
//   delete new Container(3);
//   std::cout << "*** Posprzatane ***" << std::endl;

//   // Blok 2 -  w razie braku czasu zakomentować i dokończyć w domu
//   { //Zakomentuj nawiasy i porównaj wyniki
//     std::cout << "\n*** Test klasy ContainerAutoCleaner ***" << std::endl;
//     ContainerAutoCleaner sm(new Container(51));
//     std::cout << "sm = " << sm -> value() << std::endl;
//     sm->value()++;
//     std::cout << "sm = " << sm -> value() << std::endl;
//   }
  /* Koniec Bloku 2 */
  std::cout << "*** KONIEC ***" << std::endl;
  return 0;
}

/* Oczekiwany wynik ./main
Pierwszy obiekt na stercie - alokuje kontener na 100 elementow  //komunikat operatora new
--- Alokuje 1 --- Wolne miejsca: 99
Container(int) 12       // komunikat konstruktora
--- Alokuje 1 --- Wolne miejsca: 98
Container(int) 13
--- Zwalniam 1 --- Wolne miejsca: 99    //komunikat operatora delete
--- Zwalniam 1 --- Wolne miejsca: 100
Ostatni obiekt na stercie, zwalnia kontener

*** Nowa alokacja ***
Pierwszy obiekt na stercie - alokuje kontener na 100 elementow
--- Alokuje 1 --- Wolne miejsca: 99
Container(int) 10
x1 =10
--- Alokuje 1 --- Wolne miejsca: 98
Container(int) 13

*** Manipulacje na pamieci ***
x2 = 55
x2-1 = 10
x2+1 = 0
--- Alokuje [18] --- Wolne miejsca: 80
--- Alokuje [50] --- Wolne miejsca: 30
--- Alokuje [30] --- Wolne miejsca: 0

*** Sprzatanie ***
--- Zwalniam [18] --- Wolne miejsca: 18
--- Zwalniam [50] --- Wolne miejsca: 68
--- Zwalniam [30] --- Wolne miejsca: 98
--- Zwalniam 1 --- Wolne miejsca: 99
--- Zwalniam 1 --- Wolne miejsca: 100
Ostatni obiekt na stercie, usuwa kontener

*** Nowa alokacja ***
Pierwszy obiekt na stercie - alokuje kontener na 100 elementow
--- Alokuje 1 --- Wolne miejsca: 99
Container(int) 3
--- Zwalniam 1 --- Wolne miejsca: 100
Ostatni obiekt na stercie, zwalniam kontener
*** Posprzatane ***

*** Test klasy ContainerAutoCleaner ***
Pierwszy obiekt na stercie - Alokuje kontener na 100 elementow
--- Alokuje 1 --- Wolne miejsca: 99
Container(int) 51
sm : 51
sm : 52
~ContainerAutoclean       // komunikat destruktora klasy ContainerAutoCleaner
--- Zwalniam 1 --- Wolne miejsca: 100
Ostatni obiekt na stercie, zwalniam kontener
*** KONIEC ***
 */
