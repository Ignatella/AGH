#pragma once

#include <vector>
#include <iostream>

class vec
{
private:
    std::vector<Int_t> _v;

public:
    void push_back(const Int_t &i) { _v.push_back(i); };

    std::vector<Int_t>::iterator begin() { return _v.begin(); };
    std::vector<Int_t>::iterator end() { return _v.end(); };

    Int_t &operator[](unsigned int i) { return _v[i]; };
};
