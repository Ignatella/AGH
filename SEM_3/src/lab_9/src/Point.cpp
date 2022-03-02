#include "Point.h"
#include <iostream>
#include <cstring>
#include <utility>

// region Point

int Point::idSeed = 1;
int Point::number = 0;

// region Ctors

Point::Point() : Point(nullptr, 0, 0) {}

Point::Point(const char *name, double x, double y) : x(x), y(y)
{
    this->name = nullptr;

    this->setId();
    Point::number++;

    if (name != nullptr)
    {
        int len = strlen(name);
        this->name = new char[len + 1]();
        strcpy(this->name, name);
    }
}

Point::Point(const Point &point) : Point(point.name, point.x, point.y)
{
    std::cout << "--- Kopiujemy " << point.id << ". " << point.name << std::endl;
}

Point::Point(Point &&point)
    : x(std::exchange(point.x, 0)), y(std::exchange(point.y, 0))
{
    std::cout << "--- Przenosimy " << point.id << ". " << point.name << std::endl;

    this->setId();
    Point::number++;

    this->name = point.name;
    point.name = nullptr;
}

Point Point::setPoint(double x, double y)
{
    return Point("Punkt X", x, y);
}

Point Point::setContrary(double x, double y)
{
    return Point("Punkt X", -x, -y);
}

Point Point::newMoved(const char *name, double x, double y)
{
    return Point(name, this->x + x, this->y + y);
}

// endregion

void Point::setId()
{
    this->id = this->idSeed;
    this->idSeed++;
}

void Point::fullPrint() const
{
    std::cout << this->id << ". ";

    if (this->name != nullptr)
        std::cout << this->name << " ";

    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

// region Getters

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

char *Point::getName() const
{
    return name;
}

// endregion

void Point::changeName(const char *newName)
{
    delete[] this->name;
    int len = strlen(newName);
    this->name = new char[len + 1]();
    strcpy(this->name, newName);
}

Point::~Point()
{
    if (this->name != nullptr)
    {
        delete[] this->name;
    }

    Point::number--;
}

// endregion

// region Compare...

int compareX(const Point &p1, const Point &p2)
{
    if (p1.getX() < p2.getX())
        return 1;

    if (p1.getX() > p2.getX())
        return -1;

    return 0;
}

int compareY(const Point &p1, const Point &p2)
{
    if (p1.getY() < p2.getY())
        return 1;

    if (p1.getY() > p2.getY())
        return -1;

    return 0;
}

void directions(const Point &p1, const Point &p2, int compFun(const Point &, const Point &))
{
    if (compFun == compareX)
    {
        int result = compFun(p1, p2);

        switch (result)
        {
        case 0:
            std::cout << p1.getName() << " - na tej samej długości co " << p2.getName() << std::endl;
            break;
        case 1:
            std::cout << p1.getName() << " - na zach. od " << p2.getName() << std::endl;
            break;
        case -1:
            std::cout << p1.getName() << " - na wsch. od " << p2.getName() << std::endl;
            break;
        }
    }

    if (compFun == compareY)
    {
        int result = compFun(p1, p2);

        switch (result)
        {
        case 0:
            std::cout << p1.getName() << " - na tej samej szerokości co " << p2.getName() << std::endl;
            break;
        case 1:
            std::cout << p1.getName() << " - na pd. od " << p2.getName() << std::endl;
            break;
        case -1:
            std::cout << p1.getName() << " - na pn. od " << p2.getName() << std::endl;
            break;
        }
    }
}

// endregion