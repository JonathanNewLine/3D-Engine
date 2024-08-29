#include "Cube.h"

Cube::Cube(Point3D position, float sideLength, Color color) : Drawable(color), _position(position)
{
	float halfSideLength = sideLength / 2;

	_points = {
		Point3D(-halfSideLength, -halfSideLength, -halfSideLength, color),
		Point3D(halfSideLength, -halfSideLength, -halfSideLength, color),
		Point3D(halfSideLength, halfSideLength, -halfSideLength, color),
		Point3D(-halfSideLength, halfSideLength, -halfSideLength, color),
		Point3D(-halfSideLength, -halfSideLength, halfSideLength, color),
		Point3D(halfSideLength, -halfSideLength, halfSideLength, color),
		Point3D(halfSideLength, halfSideLength, halfSideLength, color),
		Point3D(-halfSideLength, halfSideLength, halfSideLength, color)

	};
}

void Cube::rotateX(float angle)
{
	for (Point3D& point : _points)
	{
		point = MatrixHelper::matMultiply(MatrixHelper::createRotationX(angle), point);
	}
}

void Cube::rotateY(float angle)
{
	for (Point3D& point : _points)
	{
		point = MatrixHelper::matMultiply(MatrixHelper::createRotationY(angle), point);
	}
}

void Cube::rotateZ(float angle)
{
	for (Point3D& point : _points)
	{
		point = MatrixHelper::matMultiply(MatrixHelper::createRotationZ(angle), point);
	}
}

void Cube::renderCube()
{

	Renderer* renderer = Renderer::getInstance();

	vector<Point3D> updatedPoints;

	for (Point3D point : _points)
	{
		updatedPoints.push_back(point + _position);
	}

	vector<Point2D> projectedPoints;
	for (Point3D point : updatedPoints)
	{
		Point2D projectedPoint = MatrixHelper::getProjectedPoint(point);
		projectedPoints.push_back(projectedPoint);
		renderer->drawPoint(projectedPoint);
	}

	for (int i = 0; i < 4; i++)
	{
		renderer->drawLine(projectedPoints[i], projectedPoints[(i + 1) % 4]);
		renderer->drawLine(projectedPoints[i + 4], projectedPoints[((i + 1) % 4) + 4]);
		renderer->drawLine(projectedPoints[i], projectedPoints[i + 4]);
	}
}

Cube::~Cube()
{

}