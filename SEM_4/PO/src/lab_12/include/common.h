#pragma once

#include <memory>
#include <vector>

#include "person.h"


/**
 * @brief Compare persons grades
 * 
 * @param p1 
 * @param p2 
 * @return true 
 * @return false 
 */
bool greaterAverage(const std::unique_ptr<Person> &p1, const std::unique_ptr<Person> &p2)
{
    return averageScore(*p1.get()) - averageScore(*p2.get()) > 0;
}

/**
 * @brief Check if grade is bad
 * 
 */
struct badScores
{
    bool operator()(double grade) { return grade == 2; }
};
