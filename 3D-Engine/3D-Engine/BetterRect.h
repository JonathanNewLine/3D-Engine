#pragma once
#include <SDL_rect.h>


class BetterRect : public SDL_Rect
{
public:
    BetterRect(int x, int y, int w, int h, SDL_Color color);


    float& getXPosition();
    float& getYPosition();
    float getWidth();
    float getHeight();
    SDL_Color getColor();
    void setColor(SDL_Color color);
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

    SDL_Color _color;

    unsigned int _id;
};