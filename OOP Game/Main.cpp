#include "Game.h"
#include "Mouse.h"

Game* game = nullptr;

int main(int argc, char* argv[]) 
{
	const int WindowSize = 900; //Set Window Size
	const int FPS = 60; //Set Prefered FPS
	const int FrameDelay = 1000 / FPS;

	Uint32 FrameStart;
	int FrameTime;

	game = new Game();
	game->Init("Click The Circle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WindowSize, WindowSize);

	while (game->Running()) 
	{
		FrameStart = SDL_GetTicks();
		game->HandleEvents();
		game->Update(game);
		game->Render();

		//Limit FPS
		FrameTime = SDL_GetTicks() - FrameStart;
		if (FrameDelay > FrameTime) {
			SDL_Delay(FrameDelay - FrameTime);
		}
	}

	game->Clean();
	return 0;
}