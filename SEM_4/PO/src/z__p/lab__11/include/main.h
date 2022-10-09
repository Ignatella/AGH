#pragma once

#include <iostream>
#include <math.h>

class Drawable
{
public:
    virtual void draw() const = 0;
    virtual double length() const = 0;
};

class Transformable
{
public:
    virtual void shift(double dx, double dy) = 0;
};

class ClosedShape
{
public:
    virtual double area() const = 0;
};

class Point : public Transformable
{
private:
    double _x;
    double _y;

public:
    Point(double x, double y) : _x(x), _y(y){};

    double get_x() const { return _x; };
    double get_y() const { return _y; };

    virtual void shift(double dx, double dy)
    {
        _x += dx;
        _y += dy;
    };

    friend std::ostream &operator<<(std::ostream &os, const Point &p)
    {
        os << "(" << p._x << ", " << p._y << ")";
        return os;
    };
};

class Circle : public Drawable, public Transformable, public ClosedShape
{
private:
    Point _p;
    double _r;

public:
    Circle(const Point &p, double r) : _p(p), _r(r){};

    virtual double length() const { return 2 * M_PI * _r; };
    virtual void shift(double dx, double dy) { _p.shift(dx, dy); };
    virtual double area() const { return M_PI * _r * _r; };
    virtual void draw() const
    {
        std::cout << "Rysujemy kolo o srodku " << _p << " i promieniu " << _r << std::endl;
    };
};

class Section : public Drawable, public Transformable
{
private:
    Point _p1;
    Point _p2;

public:
    Section(const Point &p1, const Point &p2) : _p1(p1), _p2(p2){};

    Point get_p1() const { return _p1; };
    Point get_p2() const { return _p2; };

    virtual double length() const { return sqrt(_p1.get_x() * _p1.get_x() + _p2.get_y() * _p2.get_y()); };
    virtual void shift(double dx, double dy)
    {
        _p1.shift(dx, dy);
        _p2.shift(dx, dy);
    };

    virtual void draw() const
    {
        std::cout << "Rysujemy odcinek od " << _p1 << " do " << _p2 << std::endl;
    };
};

class Deltoid : public Drawable, public Transformable, public ClosedShape
{
private:
    Section _d1;
    Section _d2;

public:
    Deltoid(const Section &d1, const Section &d2) : _d1(d1), _d2(d2){};
    Deltoid(const Point &p11, const Point &p12, const Point &p21, const Point &p22) : _d1(p11, p12), _d2(p21, p22){};

    virtual double length() const { return 2 * sqrt(_d1.length() * _d1.length() + _d2.length() * _d2.length()); };
    virtual double area() const { return 1 / 2.0 * _d1.length() * _d2.length(); };
    virtual void shift(double dx, double dy)
    {
        _d1.shift(dx, dy);
        _d2.shift(dx, dy);
    };

    virtual void draw() const
    {
        std::cout << "Rysujemy deltoid o wierzcholkach " << _d1.get_p1() << ", " << _d1.get_p2() << ", "
                  << _d2.get_p1() << ", " << _d2.get_p2() << ", " << std::endl;
    };
};

void draw(const Drawable *d)
{
    d->draw();
};