#include "Complex.h"
#include "Vector.h"
#include <iostream>

using complex::Complex;
using vector::Vector;

Complex::Complex(const Vector &v) : Complex(v[0], v[1]) {}

void Complex::print(std::string prefix) const
{
    std::cout << prefix << _re;

    if (_im != 0)
        std::cout << " + " << _im << "i";

    std::cout << std::endl;
}

Complex complex::sum(const Complex &c1, const Complex &c2)
{
    return Complex(c1.getRe() + c2.getRe(), c1.getIm() + c2.getIm());
}