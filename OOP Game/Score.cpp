#include "Score.h"

Score::Score() { }

Score::Score(int x, int y, int _WindowSize) 
{
	arial = TTF_OpenFont("assets/arial.ttf", 30);
	xpos = x;
	ypos = y;
	Message_rect.x = 0;  //controls the rect's x coordinate 
	Message_rect.y = 0; // controls the rect's y coordinte
	Message_rect.w = 0; // controls the width of the rect
	Message_rect.h = 0; // controls the height of the rect

	Message2_rect.x = 750;
	Message2_rect.y = 0;
	Message2_rect.w = 0;
	Message2_rect.h = 0;
}
Score::~Score() {}

void Score::Update(Game*game, Menu* menu)
{
	if (Health != 0)
	{
		std::ofstream myfile, my2file;
		myfile.open("score.txt");
		myfile << " Score : " << CurrentScore;
		myfile.close();

		my2file.open("Health.txt");
		my2file << " Health : " << Health;
	}
	if (Health == 0)
	{
		std::ofstream myfile;
		myfile.open("score.txt");
		myfile << "Your Final Score : " << CurrentScore;
		myfile.close();
		game->setgameState(4);
		menu->setState(3);
	}
}

void Score::Render(SDL_Renderer* render) 
{
	
	std::ifstream myFile("score.txt");
	std::ifstream my2File("Health.txt");
	if (myFile.is_open()) 
	{
		SDL_DestroyTexture(Message);
		while (getline(myFile, Line)) 
		{
			std::string str = Line;
			cstr = str.c_str();
			TTF_SizeText(arial, cstr, &w, &h);
			Message_rect.w = w;
			Message_rect.h = h;
			surfaceMessage = TTF_RenderText_Solid(arial, cstr, color);
			SDL_BlitSurface(surfaceMessage, NULL, screen, NULL);
			Message = SDL_CreateTextureFromSurface(render, surfaceMessage);
			SDL_RenderCopy(render, Message, NULL, &Message_rect);
			SDL_FreeSurface(surfaceMessage);
		}
		SDL_DestroyTexture(Message);
		if (my2File.is_open())
		{
			while (getline(my2File, Line))
			{
				std::string str = Line;
				cstr = str.c_str();
				TTF_SizeText(arial, cstr, &w, &h);
				Message2_rect.w = w;
				Message2_rect.h = h;
				surfaceMessage = TTF_RenderText_Solid(arial, cstr, color);
				SDL_BlitSurface(surfaceMessage, NULL, screen, NULL);
				Message = SDL_CreateTextureFromSurface(render, surfaceMessage);
				SDL_RenderCopy(render, Message, NULL, &Message2_rect);
				SDL_FreeSurface(surfaceMessage);
			}
			myFile.close();
			my2File.close();
		}
	}
	else std::cout << "Unable to open file" << std::endl;
	
}