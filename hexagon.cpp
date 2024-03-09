#include "hexagon.h"

Hexagon::Hexagon() : Figure(6)
{
    tag = "HEXAGON";
}

Hexagon::Hexagon(point &x, point &y) : Figure(x, 6)
{
    tag = "HEXAGON";
    constructFig(y, 6);
    check();
}

Hexagon::Hexagon(const std::initializer_list<point> &dots) : Figure(dots, 6)
{
    tag = "HEXAGON";
    check();
};

Hexagon& Hexagon::operator=(const Hexagon& other)
{
    if (this != &other) {
        Figure::operator=(other);
    }
    return *this;
}

Hexagon& Hexagon::operator=(Hexagon&& other)
{
    if (this != &other) {
        Figure::operator=(std::move(other));
    }
    return *this;
}

bool Hexagon::equals(const Figure& other) const {
    double a = distance(this->arr[0], this->arr[1]);
    double b = distance(other.getDots()[0], other.getDots()[1]);
    return dbEqual(a,b);
}

void Hexagon::check() const
{
    if (this->calcArea() == 0) {
        throw std::underflow_error("calcArea fall");
    }
    if (!Figure::trueFigCheck(this->size())) {
        throw std::underflow_error("trueFigCheck fall");
    }
}