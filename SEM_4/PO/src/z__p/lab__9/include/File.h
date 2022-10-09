#pragma once

#include "Node.h"

#include <string>

class File : public Node
{
private:
    unsigned int _size;

public:
    File(std::string name, unsigned int size = 0) : Node(name), _size(size){};

    File *copy() const
    {
        return new File(_name, _size);
    }

    virtual void print(int indents = 0) const
    {
        Node::print(indents);

        std::cout << _name << " (" << _size << ")" << std::endl;
    };

    friend std::ostream &operator<<(std::ostream &os, const File &d)
    {
       d.print();
    };

    virtual ~File()
    {
        std::cout << "---Destruktor File: " << _name << std::endl;;
    };
};
