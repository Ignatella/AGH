#pragma once

#include <exception>
#include <iostream>
#include <string>

class X
{
protected:
    std::string _s;

public:
    X(std::string str) : _s(str) { std::cout << "Tworze X " << str << std::endl; }
    X() : X(""){}

    friend std::ostream &operator<<(std::ostream &os, const X &x)
    {
        std::cout << x._s;
        return os;
    }

    virtual ~X() { std::cout << "Usuwam X " << _s << std::endl; }
};

class Y : public X
{
public:
    Y(std::string str) : X(str) { std::cout << "Tworze Y " << str << std::endl; }
    virtual ~Y() { std::cout << "Usuwam Y " << _s << std::endl; }
};

template <size_t size, class T>
class Array
{
private:
    T *_data = new T[size]();

public:
    Array() { std::cout << "---Tworze wersje T" << std::endl; }

    T &operator[](size_t i) const
    {
        if (i >= size)
            throw std::invalid_argument("Indeks poza zakresem");
        return _data[i];
    }

    friend std::ostream &operator<<(std::ostream &os, const Array &arr)
    {
        for (size_t i = 0; i < size; i++)
        {
            std::cout << arr._data[i] << " ";
        }

        return os;
    }

    ~Array()
    {
        delete[] _data;
    }
};

template <size_t size, class T>
class Array<size, T *>
{
private:
    T **_data = new T *[size]();

public:
    Array() { std::cout << "---Tworze wersje T*" << std::endl; }

    T *&operator[](size_t i) const
    {
        if (i >= size)
            throw std::invalid_argument("Indeks poza zakresem");
        return _data[i];
    }

    friend std::ostream &operator<<(std::ostream &os, const Array &arr)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (arr._data[i] != nullptr)
            {
                std::cout << *arr._data[i] << " ";
            }
        }

        return os;
    }

    ~Array()
    {

        for (size_t i = 0; i < size; i++)
        {
            if (_data[i] != nullptr)
            {
                delete _data[i];
            }
        }

        delete[] _data;
        std::cout << "---Usuwam wersje T*" << std::endl;
    }
};