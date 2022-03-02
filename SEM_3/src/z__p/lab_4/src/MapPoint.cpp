#include "MapPoint.h"
#include <iostream>
#include <stdarg.h>
#include <cmath>

MapPoint *construct(const char *pointName, double longitude, double latitude)
{
    MapPoint *p = (MapPoint *)malloc(sizeof(MapPoint));
    p->name = pointName;
    p->latitude = latitude;
    p->longitude = longitude;
    return p;
}

void print(const MapPoint *point)
{
    const char yBit = point->longitude > 0 ? 'E' : 'W';
    const char xBit = point->latitude > 0 ? 'N' : 'S';

    std::cout << "Wspolrzedne dla "
              << point->name << ": "
              << fabs(point->longitude) << yBit << ", "
              << fabs(point->latitude) << xBit
              << std::endl;
}

void movePoint(MapPoint *point, double longitudeShift, double latitudeShift)
{
    point->longitude += longitudeShift;
    point->latitude += latitudeShift;
}

void clearAll(MapPoint *point, ...)
{
    va_list arguments;

    for (va_start(arguments, point); point != NULL; point = va_arg(arguments, MapPoint *))
        free(point);

    va_end(arguments);
}