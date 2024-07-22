#pragma once
#include <iostream>
#include <SDL.h>
#include "Rect.h"
#include "Renderer.h"

#undef main

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

class Engine
{
public:
	Engine();
	~Engine();
	void run();
private:
	SDL_Window* _window;
	Renderer* _renderer;
	SDL_Event _event;
	bool _isRunning;
};

