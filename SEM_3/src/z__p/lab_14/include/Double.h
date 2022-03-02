#pragma once

#include "Wymierne.h"

using wymierne::Wymierne;

class Double
{
private:
    double x;
    int licznik;

public:
    Double(double x) : x(x), licznik(0){};
    Double(const Wymierne &w) : Double(double(w)){};

    double GetX() const { return x; };
    void SetX(const Double &d) const { const_cast<Double *>(this)->x = d.x; };

    void Print() const;
};

Double Dodaj(const Double &d1, const Double &d2);
void Print(const Double &d);
