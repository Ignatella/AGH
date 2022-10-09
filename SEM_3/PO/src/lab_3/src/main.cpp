/*
  Aby kod dał się skompilować, zdefiniuj na początku wszystkie funkcje 
  z prawidłowymi argumentami i pustą zawartością, a potem sukcesywnie uzupełniaj.
  Nie zapomnij o dokumentacji (w pliku nagłówkowym).

  Opis zadania:
    Numer PESEL reprezentuje 11 cyfr:  YYMMDDXXXPK
    
  * YY-ostatnie dwie cyfry roku w przedziale od 00 do 99
      dla 2010 i 1910 roku będzie to wspólna liczba 10, zmienia się tylko miesiąc
    
  * MM-cyfry miesiąca
      dla 1900-1999 są to 1-12
      dla 2000-2099 są to 21-32 (+20)
      dla 2100-2099 są to 41-52 (+40)
      ----- nie ma potrzeby implementować poniższych------
      powyżej 2200 są to 61-72 (+60)
      dla 1800-1899 są to 81-92, (+80)
    
  * DD-cyfry dnia (w zależności od miesiąca)

  * XXX-liczba ewidencyjna związana z kolejnością urodzeń, 
    P-cyfra płci: podzielna przez 2 - kobieta, niepodzielna - mężczyzna, obie są podane jako napis XXXP

  * K - cyfra kontrolna, algorytm wyliczenia poniżej.

  * Należy zaimlementować funkcje pozwalające wygenerować numer PESEL
    na podstawie daty urodzenia DDMMYYYYY oraz liczby ewidencyjnej 
    i informacji o płci XXXP oraz wyliczonej cyfry kontrolnej K
    
  * Podaną datę w formacie DDMMYYYY należy zweryfikowac pod wzgledem poprawności.
    Jeś==li chodzi o zależność miesiąc - liczba dni, warto wykorzystać tablicę
    przypominam liczbę dni w kolejnych miesiącach (można przekopiować): 
    [31,28,31,30,31,30,31,31,30,31,30ctrlNumber,31];
  * Funkcja do sprawdzenia roku przestępnego (luty 29 dni):
      bool leapYear(int year) {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
      }
  * K-cyfra kontrolna wyliczana jest z poprzedzających ją 10 cyfr w następującu sposób:
     Każdą pozycję numeru ewidencyjnego mnoży się przez odpowiednią wagę, 
     są to kolejno: 1 3 7 9 1 3 7 9 1 3. 
     Następnie utworzone iloczyny dodaje się i wynik dzieli się modulo 10.
     Wynik ten należy odjąć od 10 i znów podzielić przez modulo 10 
     (to zabezpieczenie gdybyśmy w poprzednim kroku otrzymali 10).
     Np. dla 0 2 0 7 0 8 0 3 6 2 
       i wag 1 3 7 9 1 3 7 9 1 3
     Suma=0*1+2*3+0*7+7*9+0*1+8*3+0*7+3*9+6*1+2*3 = 132
     132 mod 10 = 2
     10 - 2 = 8
     8 mod 10 = 8
     K=8 Prawidłowy PESEL: 02070803628

  * Wskazówki do konwersji napisu na tablicę:
    * cyfra 0 to kod ASCII 48
    * Konwertujemy tylko wtedy, gdy długości argumentów są odpowiednio 8 i 4
    * Można skorzystać z strlen() z biblioteki cstring

   * NIE WOLNO modyfikować main.cpp!
   * W miarę czasu i możliwości spróbuj wykorzystać cmake 
     zamiast dołączony Makefile i wykonać podział na include, src, build
   * Po wykonaniu zadania przeslij na UPEL spakowane archiwum grupa_nazwisko.tar.gz albo zip. 
     W archiwum mają znajdować się TYLKO niezbędne pliki i katalogi wraz z tymi dołączonymi do zadania.
     Nie wysyłaj plików w dodatkowym katalogu np Lab3
*/

#include <iostream>
#include "pesel.h"

int main() {

//Tpesel indeksy parzyste data DDMMYYYY, indeksy nieparzyste XXXP
const char* Tpesel[] = {"29021980","0123", 
                 "29021981", "0123", 
                 "13052001","1336", 
                 "31122012", "1333",
                 "29022104","5639",
                 "19022104","562",
                 "13132000", "1212"
                 };

// tablica, w której będziemy trzymać wygenerowany PESEL, by nie alokowac pamięci
int PESEL[11]={0,0,0,0,0,0,0,0,0,0,0}; 

// tablica do konwersji liczby miesiąca na nazwę
const char *monthName[] = {0," stycznia "," lutego ", " marca "," kwietnia "," maja "," czerwca ",
    " lipca "," sierpnia "," wrzesnia ",
    " pazdziernika "," listopada "," grudnia "};

bool valid;


for (int i=0; i < 14; i+=2) {
   valid = PeselGenerator(Tpesel[i], Tpesel[i+1], PESEL); //wykonuje konwersję i zwraca poprawność numeru true/false
  if (valid) {
    std::cout << "PESEL: ";
    printPesel(PESEL);
    std::cout << " Suma kontrolna: " << getControlNumber(PESEL) << std::endl;
    std::cout << "Plec: " << sex(Tpesel[i+1]) << std::endl;
    std::cout << "Data urodzenia: " << getDay(Tpesel[i]) 
                                    << monthName[getMonth(Tpesel[i])]
                                    << getYear(Tpesel[i]) << 
                                    std::endl;
  }
  else {
    std::cout << "Nie mozna wygenerowac numeru PESEL\n";
}
  std::cout << "-----------------------------------------\n";
}
  return 0;
}

/*  Oczekiwany wynik:
PESEL: 80022901235 Suma kontrolna: 5
Plec: Mezczyzna
Data urodzenia: 29 lutego 1980
-----------------------------------------
Nieprawidlowa data3
Nie mozna wygenerowac numeru PESEL
------------------------------02-----------
PESEL: 01251313363 Suma kontrolna: 3
Plec: Kobieta
Data urodzenia: 13 maja 2001
-----------------------------------------
PESEL: 12323113332 Suma kontrolna: 2
Plec: Mezczyzna
Data urodzenia: 31 grudnia 2012
-----------------------------------------
PESEL: 04422956394 Suma kontrolna: 4
Plec: Mezczyzna
Data urodzenia: 29 lutego 2104
-----------------------------------------
Nie mozna wygenerowac numeru PESEL
-----------------------------------------
Nieprawidlowa data
Nie mozna wygenerowac numeru PESEL
-----------------------------------------
*/