#pragma once
#include "Color.h"
#include "Drawable.h"
#include <SDL_rect.h>


class Rect : public Drawable
{
public:
    Rect(float x, float y, float width, float height, Color color);


    float& getX();
    float& getY();
    float getWidth();
    float getHeight();

    float getTop();
    float getBottom();
    float getLeft();
    float getRight();

    void setTop(float top);
    void setBottom(float bottom);
    void setLeft(float left);
    void setRight(float right);

    void setHeight(int height);
    void setWidth(int width);

    SDL_Rect* getSDL_Rect();

private:
    float _x;
    float _y;
    float _width;
    float _height;
};