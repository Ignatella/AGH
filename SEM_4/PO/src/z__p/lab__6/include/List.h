#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <functional>

class List
{
private:
    std::vector<int> _v;

public:
    List() : _v(std::vector<int>{}){};

    void insert(int val) { _v.push_back(val); };

    List filter(std::function<bool(int)> f)
    {
        List result{};

        for (int val : _v)
        {
            if (f(val))
            {
                result.insert(val);
            }
        }

        return result;
    }

    void print(std::string prefix = "") const
    {
        std::cout << prefix << "[";

        for (const int &val : _v)
            std::cout << val << ", ";

        std::cout << "\b\b]" << std::endl;
    };

    int &operator[](unsigned int i) { return _v[i]; };
};
