#include "Point3D.h"

Point3D::Point3D(float x, float y, float z, Color color) : Drawable(color)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Point3D::Point3D(Matrix matrix, Color color) : Drawable(color)
{
	this->x = matrix[0][0];
	this->y = matrix[1][0];
	this->z = matrix[2][0];
}

Matrix Point3D::toMatrix()
{
		Matrix matrix = {
		{x},
		{y},
		{z},
	};

	return matrix;
}


