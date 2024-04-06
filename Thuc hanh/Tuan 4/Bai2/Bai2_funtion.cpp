#include "Bai2.h"

double distance(const Point &p1, const Point &p2)
{
    double deltaLongitude = p2.longitude - p1.longitude;
    double deltaLatitude = p2.latitude - p1.latitude;
    return sqrt(deltaLongitude * deltaLongitude + deltaLatitude * deltaLatitude);
}

bool areCollinear(const Point &p1, const Point &p2, const Point &p3)
{
    return (p1.latitude - p2.latitude) * (p2.longitude - p3.longitude) == (p2.latitude - p3.latitude) * (p1.longitude - p2.longitude);
}

Point midpoint(const Point &p1, const Point &p2)
{
    Point mid;
    mid.longitude = (p1.longitude + p2.longitude) / 2;
    mid.latitude = (p1.latitude + p2.latitude) / 2;
    return mid;
}
