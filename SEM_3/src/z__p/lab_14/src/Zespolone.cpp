#include "Zespolone.h"
#include <iostream>

using zespolone::Zespolone;

void Zespolone::Print(std::string prefix) const
{
    std::cout << prefix;

    if (im == 0)
        std::cout << re << std::endl;
    else
        std::cout << re << " + " << im << "i" << std::endl;
}

void Zespolone::Print() const
{
    Print("");
}

Zespolone zespolone::Dodaj(const Zespolone &z1, const Zespolone &z2)
{
    return Zespolone(z1.getRe() + z2.getRe(), z1.getIm() + z2.getIm());
}