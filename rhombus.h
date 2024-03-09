#pragma once

#include "figure.h"

class Rhombus: public Figure{
public:
    Rhombus();
    Rhombus(point x, point y,  double multiply);
    Rhombus(const std::initializer_list<point> &dots);
    Rhombus& operator=(Rhombus&& other);
    Rhombus& operator=(const Rhombus& other);
    
protected:
    virtual double calcArea() const override;
    virtual bool equals(const Figure& other) const override;
    void constructFig(point &dot, double multiply);
    virtual void check() const override;
};