#pragma once
#include "shape.h"
#include <iostream>

class Rectangle : public Shape
{
private:
    double a, b;

public:
    Rectangle(double a, double b) : a(a), b(b){};
    void print(std::ostream &stream) const override
    {
        Shape::print(stream);
        stream << "Prostokat o bokach: " << a << " " << b << std::endl;
    };
    double area() const override { return a * b; };
};
