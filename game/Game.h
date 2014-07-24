#ifndef GAME_H
#define GAME_H

#include "SDL.h"

#include "Singleton.h"

class CGame : public Singleton<CGame>{
public:
	CGame();
	~CGame();
private:
	void Init();
	void Render();
	void HandleEvents();
	void Update();
	SDL_Surface *background;
};

#endif