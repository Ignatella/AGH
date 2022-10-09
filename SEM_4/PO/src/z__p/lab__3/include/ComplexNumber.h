#pragma once

#include <iostream>

class ComplexNumber
{
private:
    double re_, im_;

private:
    double abs() const
    {
        return re_ * re_ + im_ * im_;
    };

public:
    ComplexNumber(double re, double im) : re_(re), im_(im){};
    explicit ComplexNumber(double re) : ComplexNumber(re, 0){};

    operator double() { return re_; };
    
    double &operator[](unsigned int i)
    {
        return i == 0 ? re_ : im_;
    };

    ComplexNumber &operator++(int)
    {
        re_++;
        return *this;
    };

    ComplexNumber &operator++()
    {
        re_++;
        return *this;
    };

    void operator*=(double n)
    {
        re_ *= n;
        im_ *= n;
    };

    friend bool operator>(const ComplexNumber &c1, const ComplexNumber &c2) { return c1.abs() > c2.abs(); };

    friend bool operator<(const ComplexNumber &c1, const ComplexNumber &c2) { return !operator>(c1, c2); };

    friend ComplexNumber operator*(const ComplexNumber &c1, const ComplexNumber &c2)
    {
        return ComplexNumber(c1.re_ * c2.re_ - c1.im_ * c2.im_, c1.re_ * c2.im_ + c2.re_ * c1.im_);
    };

    friend ComplexNumber operator-(const ComplexNumber &c1, const ComplexNumber &c2)
    {
        return ComplexNumber(c1.re_ - c2.re_, c1.im_ - c2.im_);
    }

    friend ComplexNumber operator+(const ComplexNumber &c1, const ComplexNumber &c2)
    {
        return ComplexNumber(c1.re_ + c2.re_, c1.im_ + c2.im_);
    };

    friend ComplexNumber operator+(int n, const ComplexNumber &c) { return ComplexNumber(c.re_ + n, c.im_); };

    friend std::ostream &operator<<(std::ostream &os, const ComplexNumber &c)
    {
        os << c.re_ << " + " << c.im_ << "i";
        return os;
    };
};
