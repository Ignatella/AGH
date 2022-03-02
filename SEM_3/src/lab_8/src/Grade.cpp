#include "Grade.h"
#include <iostream>
#include <cstring>

int Grade::idSeed = 1;
int Grade::gradeCount = 0;
Grade **Grade::grades = {};

int Grade::getCount()
{
    return Grade::gradeCount;
}

void Grade::addGrade(Grade *grade)
{
    Grade **newGrades = new Grade *[Grade::gradeCount + 1]();

    for (int i = 0; i < gradeCount; i++)
    {
        newGrades[i] = Grade::grades[i];
    }

    newGrades[gradeCount] = grade;

    delete[] Grade::grades;
    Grade::grades = newGrades;
    Grade::gradeCount++;
}

Grade::Grade(const char *name, double grade, const Student &student)
    : grade(grade), student(student)
{
    int len = strlen(name);
    this->name = new char[len + 1]();
    strcpy(this->name, name);

    this->id = Grade::idSeed;
    Grade::idSeed++;

    Grade::addGrade(this);
}

void Grade::print() const
{
    std::cout << "ID=" << this->id << " " << this->name << " ocena=" << this->grade
              << " student_ID=" << this->student.getId() << std::endl;
}

Grade **Grade::getGrades()
{
    return grades;
}

double Grade::getGrade() const
{
    return this->grade;
}

char *Grade::getName() const
{
    return this->name;
}

const Student &Grade::getStudent() const
{
    return this->student;
}

Grade::~Grade()
{
    if (name != NULL)
        delete[] name;

    Grade **newGrades = new Grade *[Grade::gradeCount - 1]();

    for (int i = 0; i < gradeCount; i++)
    {
        if (Grade::grades[i] == this)
            continue;
        newGrades[i] = Grade::grades[i];
    }

    delete[] Grade::grades;
    Grade::grades = newGrades;
    gradeCount--;

    if (Grade::gradeCount == 0)
        delete [] Grade::grades;
}