/*
  Aby kod dał się skompilować, zdefiniuj na początku wszystkie używane funkcje
  z prawidłowymi arumentami i pustą zawartością, a potem sukcesywnie uzupełniaj.
  Nie zapomnij o dokumentacji.

  Opis zadania:
    Należy zaimlementować funkcje pozwalające sprawdzić poprawność numeru PESEL
    Numer PESEL:  RRMMDDXXXPK (11 cyfr)
    
    RR-ostatnie dwie cyfry roku w przedziale od 00 do 99
      dla 2010 i 1910 roku będzie to wspólna liczba 10, zmienia się tylko miesiąc
    
    MM-cyfry miesiąca
      dla 1900-1999 są to 1-12
      dla 2000-2099 są to 21-32 (+20)
      dla 2100-2199 są to 41-52 (+40)
      ----- nie ma potrzeby implementować poniższych------
      powyżej 2200 są to 61-72 (+40)
      dla 1800-1899 są to 81-92, (+80)
    
    DD-cyfry dnia (w zależności od miesiąca)
      można to zrobić na piechotę ale szybciej będzie wykorzystać tablicę
      przypominam liczbę dni w kolejnych miesiącach (można przekopiować): 
      [31,28,31,30,31,30,31,31,30,31,30,31];
      Funkcja do sprawdzenia roku przestępnego (luty 29 dni):
      bool leapYear(int year) {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
      }

    XXX-liczba ewidencyjna związana z kolejnością urodzeń, nie trzeba sprawdzać.
    
    P-cyfra płci: podzielna przez 2 - kobieta, niepodzielna - mężczyzna
    
    K-cyfra kontrolna wyliczana z poprzedzających ją 10 cyfr w następującu sposób:
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

    Wskazówki do konwersji napisu na tablicę:
    * cyfra 0 to kod ASCII 48
    * Konwertujemy tylko wtedy, gdy długość napisu jest równa 11
    * Można skorzystać z strlen() z biblioteki cstring

   * NIE WOLNO modyfikować main.cpp!
   * W miarę czasu i możliwości spróbuj wykorzystać cmake zamiast dołączony Makefile i wykonać podział na include, src, build
   * Po wykonaniu zadania przeslij na UPEL spakowane archiwum grupa_nazwisko.tar.gz albo zip. 
     W archiwum mają znajdować się tylko niezbędne pliki i katalogi wraz z tymi dołączonymi do zadania.
     Nie wysyłaj plików w dodatkowym katalogu np Lab3
*/

#include <iostream>
#include <string>
#include "pesel.h"

int main()
{
    const char *Tpesel[] = {
        "80022901235",
        "81022901232",
        "01251213366",
        "11323113335",
        "04422956295",
        "044229562",
    };

    int PESEL[11]; // tablica, w której będziemy trzymać skonwertowany PESEL
    bool valid;
    // tablica do konwersji liczby miesiąca na nazwę
    const char *monthName[] = {0, " stycznia ", " lutego ", " marca ", " kwietnia ", " maja ", " czerwca ",
                               " lipca ", " sierpnia ", " wrzesnia ",
                               " pazdziernika ", " listopada ", " grudnia "};
    for (int i = 0; i < 6; ++i)
    {
        valid = PeselValidator(Tpesel[i], PESEL); //wykonuje konwersję i zwraca poprawność numeru
        if (valid)
        {
            std::cout << "PESEL: ";
            printPesel(PESEL);
            std::cout << " Suma kontrolna: " << getCtrlNumber(PESEL) << std::endl;
            std::cout << "Numer PESEL jest prawidlowy" << std::endl;
            std::cout << "Data urodzenia: " << getDay(PESEL)
                      << monthName[getMonth(PESEL)]
                      << getYear(PESEL) << std::endl;
        }
        else
        {
            std::cout << "PESEL: " << Tpesel[i];
            std::cout << " jest nieprawidlowy\n";
        }
        std::cout << "-----------------------------------------" << std::endl;
    }
    return 0;
}


/*  Oczekiwany wynik:
PESEL: 80022901235 Suma kontrolna: 5
Numer PESEL jest prawidlowy
Data urodzenia: 29 lutego 1980
-----------------------------------------
PESEL: 81022901232 jest nieprawidlowy
-----------------------------------------
PESEL: 01251213366 Suma kontrolna: 6
Numer PESEL jest prawidlowy
Data urodzenia: 12 maja 2001
-----------------------------------------
PESEL: 11323113335 Suma kontrolna: 5
Numer PESEL jest prawidlowy
Data urodzenia: 31 grudnia 2011
-----------------------------------------
PESEL: 04422956295 Suma kontrolna: 5
Numer PESEL jest prawidlowy
Data urodzenia: 29 lutego 2104
-----------------------------------------
PESEL: 044229562 jest nieprawidlowy
-----------------------------------------
*/