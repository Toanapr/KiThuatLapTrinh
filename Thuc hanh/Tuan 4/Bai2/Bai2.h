#ifndef BAI2_H
#define BAI2_H

#include <iostream>
#include <cmath>

using namespace std;
struct Point
{
    double longitude; // Kinh do
    double latitude;  // Vi do
};

double distance(const Point &p1, const Point &p2);
bool areCollinear(const Point &p1, const Point &p2, const Point &p3);
Point midpoint(const Point &p1, const Point &p2);

#endif