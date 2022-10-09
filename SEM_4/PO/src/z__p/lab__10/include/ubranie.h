#pragma once

#include "main.h"
#include "zelazko.h"

#include <iostream>
#include <string>

class Ubranie : public Produkt
{
};

class Koszula : public Ubranie
{
protected:
    int _maxIronTemp;

    bool _hasLongSleeve;
    bool _isIroned;

    Koszula(int price, bool hasLongSleeve, bool isIroned, int maxIronTemp)
        : Ubranie(price), _hasLongSleeve(hasLongSleeve), _isIroned(isIroned), _maxIronTemp(maxIronTemp){};

public:
    Koszula() = delete;

    virtual void Prasuj(const Zelazko z)
    {
        _isIroned = true;
    }

    virtual void SkrocRekawy()
    {
        _hasLongSleeve = false;
    }

    virtual void Wypisz() const = 0;
};

class KoszulaBawelniana : public Koszula
{

public:
    KoszulaBawelniana(int price, bool hasLongSleeve) : Koszula(hasLongSleeve, false, 7), _price(price){};

    virtual void Wypisz() const
    {
        std::string sleeveStatus = _hasLongSleeve ? "Dlugi" : "Krotki";
        std::string ironedStatus = _isIroned ? "Wyprasowane" : "Pogniecione";
        std::cout << "Koszula bawelniana cena: " << _price << ". " << ironedStatus << ". " << sleeveStatus << "rekaw.";
    }
};

class KoszulaJedwabna : public Koszula
{
private:
    int _price;

public:
    KoszulaJedwabna(int price, bool hasLongSleeve) : Koszula(hasLongSleeve, false, 3), _price(price){};

    virtual void Wypisz() const
    {
        std::string sleeveStatus = _hasLongSleeve ? "Dlugi" : "Krotki";
        std::string ironedStatus = _isIroned ? "Wyprasowane" : "Pogniecione";
        std::cout << "Koszula bawelniana cena: " << _price << ". " << ironedStatus << ". " << sleeveStatus << "rekaw.";
    }
};
