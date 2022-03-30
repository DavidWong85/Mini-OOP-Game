#pragma once

#ifndef _GAME_H_
#define _GAME_H_
//SDL2
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

//Menu
#include "Menu.h"
#include "Instructions.h"

//Game Object
#include "Player.h"
#include "Element.h"
#include "Score.h"

//Control
#include "Mouse.h"
#include "Keyboard.h"

#include <stdio.h>
#include <iostream>
//Image
#include "TextureManager.h"

class Menu;
class Instructions;
class Player;
class Element;
class Score;
class Mouse;
class Keyboard;
class TextureManager;

class Game {
public:
	Game();
	~Game();
	void Init(const char* title, int xpos, int ypos, int width, int height);
	
	void HandleEvents();
	void Update(Game* game);
	void Render();
	void Clean();

	bool Running() { return isRunning; }
	void setRunning(bool _run) { isRunning = _run; }

	void setgameState(int _gamestate) { gameState = _gamestate; }
	int getgameState() { return gameState; }

	void setplaySound(bool _play) { playSound = _play; }

	Mix_Chunk* getHit() { return Hit; }
	Mix_Chunk* getWrong() { return Wrong; }

private:
	bool playSound = false;
	bool playBGM = false;
	int gameState = 0; // 0 for menu, 1 for start, 2 for instructions, 3 for exit, 4 for final score.
	Mix_Music* BGM;
	Mix_Chunk* Hit, * Wrong;
	SDL_Renderer *renderer = nullptr;
	SDL_Event event;

	int WindowSize;                
	bool isRunning = false;

	SDL_Window *window;
	Menu* m_menu;
	Instructions* m_instructions;
	Player* m_player;
	Element* m_element;
	Score* m_score;
	Mouse* m_mouse;
	Keyboard* m_keyboard;

};

#endif