#include "Double.h"
#include <iostream>

void Double::Print() const
{
    Double *th = const_cast<Double *>(this);
    th->licznik++;
    std::cout << "Print nr " << licznik << ". Val = " << x << std::endl;
}

Double Dodaj(const Double &d1, const Double &d2)
{
    return Double(d1.GetX() + d2.GetX());
}

void Print(const Double &d)
{
    d.Print();
};