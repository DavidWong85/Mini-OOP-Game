#pragma once
#include "Game.h"

class Game;
class Player;
class Element;
class Score;

class Keyboard {
public:
	void Update(Game* game, Player* player, Element* element, Score* score, SDL_Event event);
};