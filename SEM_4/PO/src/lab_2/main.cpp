/*
Celem zadania jest napisanie standardowego konetnera, jakim jest tablica liczb całkowitych. Tablica ta musi mieć rozmiar określany dynamicznie podczas działania programu.
Rozwiązanie z tablicami statycznimi jest oceniane na 0 punktów!
Korzystanie z kontenerów biblioteki standardowej jest zabronione!
 
Do napisania są:
- konstruktor klasy MyArray, wypełniający tablice zerami
- konstruktor kopiujący
- konstruktor przenoszący
- destruktor
- operator przypisania =
- metoda size i operator dostępu do elementów tablicy []
- operator ++ inkrementujący wszystkie pola w tablicy
- metoda print i operator wypisania na ekran <<
- operatory * i *=

Proszę zadbać o zarządzanie pamięcią. Powodzenia!
*/


#include "MyArray.h"
#include <iostream>


int main() 
{
    std::cout << "Moja tablica liczb calkowitych!" << std::endl;
    
    //----------------------------------------------------
  	std::cout << "\nKonstruktor obiektu i metoda print" << std::endl;
    MyArray arr(6);
    arr.print("arr");
    
    //----------------------------------------------------
    std::cout << "\nOperator dostępu i metoda size" << std::endl;
    for(int i = 0; i<arr.size(); ++i)
    {
        arr[i] = i;
    }
    arr.print("arr");
    
    //----------------------------------------------------
    std::cout << "\nOperator wypisywania na ekran" << std::endl;
	  std::cout << "arr = " << arr << std::endl;
    
    //----------------------------------------------------
    std::cout << "\nInkrementacja" << std::endl;
    std::cout << arr++ << std::endl;
    arr.print("arr");
    
    //----------------------------------------------------
    std::cout << "\nKonstruktor kopiujący" << std::endl;
    const MyArray arrCopy = arr;
    arrCopy.print("copy");
        
    //----------------------------------------------------
    std::cout << "\nSprawdzenie glebokiej kopii" << std::endl;
    arr[4] = 99;
    std::cout <<  "arr[5] = " << arr[4] << ", " << 
                 "copy[5] = " << arrCopy[4] << std::endl;
        
    //----------------------------------------------------
    std::cout << "\nOperator przypisania" << std::endl;
    MyArray arr2(4);
    arr2.print("arr2");
    arr2 = arr2 = arr;
    arr2.print("arr2");

   //---------------------------------------------------- 
    std::cout << "\nOperator mnozenia" << std::endl;
    arr2 *= 2; 
    std::cout << "arr2 = " << arr2 << std::endl;
    const MyArray arr3 = arr2; 
    arr2 = arr3 * 3;
    arr2.print("arr3");
    std::cout << 10 * arr3 << std::endl;
  
    //----------------------------------------------------
    std::cout << "\nKonstruktor przenoszacy" << std::endl;
    arr.print("arr");
    MyArray marr = std::move(arr);
    arr.print("arr");
    marr.print("moved arr");
    
    //----------------------------------------------------
    std::cout << "\nDestruktory" << std::endl;
}

/* Oczekiwany wynik ./main
Moja tablica liczb calkowitych!

Konstruktor obiektu i metoda print
arr = [0, 0, 0, 0, 0, 0]

Operator dostępu i metoda size
arr = [0, 1, 2, 3, 4, 5]

Operator wypisywania na ekran
arr = [0, 1, 2, 3, 4, 5]

Inkrementacja
[0, 1, 2, 3, 4, 5]
Usuwam tablice
arr = [1, 2, 3, 4, 5, 6]

Konstruktor kopiujący
copy = [1, 2, 3, 4, 5, 6]

Sprawdzenie glebokiej kopii
arr[5] = 99, copy[5] = 5

Operator przypisania
arr2 = [0, 0, 0, 0]
arr2 = [1, 2, 3, 4, 99, 6]

Operator mnozenia
arr2 = [2, 4, 6, 8, 198, 12]
Usuwam tablice
arr3 = [6, 12, 18, 24, 594, 36]
[20, 40, 60, 80, 1980, 120]
Usuwam tablice

Konstruktor przenoszacy
arr = [1, 2, 3, 4, 99, 6]
arr = []
moved arr = [1, 2, 3, 4, 99, 6]

Destruktory
Usuwam tablice
Usuwam tablice
Usuwam tablice
Usuwam tablice
Usuwam tablice

*/