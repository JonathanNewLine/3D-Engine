#include "BetterRect.h"

unsigned int BetterRect::nextId = 0;

BetterRect::BetterRect(int x, int y, int w, int h, SDL_Color color) : _color(color)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;

    _xPosition = x;
    _yPosition = y;

    _id = generateId();
}

unsigned int BetterRect::generateId()
{
    unsigned int id = nextId;
    nextId++;
    return id;
}


float& BetterRect::getXPosition()
{
    return _xPosition;
}

float& BetterRect::getYPosition()
{
    return _yPosition;
}

float BetterRect::getWidth()
{
    return w;
}

float BetterRect::getHeight()
{
    return h;
}

SDL_Color BetterRect::getColor()
{
    return _color;
}

void BetterRect::setColor(SDL_Color color)
{
    _color = color;
}

unsigned int BetterRect::getId()
{
    return _id;
}

float BetterRect::getTop()
{
    return _yPosition;
}

float BetterRect::getBottom()
{
    return _yPosition + (float)h;
}

float BetterRect::getLeft()
{
    return _xPosition;
}

float BetterRect::getRight()
{
    return _xPosition + (float)w;
}

void BetterRect::setTop(float top)
{
    _yPosition = top;
}
void BetterRect::setBottom(float bottom)
{
    _yPosition = bottom - (float)h;
}

void BetterRect::setLeft(float left)
{
    _xPosition = left;
}

void BetterRect::setRight(float right)
{
    _xPosition = right - (float)w;
}

void BetterRect::setHeight(int height)
{
    h = height;
}

void BetterRect::setWidth(int width)
{
    w = width;
}