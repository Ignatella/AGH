#pragma once

#include <iostream>

/**
 * @brief Liczba wymierna
 * 
 */
class Wymierne
{
private:
    /**
     * @brief licznik i mianownik liczby wymiernej
     * 
     */
    int licznik, mianownik;

public:
    /**
     * @brief Defoltowy konstruktor
     * 
     */
    Wymierne() : Wymierne(0, 1){};

    /**
     * @brief Tworzy liczbe wymierna z liczby calkowitej
     * 
     * @param licznik liczba calkowita
     */
    explicit Wymierne(int licznik) : Wymierne(licznik, 1){};

    /**
     * @brief Tworzy liczbe wymierna
     * 
     * @param licznik licznik
     * @param mianownik mianownik
     */
    Wymierne(int licznik, int mianownik) : licznik(licznik) { this->mianownik = mianownik == 0 ? 1 : mianownik; };

    /**
     * @brief Ustawia mianownik liczby zespolonej
     * 
     * @param mianownik nowy mianownik
     */
    void Mianownik(int mianownik) { this->mianownik = mianownik == 0 ? 1 : mianownik; };

    /**
     * @brief Ustawia licznik liczby zespolonej
     * 
     * @param licznik nowy licznik
     */
    void Licznik(int licznik) const { const_cast<Wymierne *>(this)->licznik = licznik; };

    /**
     * @brief Pobiera licznik liczby wymiernej (getter)
     * 
     * @return int licznik
     */
    int Licznik() const { return licznik; };

    /**
     * @brief Pobiera mianownik liczby wymiernej (getter)
     * 
     * @return int 
     */
    int Mianownik() const { return mianownik; };

    /**
     * @brief Ustawia licznik i mianownik liczby wymiernej
     * 
     * @param w 
     */
    void Set(const Wymierne &w)
    {
        licznik = w.licznik;
        mianownik = w.mianownik;
    };

    /**
     * @brief Ustawia licznik i mianownik liczby wymiernej
     * 
     * @param w 
     */
    void Set(const Wymierne &w) const
    {
        const_cast<Wymierne *>(this)->licznik = w.licznik;
        const_cast<Wymierne *>(this)->mianownik = w.mianownik;
    }

    /**
     * @brief Wypisuje na ekran liczbe wymierna poprzedzajac prefiksem
     * 
     * @param prefix poprzedzajacy prefiks
     */
    void Print(std::string prefix) const;

    /**
     * @brief Mnozy 2 liczby wymierna
     * 
     * @param w1 pierwsza liczba wymierna
     * @param w2 druga liczba wymierna
     * @return rezultat
     */
    friend Wymierne Pomnoz(const Wymierne &w1, const Wymierne &w2);

    /**
     * @brief Konwertuje liczbe wymirna na double
     * 
     * @return double z liczby wymiernej
     */
    operator double() const { return (double)licznik / mianownik; };
};

/**
 * @brief Mnozy 2 liczby wymierna
 * 
 * @param w1 pierwsza liczba wymierna
 * @param w2 druga liczba wymierna
 * @return rezultat
 */
Wymierne Pomnoz(const Wymierne &w1, const Wymierne &w2);