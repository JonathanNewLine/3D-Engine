#include "Drawable.h"

Drawable::Drawable(Color color) : _color(color)
{

}

Color Drawable::getColor()
{
    return _color;
}

void Drawable::setColor(Color color)
{
    _color = color;
}