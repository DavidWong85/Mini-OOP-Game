#pragma once

#include "Game.h"

class Game;

class TextureManager {
public:
	static SDL_Texture* LoadTexture(SDL_Renderer* render, const char* fleName);	
};