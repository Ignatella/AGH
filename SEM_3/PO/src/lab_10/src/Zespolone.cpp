#include "Zespolone.h"
#include <iostream>

void Zespolone::Print(std::string prefix) const
{
    if (im == 0)
    {
        std::cout << prefix << re << std::endl;
        return;
    }

    std::cout << prefix << re << " + " << im << "i" << std::endl;
}

Zespolone Dodaj(const Zespolone &z1, const Zespolone &z2)
{
    return Zespolone(z1.re + z2.re, z1.im + z2.im);
}