#pragma once

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Game.h"

class Game;

class Player {
public:
	Player();
	Player(int x, int y, int _WindowSize);
	~Player();

	void Update();
	void Render(SDL_Renderer* render);

	void Init(SDL_Renderer* render);

	int GetX();
	void SetX(int _x);
	int GetY();
	void SetY(int _y);
	int getType() { return Type; }
	void setType(int _type) { Type = _type; }

	bool getMouse() { return mouseclicked; }
	void setMouse(bool _mouse) { mouseclicked = _mouse; }

	bool getKeyboard() { return keyboardclicked; }
	void setKeyboard(bool _keyboard) { keyboardclicked = _keyboard; }

	SDL_Rect getdestRect() { return destRect; }
private:
	SDL_Texture* red, *blue, *brown, *green, *currentTexture;
	SDL_Rect srcRect, destRect;
	
	int xpos;
	int ypos;
	int Type = 1;
	bool mouseclicked = false;
	bool keyboardclicked = false;
};

#endif