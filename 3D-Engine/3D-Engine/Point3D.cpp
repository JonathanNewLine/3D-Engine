#include "Point3D.h"

Point3D::Point3D(float x, float y, float z, Color color) : Drawable(color)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Point3D::operator*=(float scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
}

void Point3D::operator+=(float scalar)
{
	x += scalar;
	y += scalar;
	z += scalar;
}

void Point3D::operator+=(Point3D point)
{
	x += point.x;
	y += point.y;
	z += point.z;
}

Point3D Point3D::operator+(Point3D point)
{
	return Point3D(x + point.x, y + point.y, z + point.z);
}