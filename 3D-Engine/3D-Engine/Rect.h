#pragma once
#include "Color.h"
#include <SDL_rect.h>


class Rect : public SDL_Rect
{
public:
    Rect(int x, int y, int w, int h, Color color);


    float& getXPosition();
    float& getYPosition();
    float getWidth();
    float getHeight();
    Color getColor();
    void setColor(Color color);
    unsigned int getId();

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

private:

    static unsigned int generateId();
    static unsigned int nextId;

    // support floats for positions
    float _xPosition;
    float _yPosition;

    Color _color;

    unsigned int _id;
};