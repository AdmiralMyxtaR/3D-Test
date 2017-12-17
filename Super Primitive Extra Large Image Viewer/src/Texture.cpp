#include "Texture.h"

Texture::Texture(SDL_Surface * surface)
{
	this->surface = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_ARGB8888, 0);
	this->width = this->surface->w;
	this->height = this->surface->h;
}

void Texture::setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b)
{
	if (x >= 0 && y >= 0 && x < this->getWidth() && y < this->getHeight())
		((Uint32*)(this->surface->pixels))[this->getHeight()*y + x] = this->composeColor(r, g, b);
}

Uint32 Texture::composeColor(uint8_t r, uint8_t g, uint8_t b)
{
	return r << 16 | g << 8 | b;
}

Uint32 Texture::getPixel(int x, int y)
{
	if (x >= 0 && y >= 0 && x < this->getWidth() && y < this->getHeight())
		return ((Uint32*)(this->surface->pixels))[this->getWidth()*y + x];
	return 0;
}

int Texture::getWidth()
{
	return this->width;
}

int Texture::getHeight()
{
	return this->height;
}
