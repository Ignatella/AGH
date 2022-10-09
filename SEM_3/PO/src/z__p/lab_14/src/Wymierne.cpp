#include "Wymierne.h"
#include <iostream>

using wymierne::Wymierne;

void Wymierne::Print(std::string prefix) const
{
    std::cout << prefix;

    if (licznik == 0 || mianownik == 1)
        std::cout << licznik << std::endl;
    else
        std::cout << licznik << "/" << mianownik << std::endl;
}

void Wymierne::Simplify()
{
    int nwd = Nwd(licznik, mianownik);
    licznik = licznik / nwd;
    mianownik = mianownik / nwd;
}

int wymierne::Nwd(int m, int n)
{
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

Wymierne wymierne::Dodaj(const Wymierne &w1, const Wymierne &w2)
{
    return Wymierne(
        w1.GetLicznik() * w2.GetMianownik() + w2.GetLicznik() * w1.GetMianownik(),
        w1.GetMianownik() * w2.GetMianownik());
}

Wymierne wymierne::Pomnoz(const Wymierne &w1, const Wymierne &w2)
{
    return Wymierne(w1.GetLicznik() * w2.GetLicznik(), w1.GetMianownik() * w2.GetMianownik());
}
