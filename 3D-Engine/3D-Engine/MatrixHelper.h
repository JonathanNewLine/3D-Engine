#pragma once
#include <cmath>
#include <vector>
#include "Point3D.h"
#include "Point2D.h"

using std::vector;

typedef vector<vector<float>> Matrix;

class MatrixHelper
{
public:
	static Matrix createRotationX(float angle);
	static Matrix createRotationY(float angle);
	static Matrix createRotationZ(float angle);

	static Matrix point3DToMatrix(Point3D point);	
	static Point3D matrixToPoint3D(Matrix matrix);
	static Point2D matrixToPoint2D(Matrix matrix);
	static Point3D matMultiply(Matrix matrix1, Point3D point);
	static Matrix matMultiply(Matrix matrix1, Matrix matrix2);
	static Point2D getProjectedPoint(Point3D point);
};

