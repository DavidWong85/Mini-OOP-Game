#include "Mouse.h"

void Mouse::Update(Game* game, Menu* menu, Instructions* instructions, Player* player, Element* element, Score* score, SDL_Event event) 
{
	if (event.motion.type == SDL_MOUSEMOTION)
	{
		player->SetX(event.motion.x); //Move with mouse
		player->SetY(event.motion.y);
	}
	switch (event.button.type)
	{
	case SDL_MOUSEBUTTONDOWN:
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			if (player->getMouse() == false) 
			{
				player->setMouse(true);
				if (menu->getState() == 1)
				{
					if (SDL_HasIntersection(&menu->getB1destRect(), &player->getdestRect())) //start button
					{
						game->setplaySound(false);
						element->setSpeed(180);
						element->setCount(0);
						score->setScore(0);
						score->setHealth(4);
						menu->setState(0);
						game->setgameState(1);
					}
					if (SDL_HasIntersection(&menu->getB2destRect(), &player->getdestRect())) //instructions button
					{
						menu->setState(2);
						game->setgameState(2);
					}
					if (SDL_HasIntersection(&menu->getB3destRect(), &player->getdestRect())) //exit button
					{
						game->setgameState(3);
					}
				}
				if (menu->getState() == 2)
				{
					if (SDL_HasIntersection(&menu->getB4destRect(), &player->getdestRect())) //back to menu button
					{
						menu->setState(1);
						game->setgameState(0);
					}
				}
				if (menu->getState() == 3)
				{
					if (SDL_HasIntersection(&menu->getB4destRect(), &player->getdestRect())) //back to menu button
					{
						menu->setState(1);
						game->setgameState(0);
					}
				}

				if (SDL_HasIntersection(&element->getdestRect(), &player->getdestRect())) //clicking circle
				{
					if (player->getType() == element->getType())  //correct color
					{
						element->Update();
						element->setCount(1);
						element->setSpeed(element->getSpeed() - 1);
						score->setScore(score->getScore() + 1);
						Mix_PlayChannel(2, game->getHit(), 0);
					}
					else //wrong color
					{
						element->Update();
						element->setCount(1);
						score->setHealth(score->getHealth() - 1);
						Mix_PlayChannel(2, game->getWrong(), 0);
					}
				}
			}
		}
		break;
	case SDL_MOUSEBUTTONUP:
		{
		    player->setMouse(false);
		}
		break;
	default:
		break;
	}
}