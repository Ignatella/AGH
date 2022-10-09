#pragma once

#include "Wymierne.h"
#include <iostream>
#include <utility>

using wymierne::Wymierne;

namespace zespolone
{
    class Zespolone
    {
    private:
        double re;
        double im;

    public:
        Zespolone(double re) : Zespolone(re, 0){};
        Zespolone(double re, double im) : re(re), im(im){};
        Zespolone(const Wymierne &w) : Zespolone((double)w){};
        Zespolone(Zespolone &&z) : re(std::exchange(z.re, 0)), im(std::exchange(z.im, 0)) {}

        double getRe() const { return re; };
        double getIm() const { return im; };
        void Print(std::string prefix) const;
        void Print() const;
    };

    Zespolone Dodaj(const Zespolone &z1, const Zespolone &z2);
}