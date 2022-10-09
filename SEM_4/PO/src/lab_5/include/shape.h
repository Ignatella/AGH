#pragma once

#include "abstract.h"
#include <math.h>

/**
 * @brief Przedstawia punkt
 * 
 */
class Point : public Transformable
{
private:
    /**
     * @brief Skladowa x
     * 
     */
    double _x;

    /**
     * @brief Skladowa y
     * 
     */
    double _y;

public:
    /**
     * @brief Tworzy punkt o zadanych x i y
     * 
     * @param x 
     * @param y 
     */
    Point(double x, double y) : _x(x), _y(y){};

    /**
     * @brief Pobiera wspolrzedna x
     * 
     * @return double 
     */
    double get_x() const { return _x; };

    /**
     * @brief Pobiera wspolrzedna y
     * 
     * @return double 
     */
    double get_y() const { return _y; };

    /**
     * @brief Przesuwa punkt
     * 
     * @param dx 
     * @param dy 
     */
    virtual void shift(double dx, double dy)
    {
        _x += dx;
        _y += dy;
    };

    /**
     * @brief Wypisuje punkt na ekran
     * 
     * @param os 
     * @param p 
     * @return std::ostream& 
     */
    friend std::ostream &operator<<(std::ostream &os, const Point &p)
    {
        os << "(" << p._x << ", " << p._y << ")";
        return os;
    };
};

/**
 * @brief Abstrakcja przedstawiajaca figure
 * 
 */
class Shape : public Transformable, public Drawable
{
protected:
    /**
     * @brief Punkty figury
     * 
     */
    std::vector<Point> _points;

public:
    /**
     * @brief Tworzy figure
     * 
     * @param points 
     */
    Shape(std::initializer_list<Point> points) : _points(points){};

    /**
     * @brief Przesuwa figure
     * 
     * @param dx 
     * @param dy 
     */
    virtual void shift(double dx, double dy)
    {
        for (auto &p : _points)
        {
            p.shift(dx, dy);
        }
    };

    /**
     * @brief Rysuje figure
     * 
     */
    virtual void draw() const = 0;
};

/**
 * @brief Okrag
 * 
 */
class Circle : public Shape, public ClosedShape
{
private:
    /**
     * @brief Promien okregu
     * 
     */
    double _r;

public:
    /**
     * @brief Tworzy okrag
     * 
     * @param p 
     * @param r 
     */
    Circle(const Point &p, double r) : Shape{p}, _r(r){};

    /**
     * @brief Oblicza dlugosc okregu
     * 
     * @return double 
     */
    virtual double length() const { return 2 * M_PI * _r; };

    /**
     * @brief Oblicza pole okregu
     * 
     * @return double 
     */
    virtual double area() const { return M_PI * _r * _r; };

    /**
     * @brief Rysuje okrag
     * 
     */
    virtual void draw() const
    {
        std::cout << "Rysujemy kolo o srodku " << _points[0] << " i promieniu " << _r << std::endl;
    };
};

/**
 * @brief Odcinek
 * 
 */
class Section : public Shape
{
public:
    /**
     * @brief Tworzy odcinek
     * 
     * @param p1 
     * @param p2 
     */
    Section(const Point &p1, const Point &p2) : Shape{p1, p2} {};

    /**
     * @brief Pobiera punkt 1 odcinku
     * 
     * @return Point 
     */
    Point get_p1() const { return _points[0]; };

    /**
     * @brief Pobiera punkt 2 odcinku
     * 
     * @return Point 
     */
    Point get_p2() const { return _points[1]; };

    /**
     * @brief Zwraca dlugosc odcinku
     * 
     * @return double 
     */
    virtual double length() const { return sqrt(pow(_points[1].get_x() - _points[0].get_x(), 2) + pow(_points[1].get_y() - _points[0].get_y(), 2)); };

    /**
     * @brief Rysuje odcinek
     * 
     */
    virtual void draw() const
    {
        std::cout << "Rysujemy odcinek od " << _points[0] << " do " << _points[1] << std::endl;
    };
};

/**
 * @brief Deltoid
 * 
 */
class Deltoid : public Shape, public ClosedShape
{
public:
    /**
     * @brief Tworzy deltoid z 2 diagonali
     * 
     * @param d1 
     * @param d2 
     */
    Deltoid(const Section &d1, const Section &d2) : Shape{d1.get_p1(), d2.get_p1(), d1.get_p2(), d2.get_p2()} {};

    /**
     * @brief Tworzy deltoid z 4 punktow
     * 
     * @param p1 
     * @param p2 
     * @param p3 
     * @param p4 
     */
    Deltoid(const Point &p1, const Point &p2, const Point &p3, const Point &p4) : Shape{p1, p2, p3, p4} {};

    /**
     * @brief Oblicza dlugosc deltoidu
     * 
     * @return double 
     */
    virtual double length() const
    {
        return Section(_points[0], _points[1]).length() +
               Section(_points[1], _points[2]).length() +
               Section(_points[2], _points[3]).length() +
               Section(_points[3], _points[0]).length();
    };

    /**
     * @brief Zwraca pole deltoidu
     * 
     * @return double 
     */
    virtual double area() const
    {
        return 0.5 * Section(_points[0], _points[2]).length() * Section(_points[1], _points[3]).length();
    };

    /**
     * @brief Rysuje deltoid
     * 
     */
    virtual void draw() const
    {
        std::cout << "Rysujemy deltoid o wierzcholkach " << _points[0] << ", " << _points[1] << ", "
                  << _points[2] << ", " << _points[3] << ", " << std::endl;
    };
};
