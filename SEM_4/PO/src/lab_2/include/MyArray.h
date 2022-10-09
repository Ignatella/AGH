#pragma once

#include <iostream>
#include <string>
#include <utility>

/**
 * @brief Wrapper nad tablica liczb int
 * 
 */
class MyArray
{
private:
    /**
     * @brief Wewnetrzna struktura
     * 
     */
    int *_v;

    /**
     * @brief Rozmiar tablicy
     * 
     */
    unsigned int _size;

public:
    /**
     * @brief Tworzy tablice okreslonego rozmiaru
     * 
     * @param size 
     */
    MyArray(unsigned int size) : _size(size), _v(new int[size]()){};

    /**
     * @brief Kopiuje tablice
     * 
     * @param arr 
     */
    MyArray(const MyArray &arr) : MyArray(arr._size)
    {
        for (size_t i = 0; i < _size; i++)
            _v[i] = arr._v[i];
    };

    /**
     * @brief Przenosi tablice
     * 
     * @param arr 
     */
    MyArray(MyArray &&arr) : _size(std::exchange(arr._size, 0)), _v(std::exchange(arr._v, new int[0]())){};

    /**
     * @brief Zwraca rozmiar tablicy
     * 
     * @return unsigned int 
     */
    unsigned int size() const { return _size; };

    /**
     * @brief Wypisuje tablice na ekran
     * 
     * @param prefix 
     */
    void print(std::string prefix) const;

    /**
     * @brief Prypisuje jeden obiekt do tego
     * 
     * @param arr 
     * @return MyArray& 
     */
    MyArray &operator=(const MyArray &arr);

    /**
     * @brief Mnozy wektor razy liczbe
     * 
     * @param factor 
     * @return MyArray& 
     */
    MyArray &operator*=(int factor);

    /**
     * @brief Dodaje 1 dok azdego elementu tablicy
     * 
     * @return MyArray 
     */
    MyArray operator++(int);

    /**
     * @brief Daje dostep do kazdego elementu tablicy
     * 
     * @param i 
     * @return int& 
     */
    int &operator[](unsigned int i) const { return _v[i]; };

    /**
     * @brief Mnozy tablice razy factor
     * 
     * @param factor 
     * @param arr 
     * @return MyArray 
     */
    friend MyArray operator*(int factor, const MyArray &arr) { return arr * factor; };

    /** 
     * @brief  Mnozy tablice razy faktor
     * 
     * @param arr 
     * @param factor 
     * @return MyArray 
     */
    MyArray operator*(int factor) const;

    /**
     * @brief Wypisuje na ekran tablice
     * 
     * @param os 
     * @param arr 
     * @return std::ostream& 
     */
    friend std::ostream &operator<<(std::ostream &os, const MyArray &arr);

    /**
     * @brief Usuwa tablice z pamieci
     * 
     */
    ~MyArray()
    {
        std::cout << "Usuwam tablice" << std::endl;
        delete[] _v;
    };
};