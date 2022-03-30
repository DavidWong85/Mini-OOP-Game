#include "Element.h"

Element::Element() {}

Element::Element(int x, int y, int _WindowSize) 
{
	WindowSize = _WindowSize;
	xpos = x;
	ypos = y;
}

Element::~Element() {}

void Element::Update() 
{
	std::uniform_int_distribution<int> dist{ 0, WindowSize - 250 };
	srcRect.h = 500;
	srcRect.w = 500;
	srcRect.x = 0;
	srcRect.y = 0;

	xpos = dist(rd);
	ypos = dist(rd);
	std::uniform_int_distribution<int> type{ 1, 4 };

	if (Speed < 50) 
	{
		Speed = 50;
	}

	switch (type(rd)) 
	{
	case 1:
		//red
		this->type = 1;
		currentTexture = red;
		break;
	case 2:
		//blue
		this->type = 2;
		currentTexture = blue;
		break;
	case 3:
		//brown
		this->type = 3;
		currentTexture = brown;
		break;
	case 4:
		//green
		this->type = 4;
		currentTexture = green;
		break;
	default:
		break;
	}
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = srcRect.h / 5;
	destRect.w = srcRect.w / 5;
}

void Element::Init(SDL_Renderer* render) 
{
	red = TextureManager::LoadTexture(render, "assets/Element(red).png");
	blue = TextureManager::LoadTexture(render, "assets/Element(blue).png");
	brown = TextureManager::LoadTexture(render, "assets/Element(brown).png");
	green = TextureManager::LoadTexture(render, "assets/Element(green).png");
	currentTexture = red;
}

void Element::Render(SDL_Renderer* render) 
{
	SDL_RenderCopy(render, currentTexture, &srcRect, &destRect);
}

