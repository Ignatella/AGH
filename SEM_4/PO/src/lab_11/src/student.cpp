#include "school.h"
#include "student.h"

#include "iostream"
#include "algorithm"
#include "vector"

void Student::print() const
{
    std::cout << _name << ": " << _grade << " [ ";

    std::for_each(std::begin(_desiredSchools), std::end(_desiredSchools), [](School *school)
                  { std::cout << school->getName() << " "; });

    std::cout << "] --> " << (_assignedSchool == nullptr ? "nieprzyjety" : _assignedSchool->getName()) << std::endl;
}