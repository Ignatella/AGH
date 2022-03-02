#pragma once
#include <cstddef>
#include <iostream>

class Container
{
private:
    int _value;

public:
    static int mem_size;
    static Container *mem_ptr;

private:
public:
    Container() : Container(0){};

    Container(int value) : _value(value)
    {
        std::cout << "Container(int) " << value << std::endl;
    };

    int &value() { return _value; };

    void *operator new(size_t value) throw();
    void *operator new[](size_t size);

    ~Container();    
};
