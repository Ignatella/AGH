#pragma once

#include "rna.h"
#include "virus.h"

#include <string>
#include <vector>
#include <utility>

class AnimalVirus : public Virus
{
private:
    std::string _animalName;

public:
    AnimalVirus() : Virus(""), _animalName(""){};
    AnimalVirus(std::string name, std::string animalName, RNA *rna) : Virus(name, rna), _animalName(animalName){};
    AnimalVirus(std::string name, std::string animalName, std::vector<Nukleotyp> v) : Virus(name, new RNA(v)), _animalName(animalName){};
    AnimalVirus(AnimalVirus &v) : Virus(v), _animalName(v._animalName){};
    AnimalVirus(AnimalVirus &&v) : Virus(v), _animalName(std::exchange(v._animalName, "")){};

    std::string get_animal_host() const { return _animalName; };

    AnimalVirus &operator=(const AnimalVirus &another)
    {
        Virus::operator=(another);
        get_RNA()->mutate();
        _animalName = another._animalName;
        return *this;
    };
};
