#pragma once
#include <vector>
#include <string>

class Vector
{
private:
    std::vector<double> v;

public:
    explicit Vector(int size);
    explicit Vector(double value);
    Vector(const Vector &v);
    Vector(Vector &&v);

    static double dot(const Vector &v1, const Vector &v2);
    static Vector sum(const Vector &v1, const Vector &v2);

    Vector extended(int size);

    double &vec(int index);
    void print(std::string prefix) const;
    double norm() const;

    operator double() const;
};
