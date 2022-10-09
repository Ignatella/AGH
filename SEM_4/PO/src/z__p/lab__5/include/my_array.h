#pragma once

#include <iostream>
#include <utility>
#include <string>

class MyArray
{
private:
#pragma region Fields

    int *v_;
    unsigned int size_;
    MyArray *next_;

#pragma endregion

public:
#pragma region Constructors

    MyArray(int size);
    MyArray(const MyArray &arr);
    MyArray(MyArray &&arr);

#pragma endregion

#pragma region Methods

    unsigned int size() const;
    MyArray &getNext();
    void print(std::string prefix);

#pragma endregion

#pragma region Operators
    MyArray &operator=(const MyArray &arr);
    void operator+=(MyArray &&arr);
    void operator+=(MyArray &arr);
    MyArray &operator++(int);
    MyArray &operator--();
    int &operator[](unsigned int i) const;
    friend std::ostream &operator<<(std::ostream &os, const MyArray &arr);
#pragma endregion

#pragma region Destructors

    ~MyArray();

#pragma endregion
};
