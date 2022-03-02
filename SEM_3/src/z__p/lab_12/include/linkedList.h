#pragma once

#include "point.h"
#include <string>

class LinkedList
{
private:
    Point *head;
    std::string name;
    int count = 0;

private:
    Point *last() const;

public:
    LinkedList();
    LinkedList(std::string name);
    LinkedList(LinkedList &&p);
    LinkedList(const LinkedList &p);

    bool contains(const Point &p) const;
    void append(const Point &p);
    void addSorted(const Point &p);
    void removeLast();

    friend void print(const LinkedList &l);

    LinkedList operator=(const LinkedList &l);
    LinkedList &operator+=(const Point &p);
    LinkedList &operator+=(const LinkedList &list);
    LinkedList &operator--(int);
    LinkedList operator+(const LinkedList &l) const;

    friend std::ostream &operator<<(std::ostream &os, const LinkedList &l);

    ~LinkedList();
};

std::ostream &operator<<(std::ostream &os, const LinkedList &l);

void print(const LinkedList &l);
