#include "my_array.h"

void MyArray::operator+=(MyArray &&arr)
{
    int *newArr = new int[size_ + arr.size_]();

    for (size_t i = 0; i < size_; i++)
        newArr[i] = v_[i];

    for (size_t i = 0; i < arr.size_; i++)
        newArr[size_ + i] = arr.v_[i];

    size_ += arr.size_;
    delete[] v_;
    v_ = newArr;
};

void MyArray::operator+=(MyArray &arr)
{
    MyArray *curr = this;

    while (curr->next_ != nullptr)
        curr = curr->next_;

    curr->next_ = &arr;
};

MyArray &MyArray::operator=(const MyArray &arr)
{
    if (arr.v_ == v_)
        return *this;

    delete[] v_;

    size_ = arr.size_;
    v_ = new int[size_]();

    for (size_t i = 0; i < size_; i++)
        v_[i] = arr.v_[i];

    return *this;
};

int &MyArray::operator[](unsigned int i) const
{
    const MyArray *curr = this;
    while (i > curr->size_)
    {
        i -= curr->size_;
        curr = curr->next_;
    }

    return curr->v_[i];
};

MyArray &MyArray::operator++(int)
{
    for (size_t i = 0; i < size_; i++)
        ++v_[i];

    return *this;
};

MyArray &MyArray::operator--()
{
    for (size_t i = 0; i < size_; i++)
        --v_[i];

    return *this;
};

std::ostream &operator<<(std::ostream &os, const MyArray &arr)
{
    os << "[";

    for (size_t i = 0; i < arr.size(); i++)
        os << arr.v_[i] << ", ";

    if (arr.size() > 0)
        os << "\b\b";

    os << "]";

    return os;
};
