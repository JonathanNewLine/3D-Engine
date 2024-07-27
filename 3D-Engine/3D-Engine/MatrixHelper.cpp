#include "MatrixHelper.h"

Matrix MatrixHelper::createRotationX(float angle)
{
	Matrix rotationMatrix = {
		{1, 0, 0},
		{0, cos(angle), -sin(angle)},
		{0, sin(angle), cos(angle)}
	};

	return rotationMatrix;
}

Matrix MatrixHelper::createRotationY(float angle)
{
	Matrix rotationMatrix = {
		{cos(angle), 0, -sin(angle)},
		{0, 1, 0},
		{sin(angle), 0, cos(angle)}
	};

	return rotationMatrix;
}

Matrix MatrixHelper::createRotationZ(float angle)
{
	Matrix rotationMatrix = {
		{cos(angle), -sin(angle), 0},
		{sin(angle), cos(angle), 0},
		{0, 0, 1}
	};

	return rotationMatrix;
}

Matrix MatrixHelper::point3DToMatrix(Point3D point)
{
	Matrix matrix = {
		{point.x},
		{point.y},
		{point.z}
	};

	return matrix;
}

Point3D MatrixHelper::matrixToPoint3D(Matrix matrix)
{
	Point3D point = {
		matrix[0][0],
		matrix[1][0],
		matrix[2][0]
	};

	return point;
}

Point2D MatrixHelper::matrixToPoint2D(Matrix matrix)
{
	Point2D point = {
		matrix[0][0],
		matrix[1][0]
	};

	return point;
}

Point3D MatrixHelper::matMultiply(Matrix matrix1, Point3D point)
{
	Matrix matrix2 = point3DToMatrix(point);
	Matrix result = matMultiply(matrix1, matrix2);

	return matrixToPoint3D(result);
}

Matrix MatrixHelper::matMultiply(Matrix matrix1, Matrix matrix2)
{
	int colsA = matrix1[0].size();
	int rowsA = matrix1.size();
	int colsB = matrix2[0].size();
	int rowsB = matrix2.size();

	if (colsA != rowsB)
	{
		throw std::runtime_error("Matrix dimensions do not match");
	}

	Matrix result(rowsA, vector<float>(colsB));

	for (int i = 0; i < rowsA; i++)
	{
		for (int j = 0; j < colsB; j++)
		{
			float sum = 0;
			for (int k = 0; k < colsA; k++)
			{
				sum += matrix1[i][k] * matrix2[k][j];
			}
			result[i][j] = sum;
		}
	}
	return result;
}

Point2D MatrixHelper::getProjectedPoint(Point3D point)
{
	Matrix projectionMatrix = {
		{1, 0, 0},
		{0, 1, 0}
	};

	Matrix pointMatrix = point3DToMatrix(point);
	Matrix result = matMultiply(projectionMatrix, pointMatrix);

	return matrixToPoint2D(result);
}
