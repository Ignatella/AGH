#include "Vector.h"
#include <cmath>
#include <iostream>
#include <utility>

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

double Vector::norm() const
{
    double sum = 0;

    for (int i = 0; i < _size; i++)
        sum += _v[i] * _v[i];

    return sqrt(sum);
}

Vector Vector::operator+(const Vector &vec) const
{
    int size = _size > vec._size ? _size : vec._size;

    Vector res(size);

    for (int i = 0; i < size; i++)
        res[i] = (i < _size ? _v[i] : 0) + (i < vec._size ? vec[i]
                                                              : 0);

    return res;
}

Vector Vector::operator*(const Vector &vec) const
{
    int size = _size > vec._size ? _size : vec._size;

    Vector res(1);

    for (int i = 0; i < size; i++)
        res[0] += (i < _size ? _v[i] : 0) * (i < vec._size ? vec[i] : 0);

    return res;
}

Vector &Vector::operator=(const Vector &vec)
{
    delete[] this->_v;
    this->_size = vec._size;
    this->_v = new double[_size]();

    for (int i = 0; i < vec._size; i++)
        this->_v[i] = vec[i];

    return *this;
}