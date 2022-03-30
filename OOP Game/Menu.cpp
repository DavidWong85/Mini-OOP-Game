#include "Menu.h"

Menu::Menu() 
{
	Title_f = TTF_OpenFont("assets/arial.ttf", 100);
	Score_f = TTF_OpenFont("assets/arial.ttf", 60);

	Message_rect.x = 100;
	Message_rect.y = 100;

	B1srcRect.x = 0;
	B1srcRect.y = 0;
	B1srcRect.w = 100;
	B1srcRect.h = 40;

	B1destRect.x = 300;
	B1destRect.y = 300;
	B1destRect.w = B1srcRect.w * 3;
	B1destRect.h = B1srcRect.h * 3;

	B2srcRect.x = 0;
	B2srcRect.y = 0;
	B2srcRect.w = 100;
	B2srcRect.h = 40;

	B2destRect.x = 300;
	B2destRect.y = 500;
	B2destRect.w = B2srcRect.w * 3;
	B2destRect.h = B2srcRect.h * 3;

	B3srcRect.x = 0;
	B3srcRect.y = 0;
	B3srcRect.w = 100;
	B3srcRect.h = 40;

	B3destRect.x = 300;
	B3destRect.y = 700;
	B3destRect.w = B3srcRect.w * 3;
	B3destRect.h = B3srcRect.h * 3;

	B4srcRect.x = 0;
	B4srcRect.y = 0;
	B4srcRect.w = 100;
	B4srcRect.h = 40;

	B4destRect.x = 300;
	B4destRect.y = 700;
	B4destRect.w = B4srcRect.w * 3;
	B4destRect.h = B4srcRect.h * 3;
}

Menu::~Menu() {}

void Menu::Render(SDL_Renderer* render)
{
	if (State == 1)
	{
		std::ifstream myFile("title.txt");
		if (myFile.is_open())
		{
			SDL_DestroyTexture(Title);
			while (getline(myFile, Line))
			{
				std::string str = Line;
				cstr = str.c_str();
				TTF_SizeText(Title_f, cstr, &w, &h);
				Message_rect.x = ((900 - Message_rect.w) / 2);
				Message_rect.w = w;
				Message_rect.h = h;
				surfaceMessage = TTF_RenderText_Solid(Title_f, cstr, color);
				SDL_BlitSurface(surfaceMessage, NULL, screen, NULL);
				Title = SDL_CreateTextureFromSurface(render, surfaceMessage);
				SDL_RenderCopy(render, Title, NULL, &Message_rect); //title
				SDL_FreeSurface(surfaceMessage);
			}
		}
		myFile.close();
		SDL_RenderCopy(render, Start, &B1srcRect, &B1destRect); //start
		SDL_RenderCopy(render, Instructions, &B2srcRect, &B2destRect); //instructions
		SDL_RenderCopy(render, Exit, &B3srcRect, &B3destRect); //exit
	}
	
	if (State == 3)
	{
		std::ifstream myFile("score.txt");
		if (myFile.is_open())
		{
			SDL_DestroyTexture(Score);
			while (getline(myFile, Line))
			{
				std::string str = Line;
				cstr = str.c_str();
				TTF_SizeText(Score_f, cstr, &w, &h);
				Message_rect.x = ((900 - Message_rect.w) / 2);
				Message_rect.w = w;
				Message_rect.h = h;
				surfaceMessage = TTF_RenderText_Solid(Score_f, cstr, color);
				SDL_BlitSurface(surfaceMessage, NULL, screen, NULL);
				Score = SDL_CreateTextureFromSurface(render, surfaceMessage); //final score
				SDL_RenderCopy(render, Score, NULL, &Message_rect);
				SDL_FreeSurface(surfaceMessage);
			}
		}
		myFile.close();
		SDL_RenderCopy(render, BTM, &B4srcRect, &B4destRect); //back to menu
	}

}

void Menu::Init(SDL_Renderer* render)
{
	Start = TextureManager::LoadTexture(render, "assets/Start.png");
	Instructions = TextureManager::LoadTexture(render, "assets/Instructrions.png");
	Exit = TextureManager::LoadTexture(render, "assets/Exit.png");
	BTM = TextureManager::LoadTexture(render, "assets/BTM.png");
}