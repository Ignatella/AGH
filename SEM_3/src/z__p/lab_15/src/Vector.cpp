#include "Vector.h"
#include <cmath>
#include <iostream>
#include <utility>

using vector::Vector;

Vector::Vector(int size) : _size(size)
{
    this->_v = new double[size]();
}

Vector::Vector(double el1, double el2) : Vector(2)
{
    _v[0] = el1;
    _v[1] = el2;
}

Vector::Vector(Vector &&vec) : _v(std::exchange(vec._v, nullptr)), _size(std::exchange(vec._size, 0))
{
    vec._v = new double[0]();
}

Vector::Vector(const Vector &vec) : Vector(vec._size)
{
    for (int i = 0; i < _size; i++)
        _v[i] = vec[i];
}

Vector::~Vector()
{
    if (_v != nullptr)
    {
        delete[] _v;
        _v = nullptr;
    }
}

void Vector::print(std::string prefix) const
{
    std::cout << prefix << "[";

    for (int i = 0; i < _size; i++)
        std::cout << _v[i] << ", ";

    if (_size != 0)
        std::cout << "\b\b";

    std::cout << "]" << std::endl;
}

Vector Vector::extended(int newSize) const
{
    Vector res(newSize);
    for (int i = 0; i < _size; i++)
        res[i] = _v[i];

    return res;
}

double Vector::norm() const
{
    double sum = 0;

    for (int i = 0; i < _size; i++)
        sum += _v[i] * _v[i];

    return sqrt(sum);
}

double vector::dot(const Vector &v1, const Vector &v2)
{
    int size = v1.Size() > v2.Size() ? v1.Size() : v2.Size();

    double res = 0;

    for (int i = 0; i < size; i++)
        res += (i < v1.Size() ? v1[i] : 0) * (i < v2.Size() ? v2[i] : 0);

    return res;
}

Vector vector::sum(const Vector &v1, const Vector &v2)
{
    int size = v1.Size() > v2.Size() ? v1.Size() : v2.Size();

    Vector res(size);

    for (int i = 0; i < size; i++)
        res[i] = (i < v1.Size() ? v1[i] : 0) + (i < v2.Size() ? v2[i]
                                                              : 0);

    return res;
}