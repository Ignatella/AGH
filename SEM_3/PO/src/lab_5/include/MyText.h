#pragma once

#include <iostream>


// Struktura przedstawiajaca napis z jego nazwa
struct MyText  { 
    char *name;
    char *data;
};

// Oblicza dlugosc stringa
int strlen(const char *data);

// Kopiuje jeden string do drugiego
void copyStrTo(int count, const char *source, int from, char *target);

// Tworzy kopie stringa
char *copyStr(const char* source);

// Zamiania duze litery na male, a male na duze
int up2low_low2up(int src);

// Dokonuje wstepnej inicjalizacji struktury. Moze byc zainicilizowana z innej struktury
MyText *initMyText(const char *name, MyText *sourceTxt = NULL);

// Sprawdza, czy pole 'data' w strukturze ma dlugosc 0
bool empty(MyText *txt);

// Pobiera pole data ze struktury
char *getStr(MyText *txt);

// Dodaje napis do pola 'data' struktury
MyText *append(MyText *txt, const char *data);

// Wypisuje na ekran pole 'data' struktury
void print(MyText *txt);

// Oblicza rozmiar pola 'data' struktury
int size(MyText *txt);

// Ustawia 'value' na pozycji 'pos' w polu 'data' struktury
void setChar(MyText *txt, int pos, char value);

// Usuwa to - from symboli z pola 'data' struktury
void erase(MyText *txt, int from, int to);

// Wstawia na pozycji 'from' dane w polu 'data' struktury
void insert(MyText *txt, int from, const char *data);

// Wykonuje funkcje 'fun' na kazdym znaku stringa w polu 'data' struktury
void modify(MyText *txt, int fun(int source));

// Czysci pamiec zajmowana przez strukture
void clear(MyText *txt);