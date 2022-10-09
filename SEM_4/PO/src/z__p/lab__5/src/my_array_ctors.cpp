#include "my_array.h"

MyArray::MyArray(int size) : size_(size), next_(nullptr)
{
    v_ = new int[size]();
};

MyArray::MyArray(const MyArray &arr) : MyArray(arr.size_)
{
    if (arr.v_ == v_)
        return;

    delete[] v_;

    v_ = new int[arr.size_]();
    next_ = arr.next_;

    for (size_t i = 0; i < size_; i++)
        v_[i] = arr.v_[i];
};

MyArray::MyArray(MyArray &&arr)
    : size_(std::exchange(arr.size_, 0)),
      v_(std::exchange(arr.v_, new int[0]())),
      next_(std::exchange(arr.next_, nullptr)){};

MyArray::~MyArray()
{
    delete[] v_;
};
