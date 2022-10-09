#pragma once

#include <string>

class Node
{
protected:
    std::string _name;
    Node(std::string name) : _name(name){};

public:
    virtual void print(int indents) const
    {
        for (size_t i = 0; i < indents; i++)
            std::cout << "  ";
    };

    std::string getName() const { return _name; };

    virtual ~Node(){};
};
