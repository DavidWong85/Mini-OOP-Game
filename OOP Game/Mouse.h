#pragma once
#include "Game.h"

class Game;
class Menu;
class Instructions;
class Player;
class Element;
class Score;

class Mouse {
public:
	void Update(Game* game, Menu* menu, Instructions* instructions, Player* player, Element* element, Score* score, SDL_Event event);
private:
	int Mouse_xpos;
	int Mouse_ypos;	
};