#pragma once
#include "shape.h"
#include <iostream>
#include <cmath>

class Triangle : public Shape
{
private:
    double a, b, c;

public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c){};
    double perimeter() const { return a + b + c; };
    void print(std::ostream &stream) const override
    {
        Shape::print(stream);
        stream << "Trojkat o bokach: " << a << " " << b << " " << c << std::endl;
    };

    double area() const override
    {
        double p = perimeter() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    };
};
