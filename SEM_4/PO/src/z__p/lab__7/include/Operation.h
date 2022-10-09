#pragma once

#include <iostream>
#include <string>

class Operation
{
public:
    virtual void print() const = 0;

    virtual double eval() const = 0;

    friend void operator>>=(std::string pp, const Operation &o)
    {
        std::cout << pp << " ";
        o.print();
        std::cout << " " << pp;

        std::cout << std::endl;
    }
};
