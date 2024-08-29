#pragma once

#include "Color.h"

class Drawable
{
public:
    Drawable(Color color);

    Color getColor();
    void setColor(Color color);

protected:
    Color _color;
};

