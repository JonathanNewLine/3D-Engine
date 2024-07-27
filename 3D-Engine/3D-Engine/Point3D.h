#pragma once
#include "Drawable.h"
#include "MatrixHelper.h"
#define DIMENSIONS 3

class Point3D : public Drawable
{
public:
	float x;
	float y;
	float z;
	Point3D(float x, float y, float z, Color color=Color(255, 255, 255, 255));
	Point3D(Matrix matrix, Color color = Color(255, 255, 255, 255));
	Matrix toMatrix();
};
