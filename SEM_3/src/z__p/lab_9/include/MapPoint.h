#pragma once

class MapPoint
{
private:
    double longtitude;
    double latitude;
    char *name;

public:
    MapPoint();
    MapPoint(const char *name, double longitude, double latitude);
    MapPoint(const char *name, double longtitude, char longtitudeDirection, double latitude, char latitudeDirection);

    friend MapPoint inTheMiddle(MapPoint *p1, MapPoint *p2, const char *name);

    char *getName() const;
    double getLongtitude() const;
    double getLatitude() const;
    void print() const;
    void movePoint(double longitudeShift, double latitudeShift);
    MapPoint &closestFrom(MapPoint *p1, MapPoint *p2) const;

    ~MapPoint();
};

MapPoint inTheMiddle(MapPoint *p1, MapPoint *p2, const char *name);