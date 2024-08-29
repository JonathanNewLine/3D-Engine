#pragma once
#include "Drawable.h"
#include "Color.h"
#include "SDL_render.h"

class Triangle : public Drawable
{
public:
	Triangle(float x1, float y1, float x2, float y2, float x3, float y3, Color color);
	
	float& getX1();
	float& getY1();
	float& getX2();
	float& getY2();
	float& getX3();
	float& getY3();


private:
	float _x1;
	float _y1;
	float _x2;
	float _y2;
	float _x3;
	float _y3;
};

