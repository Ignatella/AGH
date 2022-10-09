/*
Zadanie ma na celu przećwiczenie kontenerów oraz algorytmów STL.
Mamy następujące klasy:

* School - reprezentującą pojednynczą szkołę/klasę w szkole, zawierającą:
- nazwę,
- maksymalną liczbę miejsc rekrutacyjnych,
- listę wskaźników przyjętych uczniów,

* Student - reprezentującą pojedynczego ucznia, zawierającą pola:
- nazwę,
- liczbę punktów rekrutacyjnych,
- listę szkół, do których chce się dostać - kolejność jest istotna
- wskaźnik szkoły, do której został przyjęty.

* Table zawierająca dwa wektory - listę szkół i kandydatów.
Klasa ta ma za zadanie posortować wektor kandydatów wg punktów rekrutacyjnych w porządku malejącym (sortpoints) oraz rekrutować kandydatów do szkół (recruit). W tym celu funkcja recruit bierze studenta z góry posortowanej listy kandydatów oraz pierwszą szkołę z listy, po czym:
- jeśli szkoła ma miejsca (w tym celu trzeba napisać w klasie School odpowiednia metodę sprawdzającą), zapisuje studenta do szkoły (dopisuje go do listy przyjętych) oraz w klasie Student wpisuje wskaźnik szkoły, do której się dostał oraz zeruje kolejkę szkół
- jeśli nie ma miejsc, bierze kolejną szkołę z listy i powtarza czynności aż do opróżnienia listy albo przyjęcia do szkoły.

UWAGA:
* Niektóre wektory przechowują obiekty, a niektóre wskaźniki do obiektów.
* Operatory += dodają element do wektorów
* Nie wolno stosować tradycyjnych pętli z języka C, typu for (i=0;....)
* Chociaż raz powinno się pojawić foreach.
* Do sumowania w średniej wykorzystać algorytm accumulate albo foreach i lambda albo funktor.
*/

#include <iostream>
#include <vector>

#include "school.h"
#include "student.h"
#include "table.h"

int main()
{
    School l1("LO1", 2), l2("LO2", 3), l3("LO3", 3);
    std::vector<School> szk = {School("LO1", 2), School("LO2", 3), School("LO3", 2), School("LO4", 3)};
    std::vector<Student> kandydaci = {
        Student("Uczen__1", 151, {&l1, &l2, &l3}),
        Student("Uczen__2", 130, {&l2, &l3}),
        Student("Uczen__3", 120, {&l1, &l2, &l3}),
        Student("Uczen__4", 119, {&l1, &l2, &l3}),
        Student("Uczen__5", 118, {&l3, &l2}),
        Student("Uczen__6", 121, {&l2, &l3}),
        Student("Uczen__7", 110, {&l1, &l2}),
        Student("Uczen__8", 100, {&l3, &l2}),
        Student("Uczen_9", 90, {&l3})};
    std::cout << l1.getClass() << " - " << l1.getMax() << std::endl;
    kandydaci[3].print(); // przydział szkoły == nullptr -> wypisujemy "--> nieprzyjety"
    l1.print();           // lista przyjetych pusta - > wypisujemy "brak przyjetych"
    std::cout << std::endl;

    Table lista(kandydaci);
    lista += Student("Uczen_10", 149, {&l2, &l3});
    Table szkoly(&l1);
    szkoly += &l2;
    szkoly += &l3;

    lista.sortPoints();
    lista.printStud();
    lista += Student("Uczen_11", 99, {&l3, &l2});
    std::cout << "Srednia kandydatow: " << lista.getAverageStudScore() << std::endl;
    lista.recruit(); // funkcja rekrutująca
    lista.printStud();
    std::cout << "Przydzial dla LO 1:\n";
    l1.print();
    std::cout << "Przydzialy w szkolach:\n";
    szkoly.printRecruit();

    return 0;
}

/* Oczekiwany output:
LO1 - 2
Uczen__4: 119 [ LO1 LO2 LO3 ] --> nieprzyjety
LO1 - 2: brak przyjetych

Uczen__1: 151 [ LO1 LO2 LO3 ] --> nieprzyjety
Uczen_10: 149 [ LO2 LO3 ] --> nieprzyjety
Uczen__2: 130 [ LO2 LO3 ] --> nieprzyjety
Uczen__6: 121 [ LO2 LO3 ] --> nieprzyjety
Uczen__3: 120 [ LO1 LO2 LO3 ] --> nieprzyjety
Uczen__4: 119 [ LO1 LO2 LO3 ] --> nieprzyjety
Uczen__5: 118 [ LO3 LO2 ] --> nieprzyjety
Uczen__7: 110 [ LO1 LO2 ] --> nieprzyjety
Uczen__8: 100 [ LO3 LO2 ] --> nieprzyjety
Uczen_9: 90 [ LO3 ] --> nieprzyjety

Srednia kandydatow: 118.818
Uczen__1: 151 [ ] --> LO1
Uczen_10: 149 [ ] --> LO2
Uczen__2: 130 [ ] --> LO2
Uczen__6: 121 [ ] --> LO2
Uczen__3: 120 [ ] --> LO1
Uczen__4: 119 [ ] --> LO3
Uczen__5: 118 [ ] --> LO3
Uczen__7: 110 [ ] --> nieprzyjety
Uczen__8: 100 [ ] --> LO3
Uczen_11: 99 [ ] --> nieprzyjety
Uczen_9: 90 [ ] --> nieprzyjety

Przydzial dla LO 1:
LO1 - 2:
Uczen__1: 151 [ ] --> LO1
Uczen__3: 120 [ ] --> LO1

Przydzialy w szkolach:
LO1 - 2:
Uczen__1: 151 [ ] --> LO1
Uczen__3: 120 [ ] --> LO1

LO2 - 3:
Uczen_10: 149 [ ] --> LO2
Uczen__2: 130 [ ] --> LO2
Uczen__6: 121 [ ] --> LO2

LO3 - 3:
Uczen__4: 119 [ ] --> LO3
Uczen__5: 118 [ ] --> LO3
Uczen__8: 100 [ ] --> LO3

*/