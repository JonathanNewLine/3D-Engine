#include "MatrixHelper.h"

Matrix MatrixHelper::CreateRotationX(float angle)
{
	Matrix rotationMatrix = {
		{1, 0, 0},
		{0, cos(angle), -sin(angle)},
		{0, sin(angle), cos(angle)}
	};

	return rotationMatrix;
}

Matrix MatrixHelper::CreateRotationY(float angle)
{
	Matrix rotationMatrix = {
		{cos(angle), 0, sin(angle)},
		{0, 1, 0},
		{-sin(angle), 0, cos(angle)}
	};

	return rotationMatrix;
}

Matrix MatrixHelper::CreateRotationZ(float angle)
{
	Matrix rotationMatrix = {
		{cos(angle), -sin(angle), 0},
		{sin(angle), cos(angle), 0},
		{0, 0, 1}
	};

	return rotationMatrix;
}

Matrix MatrixHelper::MatMultiply(Matrix matrix1, Matrix matrix2)
{
	Matrix resultMatrix = {
		{0},
		{0},
		{0}
	};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}

	return resultMatrix;
}
