#pragma once
#include <SDL\SDL.h>
class Texture
{
public:
	Texture() = default;
	Texture(SDL_Surface* surface);
	void setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b);
	Uint32 composeColor(uint8_t r, uint8_t g, uint8_t b);
	Uint32 getPixel(int x, int y);
	int getWidth();
	int getHeight();
private:
	SDL_Surface* surface;
	int width;
	int height;
};