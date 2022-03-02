#include "MapDist.h"
#include <cmath>

MapDist::MapDist(const MapPoint &p1, const MapPoint &p2)
{
    longtitudeDistance = fabs(p1.getLongtitude() - p2.getLongtitude());
    latitudeDistance = fabs(p1.getLatitude() - p2.getLatitude());
}

MapDist distance(const MapPoint &p1, const MapPoint &p2)
{
    MapDist result(p1, p2);
    return result;
}

double MapDist::getlongitude() const
{
    return this->longtitudeDistance;
}

double MapDist::getlatitude() const
{
    return this->latitudeDistance;
}

double MapDist::angularDistance() const
{
    return sqrt(pow(longtitudeDistance, 2) + pow(latitudeDistance, 2));
}

bool operator<(const MapDist &ld, const MapDist &rd)
{
    return ld.angularDistance() < rd.angularDistance();
}

bool operator>(const MapDist &ld, const MapDist &lr)
{
    return !(operator<(ld, lr));
}
