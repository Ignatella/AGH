#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <functional>

/**
 * @brief Abstrakcja przechowujaca dynamiczna tablice
 * 
 */
class List
{
private:
    /**
     * @brief Wewnetrzna struktura
     * 
     */
    std::vector<int> _v;

public:
    /**
     * @brief Tworzy liste
     * 
     */
    List() : _v(std::vector<int>{}){};

    /**
     * @brief Dodaje element na koniec listy
     * 
     * @param el 
     */
    void insert(int el) { _v.push_back(el); };

    /**
     * @brief Wypisuje liste na ekran
     * 
     * @param prefix 
     */
    void print(std::string prefix = "") const;

    /**
     * @brief Filtruje liste ze wzgledu na podany kryterium
     * 
     * @param f kryterium
     * @return List 
     */
    List filter(std::function<bool(int)> f) const;

    /**
     * @brief Udziela dostepu do poszczegolnych elementow talicy
     * 
     * @param i 
     * @return int& 
     */
    int &operator[](unsigned int i) { return _v[i]; };
};
