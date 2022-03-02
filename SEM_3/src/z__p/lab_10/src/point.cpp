#include "point.h"
#include <iostream>
#include <cstring>
#include <utility>

Point::Point() : Point(nullptr, 0, 0) {}

Point::Point(double x, double y) : Point("Miejsce nieznane", x, y) {}

Point::Point(const char *name, double x, double y) : x(x), y(y)
{
    this->name = nullptr;

    if (name != nullptr)
    {
        int len = strlen(name);
        this->name = new char[len + 1]();
        strcpy(this->name, name);
    }
}

Point::Point(const Point &point) : Point(point.name, point.x, point.y) {}

Point::Point(Point &&point)
    : x(std::exchange(point.x, 0)), y(std::exchange(point.y, 0))
{
    this->name = point.name;
    point.name = nullptr;
}

void Point::fullPrint() const
{
    if (this->name == nullptr)
        std::cout << "NULL ";
    else
        std::cout << this->name << " ";

    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

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

void Point::changeName(const char *newName)
{
    delete[] this->name;
    int len = strlen(newName);
    this->name = new char[len + 1]();
    strcpy(this->name, newName);
}

void Point::move(double x, double y)
{
    this->x += x;
    this->y += y;
}

Point::~Point()
{
    if (this->name != nullptr)
    {
        delete[] this->name;
    }
}

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

int compareXY(const Point &p1, const Point &p2)
{
    return 10 * compareX(p1, p2) + compareY(p1, p2);
}

void directions(const Point &p1, const Point &p2, int compFun(const Point &, const Point &))
{
    if (compFun == compareX)
    {
        int result = compFun(p1, p2);
        switch (result)
        {
        case 0:
            std::cout << p1.getName() << " jest na tej samej długości co " << p2.getName() << std::endl;
            break;
        case -1:
            std::cout << p1.getName() << " jest na wschód od " << p2.getName() << std::endl;
            break;
        case 1:
            std::cout << p1.getName() << " jest na zachód od " << p2.getName() << std::endl;
            break;
        }
    }

    if (compFun == compareXY)
    {
        int result = compFun(p1, p2);
        switch (result)
        {
        case 9:
            std::cout << p1.getName() << " jest na północny-zachód od " << p2.getName() << std::endl;
            break;
        case -9:
            std::cout << p1.getName() << " jest na południowy-wschód od " << p2.getName() << std::endl;
            break;
        case -11:
            std::cout << p1.getName() << " jest na północny-wschód od " << p2.getName() << std::endl;
            break;
        case 11:
            std::cout << p1.getName() << " jest na południowy-zachód od " << p2.getName() << std::endl;
            break;
        case 1:
            std::cout << p1.getName() << " jest na południe od " << p2.getName() << std::endl;
            break;
        case 10:
            std::cout << p1.getName() << " jest na zachód od " << p2.getName() << std::endl;
            break;
        }
    }

    if (compFun == compareY)
    {
        int result = compFun(p1, p2);
        switch (result)
        {
        case 0:
            std::cout << p1.getName() << " jest na tej samej szerokości co " << p2.getName() << std::endl;
            break;
        case -1:
            std::cout << p1.getName() << " jest na północ od " << p2.getName() << std::endl;
            break;
        case 1:
            std::cout << p1.getName() << " jest na południe od " << p2.getName() << std::endl;
            break;
        }
    }
}
