#pragma once

#include "Operation.h"
#include <math.h>

class Exponentiation : public Operation
{
private:
    double _a;
    double _b;

public:
    Exponentiation(double a, double b) : _a{a}, _b{b} {};

    virtual void print() const { std::cout << _a << " ^ " << _b; };

    virtual double eval() const { return pow(_a, _b); };
};
