#pragma once

/**
 * @brief 'Jednostka' listy jednokierunkowej
 * 
 */
class Element
{
private:
    /**
     * @brief Nazwa elementu 
     * 
     */
    char *name;

    /**
     * @brief Wskaznik na nastepny element
     * 
     */
    Element *next;

public:
    /**
     * @brief Tworzy Element z nazwa
     * 
     * @param name Nazwa elementu
     */
    Element(const char *name);

    /**
     * @brief Wypisuje nazwe elementu do stdout (descryptor 1)
     * 
     */
    void printName() const;

    /**
     * @brief Zwraca nazwe elementu (getter)
     * 
     * @return Nazwa elementu
     */
    const char *getName() const;

    /**
     * @brief Zwraca nastepny element (getter)
     * 
     * @return Nastepny element
     */
    Element *getNext() const;

    /**
     * @brief Ustawia nastepny element (setter)
     * 
     * @param element Nastepny element
     */
    void setNext(Element *element);

    /**
     * @brief Zwalnia pamic, zajmowana przez Element
     * 
     */
    ~Element();
};
