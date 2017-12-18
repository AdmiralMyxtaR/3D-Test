#include "Graphics.h"
#include "globals.h"
#include <iostream>
Graphics::Graphics()
{
	this->window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0);
	//this->renderer = SDL_CreateRenderer(this->window, -1, 0);
	/*Uint32 a = SDL_GetWindowPixelFormat(this->window);
	SDL_PixelForma*/
	this->windowSurface = SDL_GetWindowSurface(this->window);
	this->windowSize = { windowSurface->clip_rect.w, windowSurface->clip_rect.h };
	this->fov = M_PI;
	globals::fov = &this->fov;
	zbuffer = ZBuffer(windowSize.x, windowSize.y);
	globals::zbuffer = &zbuffer;
}

void Graphics::setPixel(uint16_t x, uint16_t y, Uint8 r, Uint8 g, Uint8 b)
{
	if (x < this->getScreenWidth() && y < this->getScreenHeight())
		((Uint32*)(this->windowSurface->pixels))[this->getScreenWidth()*y + x] = composeColor(r, g, b);
}

void Graphics::setPixel(uint16_t x, uint16_t y, Uint32 color)
{
	if (x < this->getScreenWidth() && y < this->getScreenHeight())
		((Uint32*)(this->windowSurface->pixels))[this->getScreenWidth()*y + x] = color;
}

void Graphics::drawLine(Vector2 start, Vector2 end, Uint8 r, Uint8 g, Uint8 b)
{
	double borderX = this->getScreenWidth();
	double borderY = this->getScreenHeight(); 
	int length = (end - start).length();
	//if (length > 3840) std::cout << "s:" << start.x << "," << start.y << " e:" << end.x << "," << end.y << " l:" << length << "\n";
	if (length > sqrt(1920*1920+1080*1080)) return; //TEMPORARY WORKAROUND FOR INSANELY BIG LINES, NEED TO IMPLEMENT OUT OF BOUNDS CULLING!!!
	Vector2 step = (end - start) / double(length);
	for (int i = 0; i < length; ++i)
	{
		this->setPixel(start.x, start.y, r, g, b);
		start += step;
	}
}

void Graphics::clear(Uint8 r, Uint8 g, Uint8 b)
{
	Uint32 color = this->composeColor(r, g, b);
	for (int y = 0; y < this->getScreenHeight(); ++y)
	{
		for (int x = 0; x < this->getScreenWidth(); ++x)
		{
			this->setPixel(x, y, color);
		}
	}
}

int Graphics::getScreenWidth()
{
	return this->windowSize.x;
}

int Graphics::getScreenHeight()
{
	return this->windowSize.y;
}

int Graphics::getPixelCount()
{
	return this->getScreenWidth()*this->getScreenHeight();
}

void Graphics::flip()
{
	SDL_UpdateWindowSurface(this->window);
}

void Graphics::clear()
{
	memset(this->windowSurface->pixels, 0, this->getPixelCount() * 4);
}

Uint32 Graphics::composeColor(Uint8 r, Uint8 g, Uint8 b)
{
	return r << 16 | g << 8 | b;
}
