#include "Wymierne.h"
#include <iostream>

void Wymierne::Print(std::string prefix) const
{
    if (licznik == 0)
    {
        std::cout << prefix << "0" << std::endl;
        return;
    }

    if (mianownik == 1)
    {
        std::cout << prefix << licznik << std::endl;
        return;
    }

    std::cout << prefix << licznik << "/" << mianownik << std::endl;
};

Wymierne Pomnoz(const Wymierne &w1, const Wymierne &w2)
{
    return Wymierne(w1.licznik * w2.licznik, w1.mianownik * w2.mianownik);
};
