#include "Rect.h"

unsigned int Rect::nextId = 0;

Rect::Rect(int x, int y, int w, int h, Color color) : _color(color)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;

    _xPosition = x;
    _yPosition = y;

    _id = generateId();
}

unsigned int Rect::generateId()
{
    unsigned int id = nextId;
    nextId++;
    return id;
}


float& Rect::getXPosition()
{
    return _xPosition;
}

float& Rect::getYPosition()
{
    return _yPosition;
}

float Rect::getWidth()
{
    return w;
}

float Rect::getHeight()
{
    return h;
}

Color Rect::getColor()
{
    return _color;
}

void Rect::setColor(Color color)
{
    _color = color;
}

unsigned int Rect::getId()
{
    return _id;
}

float Rect::getTop()
{
    return _yPosition;
}

float Rect::getBottom()
{
    return _yPosition + (float)h;
}

float Rect::getLeft()
{
    return _xPosition;
}

float Rect::getRight()
{
    return _xPosition + (float)w;
}

void Rect::setTop(float top)
{
    _yPosition = top;
}
void Rect::setBottom(float bottom)
{
    _yPosition = bottom - (float)h;
}

void Rect::setLeft(float left)
{
    _xPosition = left;
}

void Rect::setRight(float right)
{
    _xPosition = right - (float)w;
}

void Rect::setHeight(int height)
{
    h = height;
}

void Rect::setWidth(int width)
{
    w = width;
}