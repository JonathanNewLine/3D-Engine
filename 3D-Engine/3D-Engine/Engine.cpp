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

		_renderer->setRendererColor(Color(0, 0, 0, 255));
		SDL_RenderClear(_renderer->getRenderer());

		Point3D pointArray[] = {
			Point3D(100, 100, 0),
			Point3D(200, 100, 0),
			Point3D(100, 200, 0),
			Point3D(200, 200, 0)
		};

		for (int i = 0; i < 4; i++)
		{
			Point3D rotatedPoint = Point3D(MatrixHelper::MatMultiply(MatrixHelper::CreateRotationX(10), pointArray[i].toMatrix()));
			_renderer->drawPoint(rotatedPoint);
		}

		SDL_RenderPresent(_renderer->getRenderer());
	}
}
