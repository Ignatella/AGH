#include "functionVector.h"

double FunctionVector::calc(double x)
{
    prevX = x;

    for (int i = 0; i < v.size(); i++)
    {
        x = v[i](x);
    }

    return x;
}

double FunctionVector::operator[](unsigned int k)
{
    double x = prevX;

    if (k > v.size() - 1)
        return 0;

    for (int i = 0; i <= k; i++)
    {
        x = v[i](x);
    }

    return x;
}