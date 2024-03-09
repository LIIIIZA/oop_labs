#pragma once

#include <iostream>
#include <cmath>

class point
{
public:
    double x = 0;
    double y = 0;
    double len() const;

    friend std::ostream& operator<<(std::ostream& out, const point& _this);

    void operator=(const point& other);
    bool operator==(const point& other) const;
    bool operator!=(const point& other) const;
    point operator+(const point& other) const;
    point operator-(const point& other) const;
    point operator+= (const point &other);
    point operator-= (const point &other);
private:
    bool dbEqual(double a, double b) const;
    friend bool doubleEqual(double a, double b);
    friend double dist(point a, point b);
};