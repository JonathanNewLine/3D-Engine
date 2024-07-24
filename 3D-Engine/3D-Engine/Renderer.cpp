#include "Renderer.h"

Renderer* Renderer::_instance = nullptr;

Renderer::Renderer(SDL_Window* window)
{
	_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (_renderer == nullptr)
	{
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
	}
	_instance = this;
}

Renderer* Renderer::getInstance()
{
	if (_instance == nullptr)
	{
		throw std::runtime_error("Renderer has not been constructed");
	}
	return _instance;
}

SDL_Renderer* Renderer::getRenderer()
{
	return _renderer;
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(_renderer);
}

void Renderer::setRendererColor(Color color)
{
	SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a);
}

void Renderer::drawRect(Rect* rect)
{
	setRendererColor(rect->getColor());
	SDL_RenderFillRect(_renderer, rect->getSDL_Rect());
}

void Renderer::drawTriangle(Triangle* triangle)
{
	Color color = triangle->getColor();

	vector<SDL_Vertex> vertexes;
	vertexes.push_back({ SDL_FPoint{triangle->getX1(), triangle->getY1()}, SDL_Color{ color.r, color.g, color.b, color.a}, SDL_FPoint{0}});
	vertexes.push_back({ SDL_FPoint{triangle->getX2(), triangle->getY2()}, SDL_Color{ color.r, color.g, color.b, color.a}, SDL_FPoint{0}});
	vertexes.push_back({ SDL_FPoint{triangle->getX3(), triangle->getY3()}, SDL_Color{ color.r, color.g, color.b, color.a}, SDL_FPoint{0}});

	SDL_RenderGeometry(_renderer, nullptr, vertexes.data(), vertexes.size(), nullptr, 0);
}