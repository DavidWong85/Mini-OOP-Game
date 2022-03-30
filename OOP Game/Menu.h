#pragma once

#include "Game.h"
#include <string>
#include <fstream>

class Menu {
public:
	Menu();
	~Menu();

	void Render(SDL_Renderer* render);
	void Init(SDL_Renderer* render);

	SDL_Rect getB1destRect() { return B1destRect; }
	SDL_Rect getB2destRect() { return B2destRect; }
	SDL_Rect getB3destRect() { return B3destRect; }
	SDL_Rect getB4destRect() { return B4destRect; }
	SDL_Rect getB4srcRect() { return B4srcRect; }
	SDL_Texture* getBTM() { return BTM; }

	void setState(int _state) { State = _state; }
	int getState() { return State; }

private:
	int State = 1; // 0 for none, 1 for menu , 2 instructions , 3 for back to menu.

	SDL_Color color = { 100, 100, 100 };
	TTF_Font * Title_f, * Score_f;
	std::string Line;
	int w, h;
	SDL_Surface * screen;
	const char *cstr;
	std::string string;
	SDL_Rect Message_rect, Message2_rect;
	SDL_Surface* surfaceMessage;
	SDL_Texture* Title, * Score;

	SDL_Texture* Start, * Instructions, * Exit, * BTM;
	SDL_Rect Title_rect, B1srcRect, B1destRect, B2srcRect, B2destRect, B3srcRect, B3destRect, B4srcRect, B4destRect;



};