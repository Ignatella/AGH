#pragma once

#include "rna.h"

#include <string>
#include <vector>
#include <utility>

class Virus
{
private:
    std::string _name;
    unsigned int _age;
    RNA *_rna;

public:
    Virus(std::string name, RNA *rna = new RNA(std::vector<Nukleotyp>())) : _name(name), _rna(rna), _age(0){};
    Virus(Virus &v) : _name(v._name), _rna(new RNA(*v._rna)), _age(0) { v._age++; };
    Virus(Virus &&v) : _name(std::move(v._name)),
                       _rna(std::exchange(v._rna, new RNA(std::vector<Nukleotyp>()))),
                       _age(0)
    {
        _rna->mutate();
        v._age++;
    };

    std::string get_name() const { return _name; };
    unsigned int get_age() const { return _age; };
    RNA *get_RNA() const { return _rna; };
    void set_RNA(std::vector<Nukleotyp> v)
    {
        delete _rna;
        _rna = new RNA(v);
    };

    Virus &operator=(const Virus &another)
    {
        delete _rna;
        _name = another._name;
        _age = another._age;
        _rna = new RNA(*another._rna);
        return *this;
    }

    ~Virus()
    {
        delete _rna;
    }
};
