#pragma once

#include <string>
#include <iostream>

/**
 * @brief Klasa przedstawiajaca produkt
 * 
 */
class Produkt
{
protected:
    /**
     * @brief 
     * 
     */
    int _price;

    /**
     * @brief Nazwa produktu
     * 
     */
    std::string _name;

protected:
    /**
     * @brief Tworzy produkt o zadanej nazwie i cenie
     * 
     * @param name 
     * @param price 
     */
    Produkt(std::string name, int price) : _name(name), _price(price){};

public:
    /**
     * @brief Nie pozwalamy na tworzenie produktu, bo to jest abstrakcja
     * 
     */
    Produkt() = delete;

    /**
     * @brief Wypisuje produkt na ekran
     * 
     */
    void Wypisz() const
    {
        std::cout << _name << " cena: " << _price << ". ";
    }
};
