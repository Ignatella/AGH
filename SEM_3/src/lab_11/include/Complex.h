#pragma once
#include <iostream>
#include <utility>
#include <iostream>

class Vector;

/**
 * @brief Reprezentacja liczby zespolonej
 * 
 */
class Complex
{
private:
    /**
     * @brief Cześć rzeczywista i urojona liczby zespolonej
     * 
     */
    double _re, _im;

    /**
     * @brief Licznik sluzy dla zapamietywania ilosci wypisow obiektu
     * 
     */
    int _counter;

public:
    /**
     * @brief Tworzy liczbe zespolona
     * 
     * @param re czesc rzeczywista
     * @param im czesc urojona
     */
    Complex(double re, double im) : _re(re), _im(im), _counter(0) {};

    /**
     * @brief Tworzy liczbe zespolona, ktora ma tylko czesc rzeczywista
     * 
     * @param re czesc rzeczywista
     */
    Complex(double re) : Complex(re, 0){};

    /**
     * @brief Tworzy liczbe zespolona z wektoru 2 elementowego
     * 
     * @param v wektor
     */
    explicit Complex(const Vector &v);

    /**
     * @brief Konstruktor przenoszacy
     * 
     * @param c liczba zespolona z ktora zostana pobrane wartosci
     */
    Complex(Complex &&c) : _re(std::exchange(c._re, 0)), _im(std::exchange(c._im, 0)){};

    /**
     * @brief Pobiera czesc rzeczywista liczby zespolonej (getter)
     *          Getter ten jest wykorzystywany przez klase wektor
     * 
     * @return czesc reczywista
     */
    double getRe() const { return _re; };

    /**
     * @brief Pobiera czesc urojona liczby zespolonej (getter)
     *           Getter ten jest wykorzystywany przez klase wektor
     * 
     * @return czesc urojona
     */
    double getIm() const { return _im; };

    /**
     * @brief Wypisuje na ekran liczbe zespolona
     * 
     * @param prefix jest wypisywany przed liczba zespolona
     */
    void print(std::string prefix) const;

    /**
     * @brief Dodaje 2 liczby zespolone
     * 
     * @param c1 druga liczba zespolona
     * @return wynik dodawania 2 liczb zespolonych
     */
    Complex operator+(const Complex &c1) const;

    /**
     * @brief Przypisuje obecnej liczbie zespolonej inna liczbe zespolona
     * 
     * @param c1 liczba zespolona ktora zostanie przypisana do obecnej liczby
     * @return obiekt na ktorym zostal uzyty operator
     */
    Complex &operator=(const Complex &c1);
};
