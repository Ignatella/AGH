#pragma once
#include <iostream>

namespace wymierne
{
    class Wymierne
    {
    private:
        int licznik;
        int mianownik;

    private:
        void Simplify();

    public:
        Wymierne() : Wymierne(0){};
        explicit Wymierne(int licznik) : Wymierne(licznik, 1){};
        Wymierne(int licznik, int mianownik) : licznik(licznik)
        {
            this->mianownik = mianownik == 0 ? 1 : mianownik;
            Simplify();
        };

        int GetLicznik() const { return licznik; };
        int GetMianownik() const { return mianownik; };
        void Print(std::string prefix) const;

        operator double() const { return (double)licznik / mianownik; };
    };

    Wymierne Dodaj(const Wymierne &w1, const Wymierne &w2);
    Wymierne Pomnoz(const Wymierne &w1, const Wymierne &w2);

    int Nwd(int m, int n);
}