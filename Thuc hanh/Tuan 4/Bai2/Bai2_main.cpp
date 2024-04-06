#include "Bai2.h"

int main()
{
    Point p1, p2, p3;
    p1.longitude = 10;
    p1.latitude = 20;

    p2.longitude = 15;
    p2.latitude = 25;

    p3.longitude = 20;
    p3.latitude = 35;

    cout << "Khoang cach giua p1 va p2: " << distance(p1, p2) << endl;

    if (areCollinear(p1, p2, p3))
        cout << "Ba diem p1, p2, p3 nam tren mot duong thang." << endl;
    else
        cout << "Ba diem p1, p2, p3 khong nam tren mot duong thang." << endl;

    Point mid = midpoint(p1, p2);
    cout << "Trung diem cua p1 va p2 co toa do (" << mid.longitude << ", " << mid.latitude << ")." << endl;

    return 0;
}