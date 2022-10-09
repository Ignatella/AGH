#pragma once

#include <iostream>
#include <utility>

class MyArray
{
private:
    int *_v = nullptr;
    int _size;

public:
    MyArray(int size) : _size(size)
    {
        _v = new int[size]{};
    };

    MyArray(const MyArray &v) : MyArray(v.size())
    {
        for (size_t i = 0; i < _size; i++)
            _v[i] = v[i];
    };

    MyArray(MyArray &&v) : _size(std::exchange(v._size, 0))
    {
        delete[] _v;
        _v = new int[_size]{};

        for (size_t i = 0; i < _size; i++)
            _v[i] = v[i];

        delete[] v._v;
        v._v = new int[0]{};
    };

    void print(const char *prefix) const
    {
        std::cout << prefix << " = " << *this;
    };

    int size() const
    {
        return _size;
    };

    void operator++()
    {
        for (size_t i = 0; i < _size; i++)
            ++_v[i];
    };

    MyArray &operator=(const MyArray &a)
    {
        if (a._v == _v)
            return *this;

        delete[] _v;

        _size = a.size();
        _v = new int[_size]{};

        for (size_t i = 0; i < _size; i++)
            _v[i] = a[i];

        return *this;
    };

    int &operator[](unsigned int i) const { return _v[i]; };

    friend std::ostream &operator<<(std::ostream &os, const MyArray &dt)
    {
        std::cout << "[";

        for (size_t i = 0; i < dt.size(); i++)
            std::cout << dt[i] << ", ";

        if (dt.size() > 0)
            std::cout << "\b\b";

        std::cout << "]" << std::endl;

        return os;
    };

    ~MyArray()
    {
        delete[] _v;
        _v = nullptr;

        std::cout << "Usuwam tablice" << std::endl;
    };
};
