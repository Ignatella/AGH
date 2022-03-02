#pragma once

#include <string>
#include <iostream>

class Point
{
private:
    std::string name;
    Point *next;

public:
    double x, y;
    Point(std::string name, double x, double y);
    Point(const Point &p);

    Point *getNext() const;
    void setNext(Point *p);

    std::string getName() const;

    bool operator==(const Point &p) const;
    bool operator!=(const Point &p) const;
    bool operator<(const Point &p) const;
    bool operator>(const Point &p) const;

    friend std::ostream &operator<<(std::ostream &os, const Point &p);
};

std::ostream &operator<<(std::ostream &os, const Point &p);