#pragma once

#include "MapPoint.h"

MapPoint &closestFrom(MapPoint *referencePoint, MapPoint *firstPoint, MapPoint *secondPoint);

MapPoint inTheMiddle(const MapPoint *firstPoint, const MapPoint *secondPoint, const char *pointName);