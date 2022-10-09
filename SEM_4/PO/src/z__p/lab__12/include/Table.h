#pragma once

#include "Data.h"

#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>

class Table
{
private:
    std::vector<Data> _v;

public:
    Table() : _v(std::vector<Data>()){};

    void print() const
    {
        std::for_each(_v.begin(), _v.end(), [](Data d)
                      { d.print(); });
    };

    Table &sort(unsigned int i)
    {
        bool ok = true;

        std::for_each(_v.begin(), _v.end(), [i, &ok](Data d)
                      { if (i >= d.len()) ok = false; });

        if (!ok)
        {
            std::cout << "Indeks " << i << " nieprawidlowy!" << std::endl;
            return *this;
        }

        std::sort(_v.begin(), _v.end(), [i](const Data &a, const Data &b)
                  { return a[i] < b[i]; });

        return *this;
    };

    Table &sortBy(std::function<bool(const Data &d1, const Data &d2)> f)
    {
        std::sort(_v.begin(), _v.end(), [f](const Data &a, const Data &b)
                  { return f(a, b); });

        return *this;
    };

    void operator+=(const Data &d) { _v.push_back(d); };
};
