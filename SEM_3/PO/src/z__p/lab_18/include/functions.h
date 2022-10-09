#pragma once
#include <cmath>
#include <functional>
#include <iostream>

class Linear
{
private:
    double _a, _b;

public:
    Linear(double a, double b) : _a(a), _b(b){};

    double operator()(double x) const { return _a * x + _b; };
};

class Sqrt
{
public:
    double operator()(double x) const { return sqrt(x); };
};

class Sin
{
private:
    double _a, _b;

public:
    Sin(double a, double b) : _a(a), _b(b){};

    double operator()(double x) const { return sin(_a * x + _b); };
};
