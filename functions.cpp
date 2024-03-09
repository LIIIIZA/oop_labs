#include "functions.h"

bool doubleEqual(double a, double b)
{
    double eps = 1e-3;
    return (fabs(a - b) < eps);
}

double dist(point a, point b)
{
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}