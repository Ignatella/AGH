#pragma once
#include "functions.h"
#include <vector>
#include <functional>

class FunctionVector
{
private:
    std::vector<std::function<double(double x)>> v;
    double prevX;

public:
    void insert(std::function<double(double x)> fun);
    double calc(double x) const;

    double operator[](int i);
};
