#pragma once

#include "Node.h"
#include "File.h"

#include <string>
#include <vector>
#include <iostream>
#include <type_traits>

class Dir final : public Node
{
private:
    std::vector<Node *> _v;

public:
    Dir(std::string name) : Node(name), _v(std::vector<Node *>()){};
    Dir(const Dir &) = delete;

    virtual void print(int indents = 0) const
    {
        Node::print(indents);

        std::cout << _name << " (dir)" << std::endl;

        for (size_t i = 0; i < _v.size(); i++)
        {
            _v[i]->print(indents + 1);
        }
    };

    void copy(const Node *n)
    {
        if (const File *f = dynamic_cast<const File *>(n))
        {
            _v.push_back(f->copy());
        }

        if (const Dir *d = dynamic_cast<const Dir *>(n))
        {
            Dir *copied = new Dir(d->_name);
            _v.push_back(copied);

            for (size_t i = 0; i < d->_v.size(); i++)
            {
                copied->copy(d->_v[i]);
            }
        }
    }

    Dir *getDir(std::string name) const
    {
        if (_name == name)
            return const_cast<Dir *>(this);

        for (size_t i = 0; i < _v.size(); i++)
        {
            Dir *d = dynamic_cast<Dir *>(_v[i]);

            if (d == nullptr)
                continue;

            Dir *res = d->getDir(name);

            if (res != nullptr)
                return res;
        }

        return nullptr;
    }

    File *get(std::string name) const
    {
        for (size_t i = 0; i < _v.size(); i++)
        {
            Dir *d = dynamic_cast<Dir *>(_v[i]);
            File *f = dynamic_cast<File *>(_v[i]);

            if (f != nullptr && _v[i]->getName() == name)
                return f;

            if (d == nullptr)
                continue;

            File *res = d->get(name);

            if (res != nullptr)
                return res;
        }

        return nullptr;
    }

    Dir &operator=(const Dir &) = delete;
    void operator+=(Node *n) { _v.push_back(n); };

    void operator-=(std::string name)
    {
        for (size_t i = 0; i < _v.size(); i++)
        {
            if (_v[i]->getName() == name)
            {
                Node *del = _v[i];
                _v.erase(std::next(_v.begin(), i));
                i--;

                delete del;
            }
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Dir &d)
    {
        d.print();
        return os;
    };

    virtual ~Dir()
    {
        std::cout << "Destruktor Dir: " << _name << std::endl;

        for (size_t i = 0; i < _v.size(); i++)
        {
            delete (_v[i]);
        }
    }
};
