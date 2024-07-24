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
	while (_isRunning)
	{
		while (SDL_PollEvent(&_event))
		{
			if (_event.type == SDL_QUIT)
			{
				_isRunning = false;
			}
		}
		_renderer->setRendererColor(Color(255, 255, 255, 255));
		SDL_RenderClear(_renderer->getRenderer());

		_renderer->drawRect(new Rect(0, 0, 100, 100, Color(255, 0, 0, 255)));
		_renderer->drawTriangle(new Triangle(400, 150, 200, 450, 600, 450, Color(0, 255, 0, 255)));
		SDL_RenderPresent(_renderer->getRenderer());
	}
}