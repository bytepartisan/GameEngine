#include "SDL.h" 
#include "Window.h"
#include "Log.h"
#include "Gamestate.h"

CWindow::CWindow(){}

CWindow::~CWindow(){
	SDL_Quit();
}

SDL_Surface* CWindow::GetScreen(){
	return this->screen;
}

void CWindow::UpdateScreen(){
	SDL_Flip(this->screen);
}

void CWindow::Init(char* title, int width, int height, int bpp, Uint32 flags)
{
	try{
		SDL_Init( SDL_INIT_EVERYTHING );
	} catch ( int e ) {
		CLog::GetSingleton().WriteError("Failed to initialise SDL", e);
		CGamestate::GetSingleton().SetGameState(GAME_QUIT);
	}

	try{
		this->screen = SDL_SetVideoMode(width, height, bpp, flags);
	} catch ( int e ) {
		CLog::GetSingleton().WriteError("Failed to set Video Mode", e);
		CGamestate::GetSingleton().SetGameState(GAME_QUIT);
	}

	if(this->screen == NULL){
		CLog::GetSingleton().Write("Screen creation failed");
		CGamestate::GetSingleton().SetGameState(GAME_QUIT);
	}


	SDL_WM_SetCaption(title, NULL);
}