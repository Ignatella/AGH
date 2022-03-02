#include "MapDist.h"
#include "MapPoint.h"
#include <cmath>

MapPoint &closestFrom(MapPoint *referencePoint, MapPoint *firstPoint, MapPoint *secondPoint)
{
    auto calculateSquareOfDistance = [](MapPoint *p1, MapPoint *p2)
    {
        double dy = pow(p1->longitude - p2->longitude, 2);

        double deltaX = fabs(p1->latitude - p2->latitude);
        double dx1 = pow(deltaX, 2);
        double dx2 = pow(360 - deltaX, 2);

        double dx = dx1 < dx2 ? dx1 : dx2;

        return dx + dy;
    };

    if (calculateSquareOfDistance(referencePoint, firstPoint) < calculateSquareOfDistance(referencePoint, secondPoint))
        return *firstPoint;

    return *secondPoint;
}

MapPoint inTheMiddle(const MapPoint *firstPoint, const MapPoint *secondPoint, const char *pointName)
{
    double dy = (firstPoint->longitude + secondPoint->longitude) / 2;
    double dx = (firstPoint->latitude + secondPoint->latitude) / 2;
    MapPoint resultPoint = {.name = pointName, .longitude = dy, .latitude = dx};
    return resultPoint;
}
