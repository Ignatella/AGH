#pragma once

#include "Operation.h"

#include <iostream>

class Division : public Operation
{
private:
    double _a, _b;

public:
    Division(double a, double b) : _a{a}, _b{b} {};

    virtual void print() const { std::cout << _a << " / " << _b; };
    virtual double eval() const { return _a / _b; };
};
