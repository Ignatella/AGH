#include "school.h"
#include "student.h"

#include "iostream"
#include "algorithm"
#include "vector"

void School::print() const
{
    std::cout << _name << " - " << _capacity;

    if (_students.size() == 0)
    {
        std::cout << " brak przyjetych" << std::endl;
    }
    else
    {
        std::cout << std::endl;
        std::for_each(std::begin(_students), std::end(_students), [](Student student)
                      { student.print(); });
    }

    std::cout << std::endl;
};