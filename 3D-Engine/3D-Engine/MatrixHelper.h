#pragma once
#include <cmath>
#include <vector>
using std::vector;

typedef vector<vector<float>> Matrix;

class MatrixHelper
{
public:
	static Matrix MatMultiply(Matrix matrix1, Matrix matrix2);
	static Matrix CreateRotationX(float angle);
	static Matrix CreateRotationY(float angle);
	static Matrix CreateRotationZ(float angle);
};

