#pragma once
#include <iostream>

class Shape 
{
public:
    virtual void print(std::ostream &stream) const {};
    virtual double area() const = 0;
};

inline void print(const Shape &shape)
{
    shape.print(std::cout);
}