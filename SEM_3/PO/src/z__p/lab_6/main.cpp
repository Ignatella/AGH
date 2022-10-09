/* 
Zadanie do realizacji w parach na repl.it
Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał, a wynik jego działania był taki sam, jak podany na końcu tego pliku.

Funkcja strtok, dzieląca napis wg podanego separatora działa w oparciu o wewnętrzny statyczny wskaźnik. Każde kolejne wywołanie strtok zastępuje pierwsze wystąpienie separatorów znakami końca stringu '\0' i ustawia wewnętrzny wskaźnik za tym znakiem.
Celem zadania jest zdefiniowanie struktury, która będzie przechowywać taki "poszatkowany" napis i udostępni operacje na nim dzięki temu, że ma ustawione wskaźniki na początek i koniec napisu (begin i end) oraz wskaźnik next, zastępujący działanie wewnętrznego wskaźnika, ustawiany po każdym wywołaniu mystrtok. Next wskazuje zawsze na jeszcze nie podzielony fragment napisu.
Dodatkowo mamy funkcję split2list, która w pętli wywołuje mystrtok i dodaje każdy z elementów do listy z poprzednich zajęć - można skorzystać z kodu, ale prosze usunąc zbędne funkcje i lekko zmodyfikować print oraz dodać removeFirst. 
Pozostałe funkcje i modyfikacje są związane z inicjacją struktury oraz wynikają z tego że  NIE KORZYSTAMY z cstring ani std::string.
Niektóre funkcje mają paramety domyślne, proszę nie powielać niepotrzebnie kodu funkcji.
Podczas oceny będę zwracać uwagę na odpowiednie posługiwanie się wskaźnikami.

Należy zadbać o odpowiednie gospodarowanie pamięcią. Valgrind (make check) nie powinien wykazywać żadnych wycieków pamięci (leap) ani błędów (errors).
*/

#include "MyList.h"
#include "MyStr.h"
#include <iostream>

int main() {
    MyList list1, list2;
    init(&list1);
    init(&list2);
    MyList *ptr1 = &list1;

    std::cout << "*** Napis 1 ***" << std::endl; 
    char *text1 = mycopy("Agnieszka,Monika Maria;;;Gosia");//działa jak strcpy, ale alokuje pamięć wewnątrz funkcji
    std::cout << "Napis \"" << "text1" << "\" ma dlugosc " << mystrlen(text1) << std::endl;
    char znak=',';
    std::cout << "Znak '" << znak << "' " << (findSep(znak,text1)?"znaleziony" :"nie znaleziony") << std::endl;

    MyString tosplit1;
    initMyString(&tosplit1, text1, ",;."); 
    for (int i=1; i<4; ++i){
      std::cout <<"Do podzielenia: "<< tosplit1.next << std::endl;
      std::cout << "Pobrano: " << mystrtok(&tosplit1)<< std::endl; //dzieli napis, wstawiając w miejscu separatora znak końca stringu
    }

    std::cout << "\n*** Napis 2 ***" << std::endl;
    char *ola = mycopy("Ola");
    char* dwa = mystrcat (ola, " Piotr  Janusz");
    std::cout << dwa << std::endl;
    char *text2 = mystrcat (dwa, "Basia,Anna-Maria",';'); //ta sama funkcja co wyżej, trzeci argument mystrcat domyślnie ustawiony na '\0'
    std::cout << "Napis \"" << text2 << "\" ma dlugosc " << mystrlen(text2) << std::endl;

    MyString tosplit2;
    initMyString(&tosplit2,text2); // ta sama funkcja, trzeci argument sep domyślnie ustawiony na NULL
    addSep(&tosplit2, " ,;\t");  // dodanie separatorów
    std::cout <<"Do podzielenia: "<< tosplit2.begin << std::endl;
    split2list(ptr1, &tosplit2);
    print(ptr1);
        
    std::cout << "\n*** Napis 3 ***" << std::endl;  
    MyString tosplit3;
    initMyString(&tosplit3,"...A,B;-C--D E-F .G\tH,"," ,;.-\t");
    split2list(&list2, &tosplit3);
    print(&list2);
    
    std::cout << "Drugi w napis1: "<< gettok(&tosplit1,2) << std::endl;  
    std::cout << "Trzeci w napis2: "<< gettok(&tosplit2,3) << std::endl;
    std::cout << "Pierwszy w napis3: "<< gettok(&tosplit3,1) << std::endl;
    std::cout << "Czwarty w napis1: "<< gettok(&tosplit1,4) << std::endl;
    removeFirst(&list2);
    print(&list2);

    std::cout << "\n*** Czyszczenie ***" << std::endl;
    clear(ptr1);
    clear(&list1);
    clear(&list2);
    removeMyString(&tosplit1);
    removeMyString(&tosplit2);
    removeMyString(&tosplit3);
    delete[] text1;
    delete[] ola;
    delete[] dwa;
    delete[] text2;
}

/* Oczekiwany wynik
./main
*** Napis 1 ***
Napis "Agnieszka,Monika Maria;;;Gosia" ma dlugosc 30
Znak ',' znaleziony
Do podzielenia: Agnieszka,Monika Maria;;;Gosia
Pobrano: Agnieszka
Do podzielenia: Monika Maria;;;Gosia
Pobrano: Monika Maria
Do podzielenia: Gosia
Pobrano: Gosia

*** Napis 2 ***
Ola Piotr  Janusz
Napis "Ola Piotr  Janusz;Basia,Anna-Maria" ma dlugosc 34
Do podzielenia: Ola Piotr  Janusz;Basia,Anna-Maria
<Ola> <Piotr> <Janusz> <Basia> <Anna-Maria>

*** Napis 3 ***
<A> <B> <C> <D> <E> <F> <G> <H>
Drugi w napis1: Monika Maria
Trzeci w napis2: Janusz
Pierwszy w napis3: A
Czwarty w napis1: 
<B> <C> <D> <E> <F> <G> <H>

*** Czyszczenie ***
*/