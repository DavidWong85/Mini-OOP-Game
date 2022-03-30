#include "Player.h"

Player::Player() {}

Player::Player(int x, int y, int _WindowSize) 
{
	xpos = x;
	ypos = y;
}

Player::~Player() {}

void Player::Init(SDL_Renderer* render)
{
	red = TextureManager::LoadTexture(render, "assets/Cursor(red).png");
	blue = TextureManager::LoadTexture(render, "assets/Cursor(blue).png");
	brown = TextureManager::LoadTexture(render, "assets/Cursor(brown).png");
	green = TextureManager::LoadTexture(render, "assets/Cursor(green).png");
	currentTexture = red;
}

int Player::GetX() 
{
	return xpos;
}
void Player::SetX(int _x) 
{
	xpos = _x;
}
int Player::GetY() 
{
	return ypos;
}
void Player::SetY(int _y) 
{
	ypos = _y;
}

void Player::Update() 
{
	srcRect.h = 500;
	srcRect.w = 500;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = srcRect.h / 10;
	destRect.w = srcRect.w / 10;

	switch (Type)
	{
	case 1:
		currentTexture = red;
		break;
	case 2:
		currentTexture = blue;
		break;
	case 3:
		currentTexture = brown;
		break;
	case 4:
		currentTexture = green;
		break;
	default:
		break;
	}
}

void Player::Render(SDL_Renderer* render) 
{
	SDL_RenderCopy(render, currentTexture, &srcRect, &destRect);
}