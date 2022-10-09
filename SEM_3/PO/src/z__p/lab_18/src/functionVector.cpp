#include "functionVector.h"

void FunctionVector::insert(std::function<double(double x)> fun)
{
    v.push_back(fun);
}

double FunctionVector::calc(double x) const
{
    const_cast<FunctionVector *>(this)->prevX = x;

    for (int i = 0; i < v.size(); i++)
    {
        x = v[i](x);
    }

    return x;
}

double FunctionVector::operator[](int k)
{
    double x = prevX;

    for (int i = 0; i <= k; i++)
    {
        x = v[i](x);
    }

    return x;
}