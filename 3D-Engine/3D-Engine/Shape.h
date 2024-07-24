#pragma once

#include "Color.h"

class Shape
{
public:
    Shape(Color color);

    Color getColor();
    void setColor(Color color);

protected:
    Color _color;
};

