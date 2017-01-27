/******************************************************************
* ENTI FROGGER GRUPO 8 (ALEX CALVO Y ADRIA GONZALEZ *
******************************************************************/

#include "GameEngine.hh"

// Game constants
#define SCREEN_WIDTH 830
#define SCREEN_HEIGHT 800

int main(int argc, char* args[]) {
	GameEngine::Run<SCREEN_WIDTH, SCREEN_HEIGHT>("ENTI Frogger");
	return 0;
}