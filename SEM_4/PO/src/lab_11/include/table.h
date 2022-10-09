#pragma once

#include "school.h"
#include "student.h"
#include "vector"
#include "algorithm"
#include "numeric"

class Table
{
private:
    std::vector<Student> _candidates;
    std::vector<School *> _schools;

public:
    Table(std::vector<Student> candidates) : _schools(std::vector<School *>{}), _candidates(candidates){};
    Table(School *school) : Table(std::vector<Student>{}) { _schools.push_back(school); };

    void operator+=(const Student &candidate) { _candidates.push_back(candidate); }
    void operator+=(School *school) { _schools.push_back(school); }

    void sortPoints()
    {
        std::sort(std::begin(_candidates), std::end(_candidates), [](const Student &st1, const Student &st2)
                  { return st1.getGrade() > st2.getGrade(); });
    }

    void printStud() const
    {
        std::for_each(std::begin(_candidates), std::end(_candidates), [](const Student &student)
                      { student.print(); });

        std::cout << std::endl;
    }

    double getAverageStudScore() const
    {
        double sum = 0;

        std::for_each(std::begin(_candidates), std::end(_candidates), [&](const Student &student)
                      { sum += student.getGrade(); });

        return (double)sum / _candidates.size();
    }

    void recruit()
    {
        sortPoints();

        for (auto &candidate : _candidates)
        {
            for (auto school : candidate.getSchools())
            {
                if (school->getMax() > school->countStudents())
                {
                    candidate.removeSchools();
                    candidate.assignSchool(school);
                    school->addStudent(candidate);
                    break;
                }
            }

            candidate.removeSchools();
        }
    }

    void printRecruit() const
    {
        for (auto school : _schools)
        {
            school->print();
        }
    }
};
