#include "Instructions.h"

Instructions::Instructions()
{
	arial = TTF_OpenFont("assets/arial.ttf", 30);
	Message_rect.x = 0;
	Message_rect.y = 0;
}

Instructions::~Instructions() {}

void Instructions::Render(SDL_Renderer* render, Menu* menu)
{
	std::ifstream myFile("Instructions.txt");
	int i = 0;
	Message_rect.y = 0;
	while (getline(myFile, Line))
	{
		std::string str = Line;
		cstr = str.c_str();
		TTF_SizeText(arial, cstr, &w, &h);
		Message_rect.w = w;
		Message_rect.h = h;
		Message_rect.x = ((900 - Message_rect.w) / 2);
		Message_rect.y = Message_rect.y + 40;
		SDL_RenderCopy(render, InsMessage[i], NULL, &Message_rect);
		i++;
	}
	myFile.close();
	SDL_RenderCopy(render, menu->getBTM(), &menu->getB4srcRect(), &menu->getB4destRect());
}

void Instructions::Init(SDL_Renderer* render)
{
	int i = 0;
	std::ifstream myFile("Instructions.txt");
	while (getline(myFile, Line))
	{
		std::string str = Line;
		cstr = str.c_str();
		TTF_SizeText(arial, cstr, &w, &h);
		Message_rect.w = w;
		Message_rect.h = h;
		surfaceMessage = TTF_RenderText_Solid(arial, cstr, color);
		SDL_BlitSurface(surfaceMessage, NULL, screen, NULL);
		InsMessage[i] = SDL_CreateTextureFromSurface(render, surfaceMessage);
		SDL_FreeSurface(surfaceMessage);
		i++;
	}
	myFile.close();
}