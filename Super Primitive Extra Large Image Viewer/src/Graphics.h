#pragma once
#include <SDL\SDL.h>
#include "Vector2.h"
class Graphics
{
public:
	Graphics();
	

	void setPixel(uint16_t x, uint16_t y, Uint8 r, Uint8 g, Uint8 b);
	void setPixel(uint16_t x, uint16_t y, Uint32 color);
	void drawLine(Vector2 start, Vector2 end, Uint8 r, Uint8 g, Uint8 b);
	void clear(Uint8 r, Uint8 g, Uint8 b);
	int getScreenWidth();
	int getScreenHeight();
	int getPixelCount();
	void flip();
	void clear();
private:
	double fov;
	SDL_Point windowSize;
	SDL_Renderer* renderer;
	SDL_Window* window;
	SDL_Surface* windowSurface;
	Uint32 composeColor(Uint8 r, Uint8 g, Uint8 b);
};