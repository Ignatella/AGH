#pragma once

#include "Element.h"

/**
 * @brief Lista jednokierunkowa
 * 
 */
class MyList
{
private:
    /**
     * @brief Nazwa listy jednokierunkowej
     * 
     */
    char *name;

    /**
     * @brief Pierwszy element listy jednokierunkowej
     * 
     */
    Element *head;

    /**
     * @brief Ostatni element listy jednokierunkowej
     * 
     */
    Element *tail;

public:
    /**
     * @brief Tworzy liste jednokierunkowa z nazwa
     * 
     * @param name Nazwa listy jednokierunkowej
     */
    MyList(const char *name);

    /**
     * @brief Pobiera pierwszy element listy jednokierunkowej (getter)
     * 
     * @return Pierwszy element
     */
    Element *getHead() const;

    /**
     * @brief Pobiera ostatni element listy jednokierunkowej (getter)
     * 
     * @return Ostatni element
     */
    Element *getLast() const;

    /**
     * @brief Pobiera nazwe listy jednokierunkowej (getter)
     * 
     * @return Nazwa listy jednokierunkowej
     */
    const char *getName() const;

    /**
     * @brief Sprawdza czy lista jest pusta
     * 
     * @return true w przypadku, jezeli jest pusta
     * @return false w przeciwnym przypadku
     */
    bool isEmpty() const;

    /**
     * @brief Usuwa pierwszy element listy
     * 
     */
    void removeFirst();

    /**
     * @brief Dodaje element na poczatek listy
     * 
     * @param data element, ktory zostanie dodany na poczatek listy
     */
    void prepend(Element *data);

    /**
     * @brief Dodaje element na koniec listy
     * 
     * @param data nazwa dla elementu, ktory zostanie dodany na koniec listy
     */
    void append(const char *data);

    /**
     * @brief Dodaje element na koniec listy
     * 
     * @param element ktory zostanie dodany na koniec listy
     */
    void append(Element *element);

    /**
     * @brief Usuwa wszystkie elementy z listy, ale nie sama liste
     * 
     */
    void clearList();

    /**
    * @brief Usuwa z pamieci wszystkie elementy liste oraz sama liste
    * 
    */
    ~MyList();
};

/**
 * @brief Wypisuje liste na ekran
 * 
 * @param list lista ktora zostanie wypisana na ekran
 */
void print(const MyList *list);