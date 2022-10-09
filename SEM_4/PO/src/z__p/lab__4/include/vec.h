#pragma once

#include <vector>
#include <iostream>

class vec
{
private:
    Int_t *v_;
    unsigned int size_;

public:
    vec() : size_(0) { v_ = new Int_t[0](); };

    void push_back(const Int_t &i)
    {
        Int_t *n = new Int_t[size_ + 1]();

        for (size_t i = 0; i < size_; i++)
            n[i] = v_[i];
        n[size_++] = i;

        delete[] v_;
        v_ = n;
    };

    Int_t *begin() { return v_; }
    Int_t *end() { return v_ + size_; }

    Int_t &operator[](unsigned int i) { return v_[i]; };

    ~vec() { delete[] v_; }
};
