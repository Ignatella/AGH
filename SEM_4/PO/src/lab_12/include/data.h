#pragma once

#include <memory>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include "person.h"
#include "common.h"

/**
 * @brief Person container
 *
 */
class Data
{
private:
    /**
     * @brief Basis structure
     *
     */
    std::vector<std::unique_ptr<Person>> _persons = std::vector<std::unique_ptr<Person>>();

public:
    /**
     * @brief Add person to collection
     *
     * @param person
     */
    void operator+=(std::unique_ptr<Person> person)
    {
        _persons.push_back(std::move(person));
    }

    /**
     * @brief Print all data
     *
     */
    void fullprint() const
    {
        std::for_each(std::begin(_persons), std::end(_persons), [](const std::unique_ptr<Person> &person)
                      { 
                          std::cout << person->getName() 
                                    << " srednia:" << std::setw(4) << averageScore(*person.get()) 
                                    << " suma: " << std::setw(4) << person->getSum() 
                                    << " oceny:"; 
                          for (size_t i = 0; i < person->gradeCount(); i++)
                          {
                              std::cout << std::setw(5) << person->getIGrade(i);
                          }
                          std::cout << std::endl; });

        std::cout << std::endl;
    }

    /**
     * @brief Print data in short form
     *
     */
    void print() const
    {
        std::for_each(std::begin(_persons), std::end(_persons), [](const std::unique_ptr<Person> &person)
                      { person->print(); });

        std::cout << std::endl;
    }

    /**
     * @brief Get person stored under i index
     *
     * @param i
     * @return Person&
     */
    Person &operator[](unsigned int i)
    {
        return *_persons[i].get();
    }

    /**
     * @brief Sort persons by i grade
     *
     * @param i
     * @return Data&
     */
    Data &sort(unsigned int i)
    {
        bool correctIndex = true;

        std::for_each(std::begin(_persons), std::end(_persons), [&](const std::unique_ptr<Person> &person)
                      { correctIndex = correctIndex && (person->gradeCount() > i + 1); });

        if (!correctIndex)
        {
            std::cout << "Indeks " << i << " poza zakresem!" << std::endl;
            return *this;
        }

        std::sort(std::begin(_persons), std::end(_persons), [i](const std::unique_ptr<Person> &p1, const std::unique_ptr<Person> &p2)
                  { return p1->getIGrade(i) > p2->getIGrade(i); });

        return *this;
    }

    /**
     * @brief Sort persons using function provided by user
     *
     * @param f
     * @return Data&
     */
    Data &sortBy(std::function<bool(const std::unique_ptr<Person> &p1, const std::unique_ptr<Person> &p2)> f)
    {
        std::sort(std::begin(_persons), std::end(_persons), f);
        return *this;
    }
};
