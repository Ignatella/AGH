#pragma once
#include "functions.h"
#include <vector>
#include <functional>

/**
 * @brief Kolekcja funkcji
 * 
 */
class FunctionVector
{
private:
    /**
     * @brief Podstawa kolekcji
     * 
     */
    std::vector<std::function<double(double x)>> v;

    /**
     * @brief x, z ktorym nastapilo poprzednie wywolanie funkcji calc
     * 
     */
    double prevX;

public:
    /**
     * @brief Dodaje funckje do kolekcji
     * 
     * @param fun funkcja ktora zostanie dodana do kolekcji
     */
    void insert(std::function<double(double x)> fun) { v.push_back(fun); };

    /**
     * @brief Oblicza warosci wszystkich funkcji zgodnie z powyzszym schematem
     *      f[0] = f1(x)
     *      f[1] = f2 (f1(x))
     *      f[2] = f3 (f2 (f1(x)))
     *  
     * @param x 
     * @return double 
     */
    double calc(double x);

    /**
     * @brief Zwraca wartosc funkcji dla poprzedniego x
     * 
     * @param i index
     * @return double 
     */
    double operator[](unsigned int i);
};
