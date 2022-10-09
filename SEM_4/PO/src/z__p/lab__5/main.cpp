/*
Celem zadania jest przetestowanie konstruktorów kopiujacych, przenoszacych i przeładowania
operatorów. Należy zdefiniować klasę standardowego kontenera, jakim jest tablica liczb całkowitych,
będącego jednocześnie elementem listy jednokierunkowej. Tablica ta musi mieć rozmiar określany
dynamicznie podczas działania programu i jest wypełniana zerami.
Rozwiązanie z tablicami statycznymi jest oceniane na 0 punktów!
Korzystanie z kontenerów biblioteki standardowej jest zabronione!
Dzięki temu, że klasa tablicy posiada wskaźnik na następny element, można łączyć ze sobą
tablice poprzez wskaźniki z zachowaniem ich podziału.
Jednak w przypadku zastosowania std::move tablica doklejana jest na koniec przypisanej
(zwiększamy rozmiar tablicy i alokujemy większą pamięć, a jej powiązania wskaźnikowe pozostają bez zmian).
Proszę zadbać o zarządzanie pamięcią. Destruktor usuwa tylko pamięć zarezerwowaną dla pojedynczego
elementu.
*/

#include "my_array.h"
#include <iostream>

int main()
{
    std::cout << "Lista tablic liczb calkowitych!" << std::endl;

    MyArray tab1(5), tab2(3);
    std::cout << "tab1 = " << tab1 << std::endl;

    std::cout << "\nWypelniamy tablice i zmieniamy" << std::endl;
    for (int i = 0; i < tab1.size(); ++i)
    {
        tab1[i] = i * 2;
    }
    std::cout << "tab1 = " << tab1 << std::endl;
    std::cout << "tab1++ = " << tab1++ << std::endl;
    std::cout << "--tab2 = " << --tab2 << std::endl;

    const MyArray tab1Copy = tab1;
    std::cout << "tab1Copy = " << tab1 << std::endl;

    std::cout << "\nOperator indeksowania i przypisania" << std::endl;
    tab1[4] = 19;
    std::cout << "tab1[4] = " << tab1[4] << ", "
              << "tab1Copy[4] = " << tab1Copy[4] << std::endl;

    MyArray tab3(4);
    std::cout << "tab3 = " << tab3 << std::endl;
    tab3 = tab3 = tab1;
    std::cout << "tab3 = " << tab3 << std::endl;

    std::cout << "\nKonstruktor przenoszacy" << std::endl;
    std::cout << "tab1 = " << tab1 << std::endl;
    MyArray mtab1 = std::move(tab1);
    std::cout << "tab1 = " << tab1 << std::endl;
    std::cout << "moved tab1 = " << mtab1 << std::endl;

    std::cout << "\nDolaczanie listowe" << std::endl;
    mtab1 += tab2;
    std::cout << "next = " << mtab1.getNext() << std::endl;
    mtab1.getNext()[1] = 100;
    mtab1 += tab3;
    std::cout << "next = " << tab2.getNext() << std::endl;
    mtab1.print("Mtab1: ");
    MyArray mtab1Copy = mtab1;
    std::cout << "\ntab[6]= " << mtab1[6] << std::endl;
    mtab1Copy.print("Kopia mtab1: ");

    std::cout << "\n\nDolaczanie zwykle\n";
    MyArray newtab(3);
    newtab += std::move(tab3);
    newtab.print("Newtab: ");
    mtab1 += std::move(MyArray(3));
    mtab1.print("\nMtab1: ");
    std::cout << "\nnext = " << mtab1.getNext() << std::endl;
    std::cout << "tab[9]= " << mtab1[9] << std::endl;
}

/* Oczekiwany wynik
./main
Lista tablic liczb calkowitych!
tab1 = [0, 0, 0, 0, 0]
Wypelniamy tablice i zmieniamy
tab1 = [0, 2, 4, 6, 8]
tab1++ = [1, 3, 5, 7, 9]
--tab2 = [-1, -1, -1]
tab1Copy = [1, 3, 5, 7, 9]
Operator indeksowania i przypisania
tab1[4] = 19, tab1Copy[4] = 9
tab3 = [0, 0, 0, 0]
tab3 = [1, 3, 5, 7, 19]
Konstruktor przenoszacy
tab1 = [1, 3, 5, 7, 19]
tab1 = []
moved tab1 = [1, 3, 5, 7, 19]
Dolaczanie listowe
next = [-1, -1, -1]
next = [1, 3, 5, 7, 19]
Mtab1: [1, 3, 5, 7, 19] [-1, 100, -1] [1, 3, 5, 7, 19]
tab[6]= 100
Kopia mtab1: [1, 3, 5, 7, 19] [-1, 100, -1] [1, 3, 5, 7, 19]
Dolaczanie zwykle
Newtab: [0, 0, 0, 1, 3, 5, 7, 19]
Mtab1: [1, 3, 5, 7, 19, 0, 0, 0] [-1, 100, -1] [1, 3, 5, 7, 19]
next = [-1, 100, -1]
tab[9]= 100
*/