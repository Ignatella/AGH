#pragma once

#include <iostream>
#include <stdexcept>

/**
 * @brief Test object
 *
 */
class TestObject
{
private:
    /**
     * @brief id objektu
     *
     */
    int _id;

public:
    /**
     * @brief Tworzy TestObject
     *
     * @param id
     */
    TestObject(int id = 0) : _id(id){};

    /**
     * @brief Ustawia id objektu
     *
     * @param id
     */
    void set(unsigned int id) { _id = id; }

    /**
     * @brief Wypisuje id objektu
     *
     */
    void print() const { std::cout << "Obiekt o identyfikatorze ID = " << _id << std::endl; }
};

/**
 * @brief Wektor
 *
 */
class Vector
{
private:
    /**
     * @brief Wewnetrzna struktura danych  na ktora opiera sie Wektor
     *
     */
    static void *_arr;

    /**
     * @brief Rozmiar wektora
     *
     */
    static unsigned int _size;

public:
    /**
     * @brief Inicjializuje wektor
     *
     * @tparam T
     * @param size
     */
    template <typename T>
    static void initialise(unsigned int size)
    {
        _size = size;
        _arr = new T[size]();
    }

    /**
     * @brief Inicjalizuje wektor i ustawia kopie 1 objektu na wszystkie pozycje
     *
     * @tparam T
     * @param size
     * @param firstObj
     */
    template <typename T>
    static void initialise(unsigned int size, T firstObj)
    {
        initialise<T>(size);

        if (size == 0)
            return;

        // at<T>(0) = firstObj;
        // for (size_t i = 0; i < _size; i++)

        for (size_t i = 0; i < _size; i++)
        {
            T copy(firstObj);
            at<T>(i) = copy;
        }
    }

    /**
     * @brief Pozwala ustawiac i pobierac elementy wektora
     *
     * @tparam T
     * @param i
     * @return T&
     */
    template <typename T>
    static T &at(unsigned int i)
    {
        if (i >= _size)
            throw std::invalid_argument("Index is out range.");

        return ((T *)_arr)[i];
    }

    /**
     * @brief Zwraca rozmiar wektora
     *
     * @return unsigned int
     */
    static unsigned int size() { return _size; }

    /**
     * @brief Resetuje wektor czyszczac pamiec
     *
     * @tparam T
     */
    template <typename T>
    static void reset()
    {
        if (_arr == nullptr)
            return;

        _size = 0;
        delete[](T *) _arr;
        _arr = nullptr;
    }
};

void *Vector::_arr = nullptr;
unsigned int Vector::_size = 0;