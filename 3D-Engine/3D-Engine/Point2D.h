#pragma once
#include "Drawable.h"

class Point2D : public Drawable
{
public:
	float x;
	float y;
	Point2D(float x, float y, Color color=Color(255, 255, 255, 255));
	void operator*=(float scalar);
	void operator+=(float scalar);
	void operator+=(Point2D point);
};

