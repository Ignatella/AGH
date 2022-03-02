#pragma once
#include <iostream>

/**
 * @brief Najwiekszy wspolny dzielnik
 *
 * @param m
 * @param n
 * @return int
 */
int nwd(int m, int n);

/**
 * @brief Ulamek
 *
 */
class Fraction
{
private:
    /**
     * @brief Licznik i mianownik ulamka
     *
     */
    int l, m;

private:
    /**
     * @brief Skraca ulamek
     *
     */
    void simplify();

public:
    /**
     * @brief Tworzy ulamek
     *
     * @param l licznik
     */
    Fraction(int l) : Fraction(l, 1){};

    /**
     * @brief Tworzy ulamek
     *
     * @param l licznik
     * @param m mianownik
     */
    Fraction(int l, int m) : l(l), m(m)
    {
        this->m = m == 0 ? 1 : m;
        this->l = m < 0 ? -l : l;
        this->m = m < 0 ? abs(m) : m;
        simplify();
    };

    /**
     * @brief Konwertuje ulamek na double
     *
     * @return double
     */
    explicit operator double() const { return (double)l / m; };

    /**
     * @brief Porownuje 2 ulamki
     *
     * @param f
     * @return true
     * @return false
     */
    bool operator==(const Fraction &f) const { return l == f.l && m == f.m; };

    /**
     * @brief Oblicza ulamek * -1
     *
     * @return Fraction
     */
    Fraction operator-() const { return Fraction(-this->l, this->m); };

    /**
     * @brief Mnozy 2 ulamki
     *
     * @param f
     * @return Fraction
     */
    Fraction operator*(const Fraction &f) const { return Fraction(f.l * this->l, f.m * this->m); };

    /**
     * @brief Dodaje 2 ulamki
     *
     * @param f
     * @return Fraction
     */
    Fraction operator+(const Fraction &f) const { return Fraction(f.l * m + f.m * l, f.m * m); };

    /**
     * @brief Odejmuje od tego ulamka ulamek
     *
     * @param f
     * @return Fraction
     */
    Fraction operator-(const Fraction &f) const { return Fraction(f.m * l - f.l * m, f.m * m); };

    /**
     * @brief Domnaza ten ulamek przez ulamek
     *
     * @param f
     * @return Fraction&
     */
    Fraction &operator*=(const Fraction &f);

    /**
     * @brief Odejmuje od tego ulamka ulamek
     *
     * @param f
     * @return Fraction&
     */
    Fraction &operator-=(const Fraction &f);

    /**
     * @brief Przypisuje ulamku ulamek
     *
     * @param f
     * @return Fraction&
     */
    Fraction &operator=(const Fraction &f) &
    {
        this->l = f.l;
        this->m = f.m;
        return *this;
    };

    /**
     * @brief Mnozy ulamek przez liczbe
     *
     * @param l
     * @param f
     * @return Fraction
     */
    friend Fraction operator*(int l, const Fraction &f);

    /**
     * @brief Dodaje liczbe do ulamka
     *
     * @param l
     * @param f
     * @return Fraction
     */
    friend Fraction operator+(int l, const Fraction &f);

    /**
     * @brief Wypisuje ulamek
     *
     * @param os
     * @param f
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &os, const Fraction &f);
};

/**
 * @brief Mnozy ulamek przez liczbe
 *
 * @param l
 * @param f
 * @return Fraction
 */
inline Fraction operator*(int l, const Fraction &f)
{
    return Fraction(l, 1) * f;
};

/**
 * @brief Dodaje liczbe do ulamka
 *
 * @param l
 * @param f
 * @return Fraction
 */
inline Fraction operator+(int l, const Fraction &f)
{
    return Fraction(l, 1) + f;
};

/**
 * @brief Wypisuje ulamek na ekran
 *
 * @param os
 * @param l
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os, const Fraction &l);
