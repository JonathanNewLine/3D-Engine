#include "Renderer.h"
#include <iostream>

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
	SDL_RenderFillRect(_renderer, rect);
}
