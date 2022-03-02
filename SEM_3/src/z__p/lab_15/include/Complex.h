#pragma once
#include <iostream>
#include <utility>
#include <iostream>

namespace vector{ 
    class Vector;
}

namespace complex
{
    class Complex
    {
    private:
        double _re, _im;

    public:
        Complex(double re, double im) : _re(re), _im(im){};
        Complex(double re) : Complex(re, 0){};
        Complex(const vector::Vector &v);
        Complex(Complex &&c) : _re(std::exchange(c._re, 0)), _im(std::exchange(c._im, 0)){};

        double getRe() const { return _re; };
        double getIm() const { return _im; };
        void print(std::string prefix) const;
    };

    Complex sum(const Complex &c1, const Complex &c2);
}
