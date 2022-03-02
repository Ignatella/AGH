#include "fraction.h"
#include <iostream>

Fraction::Fraction(double v)
{
    double l = v;
    double m = 1;

    while (l / (int)l != 1)
    {
        l *= 10;
        m *= 10;
    }

    this->l = Fraction(l, m).l;
    this->m = Fraction(l, m).m;
}

int nwd(int m, int n)
{
    m = abs(m);
    n = abs(n);

    int oldm, oldn;
    while (m % n != 0)
    {
        oldm = m;
        oldn = n;
        m = oldn;
        n = oldm % oldn;
    }
    return n;
}

std::ostream &operator<<(std::ostream &os, const Fraction &l)
{
    int i = l.l / l.m;

    if (i != 0)
        os << i << " ";

    if (l.l - i * l.m != 0)
    {
        if (i != 0) 
            os << abs(l.l - i * l.m) << "/" << abs(l.m);
        else 
            os << l.l - i * l.m << "/" << abs(l.m);
    }

    return os;
}