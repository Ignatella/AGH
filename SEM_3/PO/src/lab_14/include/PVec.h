#pragma once

#include "Wrapper.h"
#include <vector>
#include <iostream>

/**
 * @brief Lista wrapperow
 * 
 */
class PVec
{
private:
    /**
     * @brief Struktura danych na ktora jest oparty PVec
     * 
     */
    std::vector<Wrapper *> v;

public:
    /**
     * @brief Dodaje wrapper na koniec listy
     * 
     * @param w 
     * @return PVec& 
     */
    PVec &push_back(Wrapper *w)
    {
        v.push_back(w);
        return *this;
    };

    /**
     * @brief Wypisuje typy przechowywanych wrapperow
     * 
     */
    void printType() const
    {
        std::cout << "[ ";

        for (int i = 0; i < size(); i++)
            std::cout << v[i]->type() << " ";

        std::cout << "]" << std::endl;
    };

    /**
     * @brief Zwraca rozmiar listy
     * 
     * @return unsigned int 
     */
    unsigned int size() const { return v.size(); };

    /**
     * @brief Dodaje wrapper na koniec listy
     * 
     * @param w 
     * @return PVec& 
     */
    PVec &operator<<(Wrapper *w) { return push_back(w); };

    /**
     * @brief Zwraca wrapper pod indeksem
     * 
     * @param i 
     * @return Wrapper& 
     */
    Wrapper &operator[](unsigned int i) const { return *v[i]; };

    /**
     * @brief Wypisuje liste na ekran
     * 
     * @param os 
     * @param l 
     * @return std::ostream& 
     */
    friend std::ostream &operator<<(std::ostream &os, const PVec &l)
    {
        os << "[ ";

        for (int i = 0; i < l.size(); i++)
        {
            l.operator[](i).print(os);
            os << " ";
        }

        os << "]" << std::endl;

        return os;
    };

    /**
     * @brief Usuwa liste z pamieci
     * 
     */
    ~PVec()
    {
        for (int i = 0; i < size(); i++)
            delete v[i];
    };
};
