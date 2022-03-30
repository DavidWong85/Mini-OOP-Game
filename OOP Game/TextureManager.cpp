#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(SDL_Renderer* render, const char* texture) 
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(render, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}