#pragma once
#include <iostream>

int nwd(int m, int n);

class Fraction
{
private:
    int l, m;

public:
    Fraction() = default;

    Fraction(int l, int m)
    {
        int n = nwd(l, m);
        this->l = l / n;
        this->m = m / n;
    };

    Fraction(double v);

    operator double() const { return (double)l / m; };
    Fraction operator*(const Fraction &f) const { return Fraction(f.l * l, f.m * m); };
    Fraction operator+(const Fraction &f) const { return Fraction(f.l * m + f.m * l, f.m * m); };
    Fraction &operator=(const Fraction &f) & { this->l = f.l; this->m = f.m; return *this; };
    Fraction operator+=(int l)
    {
        Fraction f = *this + Fraction(l, 1);
        this->l = f.l;
        this->m = f.m;
        return *this;
    };
    friend std::ostream &operator<<(std::ostream &os, const Fraction &f);
    friend Fraction operator*(int l, const Fraction &f);
};

inline Fraction operator*(int l, const Fraction &f)
{
    return Fraction(l, 1) * f;
};

std::ostream &operator<<(std::ostream &os, const Fraction &l);