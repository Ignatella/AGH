#include "MyArray.h"

void MyArray::print(std::string prefix) const
{
    std::cout << prefix << " = " << *this << std::endl;
};

MyArray &MyArray::operator=(const MyArray &arr)
{
    if (_v == arr._v)
        return *this;

    delete[] _v;

    _v = new int[arr._size]();
    _size = arr._size;

    for (size_t i = 0; i < arr._size; i++)
        _v[i] = arr._v[i];

    return *this;
}

MyArray &MyArray::operator*=(int factor)
{
    for (size_t i = 0; i < _size; i++)
        _v[i] *= factor;
    
    return *this;
}

MyArray MyArray::operator++(int)
{
    MyArray result(*this);

    for (size_t i = 0; i < _size; i++)
        ++_v[i];

    return result;
};

MyArray MyArray::operator*(int factor) const
{
    MyArray result(*this);
    result *= factor;
    return result;
};

std::ostream &operator<<(std::ostream &os, const MyArray &arr)
{
    os << "[";

    for (size_t i = 0; i < arr._size; i++)
        os << arr._v[i] << ", ";

    if (arr._size > 0)
        os << "\b\b";

    os << "]";

    return os;
}