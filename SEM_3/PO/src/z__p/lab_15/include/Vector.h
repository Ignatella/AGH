#pragma once

#include <iostream>
#include "Complex.h"

using complex::Complex;

namespace vector
{
    class Vector
    {
    private:
        double *_v;
        int _size;

    public:
        explicit Vector(int size);
        explicit Vector(double v) : Vector(1) { _v[0] = v; };
        Vector(double el1, double el2);
        Vector(const Complex &c) : Vector(c.getRe(), c.getIm()){};
        Vector(const Vector &v);
        Vector(Vector &&v);

        void print(std::string prefix) const;
        int Size() const { return _size; };

        Vector extended(int newSize) const;

        double norm() const;

        double &operator[](int i) const { return _v[i]; };
        operator double() const { return norm(); };

        ~Vector();
    };

    double dot(const Vector &v1, const Vector &v2);
    Vector sum(const Vector &v1, const Vector &v2);
}
