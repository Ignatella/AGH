/* Celem zadania jest napisanie standardowego konetnera, jakim jest tablica liczb całkowitych. Tablica ta musi mieć rozmiar określany dynamicznie podczas działania programu.
Rozwiązanie z tablicami statycznimi jest oceniane na 0 punktów!
Korzystanie z kontenrów biblioteki standardowej jest zabronione!

Do napisania są:
- konstruktor klasy MyArray, wypełniający tablice zerami
- konstruktor kopiujący
- konstruktor przenoszący
- destruktor
- operator przypisania =
- metoda size i operator dostępu do elementów tablicy []
- operator ++ inkrementujący wszystkie pola w tablicy
- metoda print i operator wypisania na ekran <<
Konstruktory i destruktory są 'głośne' - wypisują informacje na ekran.
Proszę zadbać o zarządzanie pamięcią. Powodzenia!
*/

#include "MyArray.h"
#include <iostream>

int main()
{
  std::cout << "Zadanie zaliczeniowe: Moja tablica liczb calkowitych!" << std::endl;

  //----------------------------------------------------
  std::cout << "Konstruktor obiektu i metoda print" << std::endl;
  MyArray arr(6);
  arr.print("arr");

  //----------------------------------------------------
  std::cout << "Operator dostępu i metoda size" << std::endl;
  for (int i = 0; i < arr.size(); ++i)
  {
    arr[i] = i;
  }
  arr.print("arr");

  //----------------------------------------------------
  std::cout << "Operator wypisywania na ekran" << std::endl;
  std::cout << "arr = " << arr;

  //----------------------------------------------------
  std::cout << "Inkrementacja" << std::endl;
  ++arr;
  arr.print("arr");

  //----------------------------------------------------
  std::cout << "Konstruktor kopiujący" << std::endl;
  const MyArray arrCopy = arr;
  arrCopy.print("copy");

  //----------------------------------------------------
  std::cout << "Sprawdzenie glebokiej kopii" << std::endl;
  arr[4] = 99;
  std::cout << "arr[5] = " << arr[4] << ", "
            << "copy[5] = " << arrCopy[4] << std::endl;

  //----------------------------------------------------
  std::cout << "Operator przypisania" << std::endl;
  MyArray arr2(4);
  arr2.print("arr2");
  arr2 = arr2 = arr;
  arr2.print("arr2");

  //----------------------------------------------------
  std::cout << "Konstruktor przenoszacy" << std::endl;
  arr.print("arr");
  MyArray marr = std::move(arr);
  arr.print("arr");
  marr.print("moved arr");

  //----------------------------------------------------
  std::cout << "Destruktory" << std::endl;
}

/* Oczekiwany wynik ./main
Zadanie zaliczeniowe: Moja tablica liczb calkowitych!
Konstruktor obiektu i metoda print
arr = [ 0, 0, 0, 0, 0, 0]
Operator dostępu i metoda size
arr = [ 0, 1, 2, 3, 4, 5]
Operator wypisywania na ekran
op<< [ 0, 1, 2, 3, 4, 5]
Inkrementacja
arr = [ 1, 2, 3, 4, 5, 6]
Konstruktor kopiujący
copy = [ 1, 2, 3, 4, 5, 6]
Sprawdzenie glebokiej kopii
arr[5] = 99, copy[5] = 5
Operator przypisania
arr2 = [ 0, 0, 0, 0]
arr2 = [ 1, 2, 3, 4, 99, 6]
Konstruktor przenoszacy
arr = [ 1, 2, 3, 4, 99, 6]
arr = []
moved arr = [ 1, 2, 3, 4, 99, 6]
Destruktory
Usuwam tablicę
Usuwam tablicę
Usuwam tablicę
Usuwam tablicę
*/