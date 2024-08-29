#include "Rect.h"

Rect::Rect(float x, float y, float width, float height, Color color) : Drawable(color)
{
    _x = x;
    _y = y;
    _width = width;
    _height = height;
}

float& Rect::getX()
{
    return _x;
}

float& Rect::getY()
{
    return _y;
}

float Rect::getWidth()
{
    return _width;
}

float Rect::getHeight()
{
    return _height;
}

float Rect::getTop()
{
    return _y;
}

float Rect::getBottom()
{
    return _y + _height;
}

float Rect::getLeft()
{
    return _x;
}

float Rect::getRight()
{
    return _x + _width;
}

void Rect::setTop(float top)
{
    _y = top;
}
void Rect::setBottom(float bottom)
{
    _y = bottom - _height;
}

void Rect::setLeft(float left)
{
    _x = left;
}

void Rect::setRight(float right)
{
    _x = right - _width;
}

void Rect::setHeight(int height)
{
    _height = height;
}

void Rect::setWidth(int width)
{
    _width = width;
}

SDL_Rect* Rect::getSDL_Rect()
{
    SDL_Rect sdl_rect;
    sdl_rect.x = _x;
    sdl_rect.y = _y;
    sdl_rect.w = _width;
    sdl_rect.h = _height;
    return &sdl_rect;
}