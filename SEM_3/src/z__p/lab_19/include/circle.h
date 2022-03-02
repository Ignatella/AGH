#pragma once

#define _USE_MATH_DEFINES

#include "shape.h"
#include <iostream>
#include <cmath>

class Circle : public Shape
{
private:
    double r;

public:
    Circle(double r) : r(r){};
    void print(std::ostream &stream) const override
    {
        Shape::print(stream);
        stream << "Kolo o promieniu: " << r << std::endl;
    };
    double area() const override { return M_PI * pow(r, 2); }
};
