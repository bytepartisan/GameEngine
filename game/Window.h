#ifndef WINDOW_H
#define WINDOW_H

#include "SDL.h" 
#include "Singleton.h"

class CWindow : public Singleton<CWindow>
{
public:
	CWindow();
	~CWindow();

	void Init(char* title, int width, int height, int bpp, Uint32 flags);
	SDL_Surface* GetScreen();
	void UpdateScreen();

private:
	SDL_Surface* screen;
};

#endif