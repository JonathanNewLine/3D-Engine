#pragma once
#include "Drawable.h"

class Point3D : public Drawable
{
public:
	float x;
	float y;
	float z;
	Point3D(float x, float y, float z, Color color=Color(255, 255, 255, 255));
	void operator*=(float scalar);
	void operator+=(float scalar);
	void operator+=(Point3D point);
	Point3D operator+(Point3D point);
};
