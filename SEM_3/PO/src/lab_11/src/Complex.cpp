#include "Complex.h"
#include "Vector.h"
#include <iostream>

Complex::Complex(const Vector &v) : Complex(v[0], v[1]) {}

void Complex::print(std::string prefix) const
{   
    const_cast<Complex *>(this)->_counter++;

    std::cout << "[Print " << _counter << "] "  << prefix << _re;

    if (_im != 0)
        std::cout << " + " << _im << "i";

    std::cout << std::endl;
}


Complex Complex::operator+(const Complex &c1) const
{
     return Complex(_re + c1._re, _im + c1._im);
}

Complex &Complex::operator=(const Complex &c1)
{
    this->_im = c1._im;
    this->_re = c1._re;

    return *this;
}