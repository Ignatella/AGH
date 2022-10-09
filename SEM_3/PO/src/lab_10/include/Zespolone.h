#pragma once

#include "Wymierne.h"
#include <iostream>
#include <utility>

/**
 * @brief Liczba zespolona
 * 
 */
class Zespolone
{
private:
    /**
     * @brief re - czesc rzeczywista, im - czesc urojona
     * 
     */
    double re, im;

public:
    /**
     * @brief Tworzy liczbe zespolona
     * 
     * @param re czesc rzeczywista
     * @param im czesc urojona
     */
    Zespolone(double re, double im) : re(re), im(im){};

    /**
     * @brief Tworzy liczbe zespolona z liczby wymiernej
     * 
     * @param w liczba wymierna
     */
    Zespolone(const Wymierne &w) : Zespolone((double)w.Licznik() / w.Mianownik()){};

    /**
     * @brief Tworzy liczbe zespolona z double
     * 
     * @param re 
     */
    Zespolone(double re) : Zespolone(re, 0){};

    /**
     * @brief Konstruktor przenoszacy
     * 
     * @param z 
     */
    Zespolone(Zespolone &&z) : re(std::exchange(z.re, 0)), im(std::exchange(z.im, 0)){};

    /**
     * @brief Wypisuje liczbe zespolona na ekran poprzedzajac prefiksem
     * 
     * @param prefix prefiks 
     */
    void Print(std::string prefix) const;

    /**
     * @brief Pobiera czesc urojona liczby zespolonej
     * 
     * @return double czesc urojona
     */
    double Im() const { return im; };

    /**
     * @brief Dodaje 2 liczby zespolona
     * 
     * @param z1 pierwsza liczba zespolona
     * @param z2 druga liczba zespolona
     * @return rezultat
     */
    friend Zespolone Dodaj(const Zespolone &z1, const Zespolone &z2);
};

/**
 * @brief Dodaje 2 liczby zespolona
 * 
 * @param z1 pierwsza liczba zespolona
 * @param z2 druga liczba zespolona
 * @return rezultat
 */
Zespolone Dodaj(const Zespolone &z1, const Zespolone &z2);
