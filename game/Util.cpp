#include "SDL.h"
#include "SDL_image.h" 
#include "Util.h"

SDL_Surface* UTIL_LoadTexture( char* filename )
{
	SDL_Surface* loadedImage = NULL;
	SDL_Surface* optimizedImage = NULL;

	loadedImage = IMG_Load(filename);

	if(loadedImage != NULL)
	{
		optimizedImage = SDL_DisplayFormat(loadedImage);
		SDL_FreeSurface(loadedImage);
	}

	return optimizedImage;
}

void UTIL_RenderTexture(int x, int y, SDL_Surface* src, SDL_Surface* dest)
{
	SDL_Rect offset;

	offset.x = x;
	offset.y = y;

	SDL_BlitSurface(src, NULL, dest, &offset);
}