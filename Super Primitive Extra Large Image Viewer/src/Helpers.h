#pragma once
static Vector2 STEP_BY_STEP_RENDERING(0, 100);
static uint64_t PIXELS_DRAWN_DELTA = 0;
static void setPixel(SDL_Surface* surface, int X, int Y, int r, int g, int b)
{

	Uint8* pixel = (Uint8*)surface->pixels;
	pixel += (Y * surface->pitch) + (X * sizeof(Uint32));
	*((Uint32*)pixel) = SDL_MapRGB(surface->format, r, g, b);
	++PIXELS_DRAWN_DELTA;
}
static void setPixel(SDL_Surface* surface, int X, int Y, Uint32 px)
{

	Uint8* pixel = (Uint8*)surface->pixels;
	pixel += (Y * surface->pitch) + (X * sizeof(Uint32));
	*((Uint32*)pixel) = px;
	++PIXELS_DRAWN_DELTA;
}
static Uint32 getPixel(SDL_Surface *surface, int x, int y)
{
	int bpp = surface->format->BytesPerPixel;
	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	return *(Uint32*)p;
}/*
void proxyWait()
{
	if (STEP_BY_STEP_RENDERING.x)
	{
		SDL_UpdateWindowSurface(WINDOW);
		SDL_Delay(STEP_BY_STEP_RENDERING.y);
	}
}
*/
static void SDL_BlitSurface_Proxy(SDL_Surface* srcSurf, SDL_Rect* srcRect, SDL_Surface* dstSurf, SDL_Rect* dstRect)
{
	SDL_BlitSurface(srcSurf, srcRect, dstSurf, dstRect);
	//proxyWait();
}
static void SDL_BlitScaled_Proxy(SDL_Surface* srcSurf, SDL_Rect* srcRect, SDL_Surface* dstSurf, SDL_Rect* dstRect)
{
	SDL_BlitScaled(srcSurf, srcRect, dstSurf, dstRect);
	//proxyWait();
}
/*
void presenterFunc()
{
	while (true)
	{
		if (PRESENTER_ACTIVE) SDL_UpdateWindowSurface(WINDOW);
		std::this_thread::sleep_for(500ms);
	}
}*/