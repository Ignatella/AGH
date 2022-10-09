#pragma once

#include <vector>

/**
 * @brief Przedstawia interfejs dla objektow, ktore mozna narysowac
 * 
 */
class Drawable
{
public:
    /**
     * @brief Rysuje objekt
     * 
     */
    virtual void draw() const = 0;

    /**
     * @brief Wylicza dlugosc objektu
     * 
     * @return double 
     */
    virtual double length() const = 0;
};

/**
 * @brief Przedstawia interfejs dla objektow, ktore mozna przesuwac
 * 
 */
class Transformable
{
public:
    /**
     * @brief Przesuwa objekt o dx i dy
     * 
     * @param dx 
     * @param dy 
     */
    virtual void shift(double dx, double dy) = 0;
};

/**
 * @brief Przedstawia interfejs dla objektow zamknietych
 * 
 */
class ClosedShape
{
public:
    /**
     * @brief Oblicza pole objektu
     * 
     * @return double 
     */
    virtual double area() const = 0;
};
