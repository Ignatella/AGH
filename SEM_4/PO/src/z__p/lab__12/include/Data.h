#pragma once

#include "Sum.h"

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

class Data
{
private:
    std::string _dayOfWeek;
    std::vector<double> _v;

public:
    Data(std::string dayOfWeek, std::initializer_list<double> v) : _dayOfWeek(dayOfWeek), _v(v){};
    void print() const
    {
        std::cout << _dayOfWeek << ": ";

        std::for_each(_v.begin(), _v.end(), [](double val)
                      { std::cout << std::setw(6) << val; });

        std::cout << std::endl;
    };

    unsigned int len() const { return _v.size(); };

    double operator[](unsigned int i) const { return _v[i]; };

    friend Sum sumData(const Data &d)
    {
        Sum res;

        std::for_each(d._v.begin(), d._v.end(), [&](double val)
                      { res(val); });

        return res;
    };
};
