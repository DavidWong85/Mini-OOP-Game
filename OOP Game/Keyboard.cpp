#include "Keyboard.h"

bool keystate = false;
void Keyboard::Update(Game* game, Player* player, Element* element, Score* score, SDL_Event event)
{
	if (event.type == SDL_KEYDOWN) 
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_1:
			if (player->getKeyboard() == false) //red
			{
				player->setKeyboard(true);
				player->setType(1);
			}
			break;
		case SDLK_2:
			if (player->getKeyboard() == false) //blue
			{
				player->setKeyboard(true);
				player->setType(2);
			}
			break;
		case SDLK_3:
			if (player->getKeyboard() == false) //brown
			{
				player->setKeyboard(true);
				player->setType(3);
			}
			break;
		case SDLK_4:
			if (player->getKeyboard() == false) //green
			{
				player->setKeyboard(true);
				player->setType(4);
			}
			break;
		case SDLK_SPACE:
			if (player->getKeyboard() == false) //click
			{
				player->setKeyboard(true);
				if (SDL_HasIntersection(&element->getdestRect(), &player->getdestRect())) 
				{
					if (player->getType() == element->getType()) 
					{
						element->Update();
						element->setCount(1);
						element->setSpeed(element->getSpeed() - 1);
						score->setScore(score->getScore() + 1);
					}
					else 
					{
						element->Update();
						element->setCount(1);;
						score->setHealth(score->getHealth() - 1);
					}
				}
			}
			break;
		default:
			break;
		}
	}

	if (event.type == SDL_KEYUP)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_1:
			player->setKeyboard(false);
			break;
		case SDLK_2:
			player->setKeyboard(false);
			break;
		case SDLK_3:
			player->setKeyboard(false);
			break;
		case SDLK_4:
			player->setKeyboard(false);
			break;
		case SDLK_SPACE:
			player->setKeyboard(false);
			break;
		default:
			break;
		}
	}
}