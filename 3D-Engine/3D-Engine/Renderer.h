#pragma once

#include <SDL_render.h>
#include "Rect.h"
#include "Triangle.h"
#include <vector>
#include <iostream>

#include "Point3D.h"

#define POINT_RADIUS 10

using std::vector;

class Renderer
{
public:
	Renderer(SDL_Window* window);
	~Renderer();
	SDL_Renderer* getRenderer();
	static Renderer* getInstance();

	void setRendererColor(Color color);
	void drawRect(Rect* rect);
	void drawTriangle(Triangle* triangle);
	void drawPoint(Point3D point);

private:
	SDL_Renderer* _renderer;
	static Renderer* _instance;
};
