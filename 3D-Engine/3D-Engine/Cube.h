#pragma once

#include "Point3D.h"
#include "MatrixHelper.h"
#include "Drawable.h"
#include "Renderer.h"

class Cube : public Drawable
{
public:
	Cube(Point3D position, float sideLength, Color color=Color(255, 255, 255, 255));

	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);

	void renderCube();

	~Cube();
private:
	vector<Point3D> _points;
	Point3D _position;
};

