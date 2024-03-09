#pragma once

#include <iostream>
#include "figure.h"

class Hexagon: virtual public Figure{
public:
    Hexagon();
    Hexagon(point& cen, point& dot);
    Hexagon(const std::initializer_list<point> &dots);
    Hexagon& operator=(const Hexagon& other);
    Hexagon& operator=(Hexagon&& other);
    
protected:
    void check() const override;
    bool equals(const Figure& other) const override;
};
