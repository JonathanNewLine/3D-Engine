#include "Triangle.h"

Triangle::Triangle(float x1, float y1, float x2, float y2, float x3, float y3, Color color) : Drawable(color)
{
	_x1 = x1;
	_y1 = y1;
	_x2 = x2;
	_y2 = y2;
	_x3 = x3;
	_y3 = y3;

}

float& Triangle::getX1()
{
	return _x1;
}

float& Triangle::getY1()
{
	return _y1;
}

float& Triangle::getX2()
{
	return _x2;
}

float& Triangle::getY2()
{
	return _y2;
}

float& Triangle::getX3()
{
	return _x3;
}

float& Triangle::getY3()
{
	return _y3;
}
