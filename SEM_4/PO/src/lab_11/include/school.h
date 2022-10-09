#pragma once

#include "string"
#include "iostream"
#include "algorithm"
#include "vector"

class Student;

class School
{
private:
    std::string _name;
    unsigned int _capacity;
    std::vector<Student> _students;

public:
    School(std::string name, unsigned int capacity) : _name(name), _capacity(capacity), _students(std::vector<Student>{}){};

    std::string getClass() const { return _name; };

    unsigned int getMax() const { return _capacity; };

    void addStudent(const Student &st) { _students.push_back(st); };

    unsigned int countStudents() const { return _students.size(); };

    std::string getName() const { return _name; };

    void print() const;
};
