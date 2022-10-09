#include "Student.h"
#include "Grade.h"
#include <iostream>

Student::Student(int id) : id(id) {}

void Student::print() const
{
    Grade **studentGrades = Grade::getGrades();

    std::cout << "Student ID=" << this->id << " oceny: ";

    for (int i = 0; i < Grade::getCount(); i++)
    {
        if ((*(studentGrades + i))->getStudent().getId() == this->id)
        {
            std::cout << (*(studentGrades + i))->getGrade() << " ";
        }
    }

    std::cout << std::endl;
}

int Student::getId() const
{
    return id;
}
