#include "Double.h"
#include <iostream>

void Double::print() const
{
    const_cast<Double *>(this)->counter++;
    std::cout << "Print nr " << counter << ". Val = " <<  x << std::endl;
}

double sum(const Double &d1, const Double &d2)
{
    return d1.getx() + d2.getx();
}

void print(const Double &x)
{
    x.print();
}