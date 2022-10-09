#pragma once

class Point
{
private:
    double x, y;
    char *name;

public:
    Point();
    Point(double x, double y);
    Point(const char *name, double x, double y);

    Point(const Point &point);
    Point(Point &&point);

    void fullPrint() const;
    void changeName(const char *newName);
    void move(double x, double y);

    double getX() const;
    double getY() const;
    char *getName() const;

    ~Point();
};

int compareX(const Point &p1, const Point &p2);
int compareY(const Point &p1, const Point &p2);
int compareXY(const Point &p1, const Point &p2);

void directions(const Point &p1, const Point &p2, int compFun(const Point &, const Point &));