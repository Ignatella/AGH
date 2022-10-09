#pragma once

#include <vector>
#include <functional>

/**
 * @brief Przechowuje filtr kryteria
 * 
 */
class FilterCriteria
{
private:
    /**
     * @brief Wewnetrzna struktura
     * 
     */
    std::vector<std::function<bool(int)>> _v;

public:
    /**
     * @brief Tworzy FilterCriteria
     * 
     */
    FilterCriteria() : _v(std::vector<std::function<bool(int)>>{}){};

    /**
     * @brief Dodaje filtr kryterium do listy
     * 
     * @param f 
     */
    void add(std::function<bool(int)> f) { _v.push_back(f); };

    /**
     * @brief Zwraca ilosc przechowywanych kryteriow
     * 
     * @return std::size_t 
     */
    std::size_t size() { return _v.size(); };

    /**
     * @brief Zwraca poszczegolny kreterium
     * 
     * @param i 
     * @return std::function<bool(int)> 
     */
    std::function<bool(int)> get(unsigned int i) { return _v[i]; };
};
