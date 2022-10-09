#include "MapPoint.h"
#include "MapDist.h"
#include <iostream>
#include <cstring>
#include <cmath>

MapPoint::MapPoint(const char *name, double longtitude, double latitude)
    : longtitude(longtitude), latitude(latitude)
{
    int len = strlen(name);
    this->name = new char[len + 1]();
    strcpy(this->name, name);
}

MapPoint::MapPoint() : MapPoint("Punkt", 0, 0) {}

MapPoint::MapPoint(const char *name, double longtitude, char longtitudeDirection, double latitude, char latitudeDirection)
    : MapPoint(name, longtitude, latitude)
{
    if (longtitudeDirection == 'W')
        this->longtitude *= -1;

    if (latitudeDirection == 'S')
        this->latitude *= -1;
}

double MapPoint::getLongtitude() const
{
    return this->longtitude;
}

double MapPoint::getLatitude() const
{
    return this->latitude;
}

char *MapPoint::getName() const
{
    return this->name;
}

void MapPoint::print() const
{
    char longtitudeDirection = this->longtitude > 0 ? 'E' : 'W';
    char latitudeDirection = this->latitude > 0 ? 'N' : 'S';

    std::cout << "Wspolrzedne dla " << this->name << ": "
              << fabs(this->longtitude) << longtitudeDirection << ", "
              << fabs(this->latitude) << latitudeDirection << std::endl;
}

void MapPoint::movePoint(double longitudeShift, double latitudeShift)
{
    this->longtitude += longitudeShift;
    this->latitude += latitudeShift;
}

MapPoint &MapPoint::closestFrom(MapPoint *p1, MapPoint *p2) const
{
    MapDist dist1 = distance(*this, *p1);
    MapDist dist2 = distance(*this, *p2);

    return dist1 < dist2 ? *p1 : *p2;
}

MapPoint::~MapPoint()
{
    if (this->name != NULL)
    {
        std::cout << "Usuwanie " << this->name << std::endl;
        delete[] this->name;
    }
}

MapPoint inTheMiddle(MapPoint *p1, MapPoint *p2, const char *name)
{
    return MapPoint(name, (p1->longtitude + p2->longtitude) / 2, (p1->latitude + p2->latitude) / 2);
}