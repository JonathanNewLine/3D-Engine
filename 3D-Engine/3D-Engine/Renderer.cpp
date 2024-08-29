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

void Renderer::drawPoint(Point2D point)
{
	Color color = point.getColor();
	setRendererColor(color);

	int x = point.x;
	int y = point.y;

	for (int w = 0; w < POINT_RADIUS * 2; w++)
	{
		for (int h = 0; h < POINT_RADIUS * 2; h++)
		{
			int dx = POINT_RADIUS - w;
			int dy = POINT_RADIUS - h;
			if ((dx*dx + dy*dy) <= (POINT_RADIUS * POINT_RADIUS))
			{
				SDL_RenderDrawPoint(_renderer, x + dx, y + dy);
			}
		}
	}
}

void Renderer::drawLine(Point2D point1, Point2D point2)
{
	Color color = point1.getColor();
	setRendererColor(color);

	SDL_RenderDrawLine(_renderer, point1.x, point1.y, point2.x, point2.y);
}

