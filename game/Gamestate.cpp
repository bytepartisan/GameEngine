#include "Gamestate.h"

CGamestate::CGamestate(){}

CGamestate::~CGamestate(){}

void CGamestate::Init(game_state_t state){
	this->gameState = state;
};

void CGamestate::SetGameState(game_state_t state){
	this->gameState = state;
}

game_state_t CGamestate::GetGameState(){
	return this->gameState;
}