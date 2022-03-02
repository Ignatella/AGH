#pragma once
#include <cmath>
#include <functional>
#include <iostream>

/**
 * @brief Funckcja liniowa
 * 
 */
class Linear
{
private:
    /**
     * @brief Wspolczynniki _a * x + _b
     * 
     */
    double _a, _b;

public:
    /**
     * @brief Tworzy funkcje liniowa
     * 
     * @param a Wspolczynnik _a
     * @param b Wspolczynnik _b
     */
    Linear(double a, double b) : _a(a), _b(b){};

    /**
     * @brief Oblicza wartosc funkcji dla okreslonego x
     * 
     * @param x 
     * @return double 
     */
    double operator()(double x) const { return _a * x + _b; };

    /**
     * @brief Wypisuje obecna postac funkcji na ekran
     * 
     * @param os stream, do ktorego nastepuje wypisanie
     * @param f funkcja liniowa
     * @return std::ostream& 
     */
    friend std::ostream &operator<<(std::ostream &os, const Linear &f)
    {
        os << f._a << "x" << f._b << std::endl;
        return os;
    };
};

/**
 * @brief Funkcja pierwiastka
 * 
 */
class Sqrt
{
public:
    /**
     * @brief Oblicza wartosc funkcji dla okreslonego x
     * 
     * @param x 
     * @return double 
     */
    double operator()(double x) const { return sqrt(x); };

    /**
     * @brief Wypisuje obecna postac funkcji na ekran
     * 
     * @param os stream, do ktorego nastepuje wypisanie
     * @param f funkcja pierwiastka
     * @return std::ostream& 
     */
    friend std::ostream &operator<<(std::ostream &os, const Sqrt &f)
    {
        os << "sqrt(x)" << std::endl;
        return os;
    };
};

/**
 * @brief Funkcja sinusa
 * 
 */
class Sin
{
private:
    /**
     * @brief Wspolczynniki sin (_a  * x + _b)
     * 
     */
    double _a, _b;

public:
    /**
     * @brief Tworzy funkcje sinusa
     * 
     * @param a 
     * @param b 
     */
    Sin(double a, double b) : _a(a), _b(b){};

    /**
     * @brief Oblicza wartosc funkcji dla okreslonego x
     * 
     * @param x 
     * @return double 
     */
    double operator()(double x) const { return sin(_a * x + _b); };

    /**
     * @brief Wypisuje obecna postac funkcji na ekran
     * 
     * @param os stream, do ktorego nastepuje wypisanie
     * @param f funkcja sinusa
     * @return std::ostream& 
     */
    friend std::ostream &operator<<(std::ostream &os, const Sin &f)
    {
        os << "sin(" << f._a << "*x+" << f._b << ")" << std::endl;
        return os;
    };
};
