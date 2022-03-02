#pragma once

#include "Vector.h"

using vector::Vector;

class Double
{
private:
    double x;
    int counter;

public:
    Double(double x) : x(x), counter(0) {};
    Double(const Vector &v) : Double(v.norm()){};

    void setconstx(double x) const { const_cast<Double *>(this)->x = x; };
    void setx(const Double &d) { this->x = d.x; };
    double getx() const {return x;};

    void print() const;
};

double sum(const Double &d1, const Double &d2);
void print(const Double &x);
