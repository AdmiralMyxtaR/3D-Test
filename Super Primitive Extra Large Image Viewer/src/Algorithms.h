#pragma once
static void renderScaled(SDL_Surface* src, SDL_Rect* srcRect, SDL_Surface* dst, SDL_Rect* dstRect)
{
	if (srcRect == nullptr) srcRect = &src->clip_rect;
	if (dstRect == nullptr) dstRect = &dst->clip_rect;
	Vector2 srcDims(srcRect->w, srcRect->h);
	Vector2 srcPos(srcRect->x, srcRect->y);
	Vector2 srcPosEnd = srcDims + srcPos;
	Vector2 dstDims(dstRect->w, dstRect->h);
	Vector2 dstPos(dstRect->x, dstRect->y);
	Vector2 dstPosEnd = dstDims + dstPos;
	Vector2 step = srcDims / dstDims;
	for (int y = dstPos.y; y < dstPosEnd.y; ++y)
	{
		Vector2 currOffset(0, y);
		for (int x = dstPos.x; x < dstPosEnd.x; ++x)
		{
			currOffset.x = x;
			currOffset -= dstPos;
			Vector2 targetSrcPxPos(srcPos);
			targetSrcPxPos += step*currOffset;
			Uint32 pixel = getPixel(src, targetSrcPxPos.x, targetSrcPxPos.y);
			Uint8 r, g, b;
			SDL_GetRGB(pixel, src->format, &r, &g, &b);
			pixel = SDL_MapRGB(dst->format, r, g, b);
			setPixel(dst, x, y, pixel);
		}
	}
}

static void setPixel(Uint32* pixel, Uint32 color)
{
	*pixel = color;
}

static void setPixel(int pixelNumber, Uint32 color)
{

}