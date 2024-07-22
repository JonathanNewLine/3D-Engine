#pragma once
#include <SDL_pixels.h>
#include <iostream>

class Color: public SDL_Color
{
public:
	Color(int r, int g, int b, int alpha);
};

