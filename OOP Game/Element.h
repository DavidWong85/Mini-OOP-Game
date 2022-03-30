#pragma once

#ifndef _ELEMENT_H_
#define _ELEMENT_H_

#include "Game.h"
#include <random>

class Game;

class Element {
public:
	Element();
	Element(int x, int y, int _WindowSize);
	~Element();

	void Update();
	void Render(SDL_Renderer* render);

	void Init(SDL_Renderer* render);

	int getType() { return type; }
	void setType(int _type) { type = _type; }
	int getCount() { return Count; }
	void setCount(int _Count) { Count = _Count; }
	int getSpeed() { return Speed; }
	void setSpeed(int _speed) { Speed = _speed; }
	int getX() { return xpos; }
	void setX(int _x) { xpos = _x; }
	int getY() { return ypos; }
	void setY(int _y) { ypos = _y; }

	SDL_Rect getdestRect() { return destRect; }

private:
	SDL_Texture* red, * blue, * brown, * green, * currentTexture;
	SDL_Rect srcRect, destRect;

	int type = 0;
	int Count = 0;
	int Speed = 180;
	int xpos;
	int ypos;
	std::random_device rd;
	std::mt19937 e{ this->rd() };
	int WindowSize;
};

#endif