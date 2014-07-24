#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "SDL.h" 
#include "Singleton.h"

enum game_state_t{
	GAME_RUN,
	GAME_MENU,
	GAME_QUIT
};

class CGamestate : public Singleton<CGamestate>
{
public:
	CGamestate();
	~CGamestate();
	void Init(game_state_t state);
	game_state_t GetGameState();
	void SetGameState(game_state_t state);
private:
	game_state_t gameState;
};

#endif