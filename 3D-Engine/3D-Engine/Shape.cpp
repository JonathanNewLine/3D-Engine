#include "Shape.h"

Shape::Shape(Color color) : _color(color)
{

}

Color Shape::getColor()
{
    return _color;
}

void Shape::setColor(Color color)
{
    _color = color;
}