#pragma once

#include "Menu.h"
#include <string>
#include <fstream>

class Menu;

class Instructions {
public:
	Instructions();
	~Instructions();

	void Render(SDL_Renderer* render, Menu* menu);
	void Init(SDL_Renderer* render);

private:
	SDL_Color color = { 100, 100, 100 };
	TTF_Font * arial;
	std::string Line;
	int w, h;
	SDL_Surface * screen;
	const char *cstr;
	std::string string;
	SDL_Rect Message_rect, Message2_rect;
	SDL_Surface* surfaceMessage;
	SDL_Texture* InsMessage[10];
};