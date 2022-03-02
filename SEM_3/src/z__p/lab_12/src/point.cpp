#include "point.h"
#include <string>

Point::Point(std::string name, double x, double y) : x(x), y(y), name(name), next(nullptr) {}

Point::Point(const Point &p) : Point(p.name, p.x, p.y)
{
    next = p.next;
}

Point *Point::getNext() const
{
    return next;
}

void Point::setNext(Point *p)
{
    next = p;
}

std::string Point::getName() const
{
    return name;
}

// region Operators

bool Point::operator==(const Point &p) const
{
    return p.x == x && p.y == y;
}

bool Point::operator!=(const Point &p) const
{
    return !(operator==(p));
}

bool Point::operator<(const Point &p) const
{
    if (p.x == x)
        return p.y > y;

    return p.x > x;
}

bool Point::operator>(const Point &p) const
{
    return !(operator<(p));
}

std::ostream &operator<<(std::ostream &os, const Point &dt)
{
    os << dt.name << "(" << dt.x << " ," << dt.y << ")";
    return os;
}

// endregion