#pragma once

#include <SDL_render.h>
#include "Rect.h"

class Renderer
{
public:
	Renderer(SDL_Window* window);
	~Renderer();
	SDL_Renderer* getRenderer();
	static Renderer* getInstance();

	void setRendererColor(Color color);
	void drawRect(Rect* rect);

private:
	SDL_Renderer* _renderer;
	static Renderer* _instance;
};
