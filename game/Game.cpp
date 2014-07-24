#include "SDL.h"
#include "Window.h"
#include "Game.h"
#include "Gamestate.h"
#include "Settings.h"
#include "Util.h"

CGame::CGame(){
	new CGamestate;
	new CWindow;
	new CSettings;

	CGamestate::GetSingleton().Init(GAME_RUN);
	CSettings::GetSingleton().Init();
	CWindow::GetSingleton().Init("Crystal Engine", CSettings::GetSingleton().screenWidth, CSettings::GetSingleton().screenHeight, CSettings::GetSingleton().screenBpp, SDL_SWSURFACE);
	this->Init();

	while(CGamestate::GetSingleton().GetGameState() != GAME_QUIT){
		this->HandleEvents();
		this->Update();
		this->Render();
		CWindow::GetSingleton().UpdateScreen();
	}

	delete CGamestate::GetSingletonPtr();
	delete CWindow::GetSingletonPtr();
	delete CSettings::GetSingletonPtr();
}

CGame::~CGame(){
	SDL_FreeSurface(this->background);
}

void CGame::Init(){
	this->background = UTIL_LoadTexture("textures/background2.jpg");
}

void CGame::Render(){
	UTIL_RenderTexture(0, 0, this->background, CWindow::GetSingleton().GetScreen());
}

void CGame::Update(){

}

void CGame::HandleEvents(){
	SDL_Event sdlEvent;
	while(SDL_PollEvent(&sdlEvent))
	{
		if(sdlEvent.type == SDL_QUIT){
			CGamestate::GetSingleton().SetGameState(GAME_QUIT);
		}
	}
}