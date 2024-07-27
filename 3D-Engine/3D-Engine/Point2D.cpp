#include "Point2D.h"

Point2D::Point2D(float x, float y, Color color) : Drawable(color)
{
	this->x = x;
	this->y = y;
}

void Point2D::operator*=(float scalar)
{
	x *= scalar;
	y *= scalar;
}

void Point2D::operator+=(float scalar)
{
	x += scalar;
	y += scalar;
}

void Point2D::operator+=(Point2D point)
{
	x += point.x;
	y += point.y;
}