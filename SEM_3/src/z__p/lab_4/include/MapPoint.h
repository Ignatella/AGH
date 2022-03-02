#pragma once

#include <iostream>

#define clear(...) clearAll(__VA_ARGS__, NULL)

struct MapPoint
{
    const char *name;
    double longitude;
    double latitude;
};

MapPoint *construct(const char *pointName, double longitude, double latitude);

void print(const MapPoint *point);

void movePoint(MapPoint *point, double longitudeShift, double latitudeShift);

void clearAll(MapPoint *point...);


