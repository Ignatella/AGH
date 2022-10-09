#pragma once

#include "main.h"
#include "zelazko.h"

#include <iostream>
#include <string>

/**
 * @brief Klasa przedstawiajaca ubranie
 * 
 */
class Ubranie : public Produkt
{
protected:
    /**
     * @brief Czy ubranie jest wyprasowane
     * 
     */
    bool _isIroned;

    /**
     * @brief Maksymalna temperatura, przy ktorej ubranie mozna biezpiecznie prasowac
     * 
     */
    int _maxIronTemp;

protected:
    /**
     * @brief Tworzy Ubranie
     * 
     * @param name 
     * @param price 
     * @param maxIronTemp 
     * @param isIroned 
     */
    Ubranie(std::string name, int price, int maxIronTemp = 9, bool isIroned = false)
        : Produkt(name, price), _maxIronTemp(maxIronTemp), _isIroned(isIroned) {}

public:
    /**
     * @brief Nie pozwalamy na tworzenie ubrania, bo to jest abstrakcja
     * 
     */
    Ubranie() = delete;

    /**
     * @brief Prasuje ubranie
     * 
     * @param z 
     */
    void Prasuj(const Zelazko &z)
    {
        if (z.getTemp() > _maxIronTemp)
        {
            std::cout << "Zelazko za gorace." << std::endl;
            return;
        }

        if (_isIroned)
        {
            std ::cout << "---Ubranie nie wymaga prasowania." << std::endl;
            return;
        }

        std::cout << "---Prasuje " << _name << " zelazkiem o temp. " << z.getTemp() << "." << std::endl;
        _isIroned = true;
    };

    /**
     * @brief Gniecie ubranie
     * 
     */
    void Pogniec()
    {
        _isIroned = false;
    }

    /**
     * @brief Wypisuje ubranie na ekran
     * 
     */
    void Wypisz() const
    {
        Produkt::Wypisz();
        std::cout << (_isIroned ? "Wyprasowane" : "Pogniecione") << ". ";
    }
};

/**
 * @brief Klasa przedstawiajaca koszule
 * 
 */
class Koszula : public Ubranie
{
protected:
    /**
     * @brief Czy koszula ma dlugi rekaw
     * 
     */
    bool _hasLongSleeve;

    /**
     * @brief Tworyz nowa koszule
     * 
     * @param name 
     * @param price 
     * @param maxIronTemp 
     * @param isIroned 
     * @param hasLongSleeve 
     */
    Koszula(std::string name, int price, int maxIronTemp, bool isIroned, bool hasLongSleeve)
        : Ubranie(name, price, maxIronTemp, isIroned), _hasLongSleeve(hasLongSleeve){};

public:
    /**
     * @brief Nie pozwalamy na tworzenie koszuli, bo to jest abstrakcja
     * 
     */
    Koszula() = delete;

    /**
     * @brief Skraca rekawy koszuli
     * 
     */
    virtual void SkrocRekawy()
    {
        _hasLongSleeve = false;
    }

    /**
     * @brief Wypisuje koszule na ekran
     * 
     */
    void Wypisz() const
    {
        Ubranie::Wypisz();
        std::cout << (_hasLongSleeve ? "Dlugi" : "Krotki") << " rekaw. ";
    }
};

/**
 * @brief Klasa przedstawiajaca koszule bawelniana
 * 
 */
class KoszulaBawelniana final : public Koszula
{
public:
    /**
     * @brief Tworzy koszule bawelniana
     * 
     * @param price 
     * @param hasLongSleeve 
     */
    KoszulaBawelniana(int price, bool hasLongSleeve) : Koszula("Koszula bawelniana", price, 7, false, hasLongSleeve){};

    /**
     * @brief Wypisuje koszule bawelniana na ekran
     * 
     */
    void Wypisz() const
    {
        Koszula::Wypisz();
        std::cout << std::endl;
    }
};

/**
 * @brief Klasa przedstawiajaca koszule jedwabna
 * 
 */
class KoszulaJedwabna final : public Koszula
{
public:
    /**
     * @brief Tworzy nowa koszule jedwabna
     * 
     * @param price 
     * @param hasLongSleeve 
     */
    KoszulaJedwabna(int price, bool hasLongSleeve) : Koszula("Koszula jedwabna", price, 3, false, hasLongSleeve){};

    /**
     * @brief Wypisuje koszule jedwabna na ekran
     * 
     */
    void Wypisz() const
    {
        Koszula::Wypisz();
        std::cout << std::endl;
    }
};

/**
 * @brief Klasa przedstawiajaca Spodnie
 * 
 */
class Spodnie : public Ubranie
{
protected:
    /**
     * @brief Czy spodnie maja kanty
     * 
     */
    bool _hasEdges;

    /**
     * @brief Tworzy spodnie
     * 
     * @param name 
     * @param price 
     * @param maxIronTemp 
     * @param isIroned 
     * @param hasEdges 
     */
    Spodnie(std::string name, int price, int maxIronTemp, bool isIroned, bool hasEdges)
        : Ubranie(name, price, maxIronTemp, isIroned), _hasEdges(hasEdges){};

public:
    /**
     * @brief Nie pozwalamy na tworzenie spodni, bo to jest abstrakcja
     * 
     */
    Spodnie() = delete;

    /**
     * @brief Prasuje kanty
     * 
     * @param z 
     */
    void PrasujKanty(const Zelazko &z)
    {
        if (z.getTemp() > _maxIronTemp)
        {
            std::cout << "Zelazko za gorace." << std::endl;
            return;
        }

        if (_hasEdges)
        {
            std::cout << "Ubranie ma kanty." << std::endl;
            return;
        }

        std::cout << "---Prasuje nogawki " << _name << " zelazkiem o temp. " << z.getTemp() << "." << std::endl;

        _hasEdges = true;
    }

    /**
     * @brief Wypisuje spodnie na ekran
     * 
     */
    void Wypisz() const
    {
        Ubranie::Wypisz();
        std::cout << (_hasEdges ? "Kanty" : "Brak kantow") << ". ";
    }
};

/**
 * @brief Klasa przedstawiajaca spodnie bawelniane
 * 
 */
class SpodnieBawelniane final : public Spodnie
{
public:
    /**
     * @brief Tworzy spodnie bawelniane
     * 
     * @param price 
     * @param hasEdges 
     */
    SpodnieBawelniane(int price, bool hasEdges = false) : Spodnie("Spodnie bawelniane", price, 7, false, hasEdges){};

    /**
     * @brief Wypisuje bawelniane spodnie na ekran
     * 
     */
    void Wypisz() const
    {
        Spodnie::Wypisz();
        std::cout << std::endl;
    }
};

/**
 * @brief Klasa przedstawiajaca spodnie jedwabne
 * 
 */
class SpodnieJedwabne final : public Spodnie
{
public:
    /**
     * @brief Tworzy spodnie jedwabne
     * 
     * @param price 
     * @param hasEdges 
     */
    SpodnieJedwabne(int price, bool hasEdges = false) : Spodnie("Spodnie jedwabne", price, 7, false, hasEdges){};

    /**
     * @brief Wypisuje spodnie jedwabne na ekran
     * 
     */
    void Wypisz() const
    {
        Spodnie::Wypisz();
        std::cout << std::endl;
    }
};
