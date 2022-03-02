#pragma once
#include "Fraction.h"
#include <vector>
#include <iostream>
#include <algorithm>

/**
 * @brief Porownuje ulamki
 *
 * @param i1
 * @param i2
 * @return true
 * @return false
 */
inline bool compareInterval(Fraction i1, Fraction i2)
{
    return (double)(i1 - i2) < 0;
}

/**
 * @brief Kolekcja ulamkow
 *
 */
class FVector
{
private:
    /**
     * @brief Wewnetrzna struktura danych
     *
     */
    std::vector<Fraction> v;

public:
    /**
     * @brief Tworzy Kolekcje inicjalizujac ulamkiem
     * @param f
     */
    FVector(const Fraction &f) { v.push_back(f); };

    /**
     * @brief Dodaje ulamek do kolekcji
     *
     * @param f
     */
    void operator+=(const Fraction &f) { v.push_back(f); };

    /**
     * @brief Sortuje kolekcje ulamkow
     *
     */
    void sort() { std::sort(v.begin(), v.end(), compareInterval); };

    /**
     * @brief Wypisuje kolekcje ulamkow na ekran
     *
     * @param os
     * @param f
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &os, const FVector &f);
};

/**
 * @brief Wypisuje kolekcje ulamkow na ekran
 *
 * @param os
 * @param f
 * @return std::ostream&
 */
inline std::ostream &operator<<(std::ostream &os, const FVector &f)
{
    os << "[ ";

    for (int i = 0; i < f.v.size(); i++)
        os << f.v[i] << ", ";

    os << "\b\b]" << std::endl;
    return os;
}
