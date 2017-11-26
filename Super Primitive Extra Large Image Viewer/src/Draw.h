#pragma once
#include "Helpers.h"
static void drawCircle(SDL_Surface* dst, Vector2 center, double radius, uint8_t col_r, uint8_t col_g, uint8_t col_b)
{
	int pixelsToDraw = (radius + 1) * 2 * M_PI;
	Uint32 color = SDL_MapRGB(dst->format, col_r, col_g, col_b);
	double currAngle = 0;
	double anglePerPixel = 2 * M_PI / pixelsToDraw;
	Vector2 radiusVec(radius, radius);
	for (int32_t i = 0; i < pixelsToDraw; ++i)
	{
		Vector2 pixelOffset = Vector2(cos(currAngle), sin(currAngle))*radiusVec;
		Vector2 targetPixelPos = center + pixelOffset;
		setPixel(dst, targetPixelPos.x, targetPixelPos.y, color);
		currAngle += anglePerPixel;
	}
}
static void drawRing(SDL_Surface* dst, Vector2 center, double maxRadius, double thickness, uint8_t col_r, uint8_t col_g, uint8_t col_b)
{
	for (uint32_t i = 0; i < thickness; ++i)
	{
		drawCircle(dst, center, maxRadius - i, col_r, col_g, col_b);
	}
}
static void drawLine(SDL_Surface* dst, Vector2 p1, Vector2 p2, uint8_t r, uint8_t g, uint8_t b)
{
	Vector2 deltaPos = p2 - p1;
	int pixelsToDraw = deltaPos.length();
	Vector2 step = deltaPos / pixelsToDraw;
	Uint32 color = SDL_MapRGB(dst->format, r, g, b);	
	int w = dst->w, h = dst->h;
	for (int i = 0; i < pixelsToDraw; ++i)
	{
		Vector2 pxPos = p1 + step*i;
		if (pxPos.x < dst->w&&pxPos.y >= 0 && pxPos.x >= 0 && pxPos.y < dst->h)	setPixel(dst, pxPos.x, pxPos.y, color);
		else return;
	}
}