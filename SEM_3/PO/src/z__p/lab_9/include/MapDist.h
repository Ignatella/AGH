#pragma once
#include "MapPoint.h"

class MapDist
{
private:
    double longtitudeDistance;
    double latitudeDistance;

public:
    MapDist(const MapPoint &p1, const MapPoint &p2);
    double getlongitude() const;
    double getlatitude() const;
    double angularDistance() const;

    friend bool operator<(const MapDist &ld, const MapDist &lr);
    friend bool operator>(const MapDist &ld, const MapDist &lr);
};

MapDist distance(const MapPoint &p1, const MapPoint &p2);