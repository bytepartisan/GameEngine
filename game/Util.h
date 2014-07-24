#ifndef UTIL_H
#define UTIL_H

#include "SDL.h"

SDL_Surface *UTIL_LoadTexture(char* filename);
void UTIL_RenderTexture(int x, int y, SDL_Surface* src, SDL_Surface* dest);

#endif