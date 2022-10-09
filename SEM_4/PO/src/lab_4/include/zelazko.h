#pragma once

#include "main.h"

#include <iostream>

/**
 * @brief Klasa przedstawiaca zelazko
 * 
 */
class Zelazko: public Produkt
{
protected:
    /**
     * @brief Zakres zelazka
     * 
     */
    int _upperBound;

    /**
     * @brief Obecna temperatura zelazka
     * 
     */
    int _temp;

    /**
     * @brief Tworzy zelazke
     * 
     * @param name 
     * @param price 
     * @param upperBuond 
     * @param temp 
     */
    Zelazko(std::string name, int price, int upperBuond, int temp = 0)
        : Produkt(name, price), _upperBound(upperBuond), _temp(temp){};

public:
    /**
     * @brief Nie pozwalamy na tworzenie zelazka, bo to jest abstrakcja
     * 
     */
    Zelazko() = delete;

    /**
     * @brief Ustawia obecna temperature
     * 
     * @param temp 
     */
    void UstawTemperature(int temp)
    {

        if (temp > _upperBound)
        {
            std::cout << "Ten model nie obsluguje takiego zakresu temperatur." << std::endl;
            return;
        }

        _temp = temp;
    };

    /**
     * @brief Zwraca obecna temperature zelazka
     * 
     * @return int 
     */
    int getTemp() const { return _temp; };

    /**
     * @brief Wypisuje zelazko na ekran
     * 
     */
    void Wypisz() const
    {
        Produkt::Wypisz();
        std::cout << "Temperatura: " << _temp << ". "
                  << "Zakres: " << _upperBound << ". ";
    };
};

/**
 * @brief Klasa przedstawiajaca zelazko Philips
 * 
 */
class ZelazkoPhilips final: public Zelazko
{
public:
    /**
     * @brief Tworzy zelazko Philips
     * 
     * @param price 
     */
    ZelazkoPhilips(int price) : Zelazko("Philips", price, 5, 0){};

    /**
     * @brief Wypisuje zelazko philips na ekran
     * 
     */
    void Wypisz() const
    {
        Zelazko::Wypisz();
        std::cout << std::endl;
    };
};

/**
 * @brief Klasa przedstawiajaca zelazko Tefal
 * 
 */
class ZelazkoTefal final: public Zelazko
{
public:
    /**
     * @brief Tworzy zelazko Tefal
     * 
     * @param price 
     */
    ZelazkoTefal(int price) : Zelazko("Tefal", price, 7, 0){};

    /**
     * @brief Wypisuje zelazko tefal na ekran
     * 
     */
    void Wypisz() const
    {
        Zelazko::Wypisz();
        std::cout << std::endl;
    };
};
