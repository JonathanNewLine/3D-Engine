#pragma once

#include <SDL_render.h>
#include "Rect.h"
#include "Triangle.h"
#include <vector>
#include <iostream>

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

private:
	SDL_Renderer* _renderer;
	static Renderer* _instance;
};
