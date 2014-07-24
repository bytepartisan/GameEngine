#include "SDL.h" 
#include <stdio.h>
#include "Game.h"
#include "Log.h"

int main( int argc, char* args[] ) {
	new CLog();
	CLog::GetSingleton().Init("log.txt");
	
	new CGame();

	delete CLog::GetSingletonPtr();
	delete CGame::GetSingletonPtr();
	
	return 0; 
}