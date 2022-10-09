#include "Vector.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <utility>
#include <string>

Vector::Vector(int size)
{
    this->v = std::vector<double>(size);
}

Vector::Vector(double value) : Vector(1)
{
    this->v[0] = value;
}

Vector::Vector(const Vector &v)
{
    this->v = v.v;
}

Vector::Vector(Vector &&v) : v(std::move(v.v)) {}

double Vector::dot(const Vector &v1, const Vector &v2)
{
    int result = 0;

    for (int i = 0; i < v1.v.size(); i++)
        result += v1.v[i] * (v2.v.size() > i ? v2.v[i] : 0);

    return result;
}

Vector Vector::sum(const Vector &v1, const Vector &v2)
{
    int len = v1.v.size() > v2.v.size() ? v1.v.size() : v2.v.size();
    Vector result = Vector(len);

    for (int i = 0; i < len; i++)
        result.v[i] += (v1.v.size() > i ? v1.v[i] : 0) + (v2.v.size() > i ? v2.v[i] : 0);

    return result;
}

Vector Vector::extended(int size)
{
    Vector result(size);
    for (int i = 0; i < v.size(); i++)
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

    for (auto &element : v)
        std::cout << element << ", ";

    std::cout << "\b\b"
              << "]" << std::endl;
}

double Vector::norm() const
{
    double result = 0;
    for (auto &element : v)
    {
        result += element * element;
    }

    return sqrt(result);
}

Vector::operator double() const
{
    return norm();
}
