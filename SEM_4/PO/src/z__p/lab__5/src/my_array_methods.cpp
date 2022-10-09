#include "my_array.h"

unsigned int MyArray::size() const
{
    return size_;
};

MyArray &MyArray::getNext()
{
    return *next_;
};

void MyArray::print(std::string prefix)
{
    std::cout << prefix;

    MyArray *curr = this;

    while (curr != nullptr)
    {
        std::cout << *curr << " ";
        curr = curr->next_;
    }
};
