#pragma once

#include <iostream>
#include "Complex.h"

/**
 * @brief Reprezentacja wektora
 * 
 */
class Vector
{
private:
    /**
     * @brief Struktura danych na ktora opiera sie 'kolekcja' Vector
     * 
     */
    double *_v;

    /**
     * @brief Rozmiar _v 
     * 
     */
    int _size;

public:
    /**
     * @brief Tworzy wektor o rozmiarze 'size'
     * 
     * @param size rozmiar wektora
     */
    explicit Vector(int size);

    /**
     * @brief Tworzy 2 elementowy wektor o wartosciach el1 i el2
     * 
     * @param el1 _v[0]
     * @param el2 _v[1]
     */
    Vector(double el1, double el2);

    /**
     * @brief Tworzy 2 elementowy wektor z liczby zespolonej
     * 
     * @param c liczba zespolona
     */
    Vector(const Complex &c) : Vector(c.getRe(), c.getIm()){};

    /**
     * @brief Konstruktor kopiujacy wektora
     * 
     * @param v wektor, ktory zostanie skopiowany
     */
    Vector(const Vector &v);

    /**
     * @brief Konstruktor przenoszacy wektora
     * 
     * @param v wektor, ktorego wartosci zostana przeniesione
     */
    Vector(Vector &&v);

    /**
     * @brief Wypisuje wektor na ekran
     * 
     * @param prefix ktory zostanie wypisany przed wektorem
     */
    void print(std::string prefix) const;

    /**
     * @brief Oblicza norme wektora 
     * 
     * @return double norma wektora
     */
    double norm() const;

    /**
     * @brief Pobiera wartosc wektora pod indeksem i
     * 
     * @param i indeks obiektu
     * @return double& wartosc pod indeksem i
     */
    double &operator[](int i) const { return _v[i]; };

    /**
     * @brief Konwertuje wektor na double (oblicza norme)
     * 
     * @return double norma wektora
     */
    operator double() const { return norm(); };

    /**
     * @brief Przypisuje wektor vec do obecnego obiektu
     * 
     * @param vec wektor, ktory zostanie przypisany
     * @return wektor po przypisaniu
     */
    Vector &operator=(const Vector &vec);

    /**
     * @brief Dodaje 2 wektory
     * 
     * @param vec
     * @return wynik dodawania wektora vec do obecnego obiektu wektora
     */
    Vector operator+(const Vector &vec) const;

    /**
     * @brief Mnozy skalarnie 2 wektory
     * 
     * @param vec k
     * @return wynik skalarnego iloczynu wektora vec razy obecny wektor
     */
    Vector operator*(const Vector &vec) const;

    /**
     * @brief Usuwa z pamieci wektor
     * 
     */
    ~Vector();
};
