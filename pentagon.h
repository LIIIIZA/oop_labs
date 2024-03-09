#pragma once

#include "figure.h"

class Pentagon: virtual public Figure{
public:
    Pentagon();
    Pentagon(point& cen, point& dot);
    Pentagon(const std::initializer_list<point> &dots);
    Pentagon& operator=(const Pentagon& other);
    Pentagon& operator=(Pentagon&& other);
    
protected:
    virtual void check() const override;
    virtual bool equals(const Figure& other) const override;
};
