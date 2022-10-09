#pragma once

#include "Operation.h"

class SumOfElements : public Operation
{
private:
    double *_a;
    unsigned int _b;

public:
    SumOfElements(double *a, unsigned int b) : _a{a}, _b{b} {};

    virtual void print() const
    {
        for (int i = 0; i < _b; i++)
            std::cout << _a[i] << " + ";

        if (_b > 0)
            std::cout << "\b\b\b";
    };

    virtual double eval() const
    {
        double result = 0;
        for (int i = 0; i < _b; i++)
            result += _a[i];
        return result;
    };
};
