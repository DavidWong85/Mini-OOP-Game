#pragma once

#include "Game.h"
#include <string>
#include <fstream>

#ifndef _SCORE_H_
#define _SCORE_H_

class Game;
class Menu;

class Score {
public:
	Score();
	Score(int x, int y, int _WindowSize);
	~Score();

	void Update(Game* game, Menu* menu);
	void Render(SDL_Renderer* render);

	int getHealth() { return Health; }
	void setHealth(int _health) { Health = _health; }

	int getScore() { return CurrentScore; }
	void setScore(int _score) { CurrentScore = _score; }
	
private:
	SDL_Color color = { 100, 100, 100 };
	TTF_Font * arial;
	std::string Line;
	int w, h;
	SDL_Surface * screen;
	const char *cstr;
	std::string string;
	SDL_Rect Message_rect , Message2_rect;
	SDL_Surface* surfaceMessage;
	SDL_Texture* Message;

	int CurrentScore = 0;
	int Health = 4;
	int xpos;
	int ypos;
};

#endif