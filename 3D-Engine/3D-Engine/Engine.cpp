#include "Engine.h"

Engine::Engine()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	}
	_window = SDL_CreateWindow("3D Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (_window == nullptr)
	{
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
	}
	_renderer = new Renderer(_window);

	_isRunning = true;
}

Engine::~Engine()
{
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

void Engine::run()
{
	Cube* cube = new Cube(Point3D(400, 300, 400), 200);
	while (_isRunning)
	{
		while (SDL_PollEvent(&_event))
		{
			if (_event.type == SDL_QUIT)
			{
				_isRunning = false;
			}
		}

		_renderer->setRendererColor(Color(0, 0, 0, 255));
		SDL_RenderClear(_renderer->getRenderer());

		cube->rotateX(0.01);
		cube->rotateY(0.015);
		cube->rotateZ(0.0175);

		cube->renderCube();

		SDL_RenderPresent(_renderer->getRenderer());
	}
}
