#include "Vector.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <utility>
#include <string>

Vector::Vector(int size)
{
    this->v = new double[size]();
    this->size = size;
}

Vector::Vector(double value) : Vector(1)
{
    this->v[0] = value;
}

Vector::Vector(const Vector &v)
{
    this->size = v.size;
    this->v = copyArr(v.size, v.v);
}

Vector::Vector(Vector &&v)
{
    this->v = v.v;
    this->size = v.size;

    v.size = 0;
    v.v = new double[0]();
}

double Vector::dot(const Vector &v1, const Vector &v2)
{
    int result = 0;

    for (int i = 0; i < v1.size; i++)
        result += v1.v[i] * (v2.size > i ? v2.v[i] : 0);

    return result;
}

Vector Vector::sum(const Vector &v1, const Vector &v2)
{
    int len = v1.size > v2.size ? v1.size : v2.size;
    Vector result = Vector(len);

    for (int i = 0; i < len; i++)
        result.v[i] += (v1.size > i ? v1.v[i] : 0) + (v2.size > i ? v2.v[i] : 0);

    return result;
}

Vector Vector::extended(int size)
{
    Vector result(size);
    for (int i = 0; i < this->size; i++)
        result.v[i] = v[i];

    return result;
}

double &Vector::vec(int index)
{
    return v[index];
}

void Vector::print(std::string prefix) const
{
    std::cout << prefix << "[";

    for (int i = 0; i < size; i++)
        std::cout << v[i] << ", ";

    std::cout << "\b\b"
              << "]" << std::endl;
}

double Vector::norm() const
{
    double result = 0;
    for (int i = 0; i < size; i++)
    {
        result += v[i] * v[i];
    }

    return sqrt(result);
}

Vector::operator double() const
{
    return norm();
}

Vector::~Vector()
{
    if (v != nullptr)
        delete[] v;
}

double *copyArr(int size, double arr[])
{
    double *copy = new double[size]();

    for (int i = 0; i < size; i++)
        copy[i] = arr[i];

    return copy;
}