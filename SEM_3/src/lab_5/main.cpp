/* Zadanie służy przećwiczeniu zarządzaniu pamięcią oraz arytmetyki wskaźników. 
 * Do napisania jest prosta struktura będąca kontenerem na napis.
 * Kontener ten powinien pozwalać na rozszerzanie, usuwanie i podmienianie fragmentów.
 * Uwaga!  funkcje std::tolower(int)/std::toupper(int) nie działają na typie char!
 * W zadaniu są problematyczne miejsca:
 * funkcja erase  - usuwanie tekstu w środku - warto ustawić sobie odpowiednio wskaźniki.
 * funkcja insert - wstawianie tekstu pod zadany indeks, prosze spróbować to zrobić, ustawiając wskaźniki, nie iteracyjnie.
 * funkcja modify - modyfikuje cały napis używając przekazanego WSKAŹNIKA do funkcji 

 * UWAGA:
 * Zadanie należy wykonać za pomocą arytmetyki wskaźników - nie tablicowo.
 * Nie wolno używać gotowych rozwiązań. Nie korzystamy z funkcji z biblioteki cstring - sami piszemy potrzebne funkcje (strlen, strcpy, strcat).
 * Kontenery z biblioteki standardowej są zabronione. 
 */


#include <iostream>

#include "MyText.h"

void printStr(const char * text)
{
    std::cout << "Wypisujemy \"" << text << "\"" << std::endl;
}

int main()
{  
    std::cout << "Testujemy :" << std::endl;
    
    char a = 'a', b = 'B';
    std::cout << "a = " << a << ", b = " << b << std::endl;
    a = std::toupper(a);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    b = std::tolower(b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    a = up2low_low2up(a);
    b = up2low_low2up(b);
    std::cout << "a = " << a << ", b = " << b << std::endl;

    std::cout << "----------------------" << std::endl;

    MyText * text = initMyText("Tekst_1");
    if (empty(text))
    {
        std::cout << text ->name << " jest pusty." << std::endl;
        printStr(getStr(text));
    }
    
    std::cout << "----------------------" << std::endl;
    
    append(text, "Ala"); 
    printStr(getStr(text) );
    print(text);
    std::cout << "rozmiar(text) = " << size(text) << std::endl;
    
    append(append(text, " ma"), " kota");
    print(text);
    std::cout << "rozmiar(text) = " << size(text) << std::endl;
    
    setChar(text, 0, 'O');
    print(text);
    std::cout << "rozmiar(text) = " << size(text) << std::endl;
    
    erase(text, 4, 7);  // Usuwa trzy znaki: od 4 (włącznie) do 7 (bez 7)
    print(text);
    std::cout << "rozmiar(text) = " << size(text) << std::endl;
    insert(text, 4,"ma psa i ");
    print(text); 
    std::cout << "rozmiar(text) = " << size(text) << std::endl;
    std::cout << "----------------------" << std::endl;

#ifndef BASIC
    MyText * copy = initMyText("Tekst_2", text);
    print(copy);
    modify(copy, std::toupper);
    print(copy);
    modify(copy, std::tolower);
    print(copy);
    
    std::cout << "Zmieniamy  Tekst_1" << std::endl;
    print(text);
    modify(text, up2low_low2up);
    print(text);

    std::cout << "----------------------" << std::endl;
    clear(copy);
#endif

    clear(text);

#ifndef BASIC
    std::cout << "I jeszcze raz... Dla pewnosci." << std::endl;
    clear(copy);
    delete copy;
#endif

  delete text;
}


/* OUTPUT

Testujemy :
a = a, b = B
a = A, b = B
a = A, b = b
a = a, b = B
----------------------
Tekst_1 jest pusty.
Wypisujemy ""
----------------------
Wypisujemy "Ala"
Tekst_1 = "Ala"
rozmiar(text) = 3
Tekst_1 = "Ala ma kota"
rozmiar(text) = 11
Tekst_1 = "Ola ma kota"
rozmiar(text) = 11
Tekst_1 = "Ola kota"
rozmiar(text) = 8
Tekst_1 = "Ola ma psa i kota"
rozmiar(text) = 17
----------------------
Tekst_2 = "Ola ma psa i kota"
Tekst_2 = "OLA MA PSA I KOTA"
Tekst_2 = "ola ma psa i kota"
Zmieniamy  Tekst_1
Tekst_1 = "Ola ma psa i kota"
Tekst_1 = "OLA MA PSA I KOTA"
----------------------
Usuwamy Tekst_2
Usuwamy Tekst_1
I jeszcze raz... Dla pewnosci.*/