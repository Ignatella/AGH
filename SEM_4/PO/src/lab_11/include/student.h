#pragma once

#include "string"
#include "iostream"
#include "algorithm"
#include "vector"

class School;

class Student
{
private:
    std::string _name;
    unsigned int _grade;
    School *_assignedSchool;
    std::vector<School *> _desiredSchools;

public:
    Student(std::string name, unsigned int grade, std::initializer_list<School *> desiredSchools)
        : _name(name), _grade(grade), _assignedSchool(nullptr), _desiredSchools(desiredSchools){};

    unsigned int getGrade() const { return _grade; };

    std::vector<School *> getSchools() const { return _desiredSchools; };

    void removeSchools() { _desiredSchools.clear(); };

    void assignSchool(School *school) { _assignedSchool = school; };

    void print() const;
};
