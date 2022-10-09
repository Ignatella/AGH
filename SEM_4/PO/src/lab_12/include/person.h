#pragma once

#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <functional>

/**
 * @brief Person
 *
 */
class Person
{
private:
    /**
     * @brief Person name
     *
     */
    std::string _name;

    /**
     * @brief Person grades
     *
     */
    std::vector<double> _grades;

public:
    /**
     * @brief Construct a new Person
     *
     * @param name
     * @param grades
     */
    Person(std::string name, std::vector<double> grades) : _name(name), _grades(grades){};

    /**
     * @brief Get the name of person
     *
     * @return std::string
     */
    std::string getName() const { return _name; }

    /**
     * @brief Count person grades
     *
     * @return unsigned int
     */
    unsigned int gradeCount() const
    {
        return _grades.size();
    }

    /**
     * @brief Add grade to person grades collection
     *
     * @param grade
     */
    void addScore(double grade)
    {
        _grades.push_back(grade);
    }

    /**
     * @brief Remove grade from person grades collection
     *
     * @param grade
     */
    void removeScore(double grade)
    {
        auto iterator = std::find(std::begin(_grades), std::end(_grades), grade);
        if (iterator != std::end(_grades))
        {
            unsigned int i = std::distance(std::begin(_grades), iterator);
            _grades.erase(std::next(std::begin(_grades), i), std::next(std::begin(_grades), i + 1));
        }
    }

    /**
     * @brief Print persons data
     *
     */
    void print() const
    {
        std::cout << _name << ":";

        std::for_each(std::begin(_grades), std::end(_grades), [](double grade)
                      { std::cout << std::setw(5) << grade; });

        std::cout << std::endl;
    }

    /**
     * @brief Get sum of all grades
     *
     * @return double
     */
    double getSum() const
    {
        return std::accumulate(std::begin(_grades), std::end(_grades), 0.);
    }

    /**
     * @brief Get grad that is stored under i index
     *
     * @param i
     * @return double
     */
    double getIGrade(unsigned int i) const { return _grades[i]; }

    /**
     * @brief Get not int grades
     *
     * @return std::vector<double>::const_iterator
     */
    std::vector<double>::const_iterator notIntScores() const
    {
        return std::find_if(std::begin(_grades), std::end(_grades), [](double grade)
                            { return grade != (int)grade; });
    }

    /**
     * @brief Count grades that are > 3.0
     *
     * @return size_t
     */
    size_t countGoodScores() const
    {
        return std::count_if(std::begin(_grades), std::end(_grades), [](double grade)
                             { return grade >= 3.0; });
    }

    /**
     * @brief Calculate average grade
     *
     * @param person
     * @return double
     */
    friend double averageScore(const Person &person)
    {
        return person.getSum() / person._grades.size();
    }
};
