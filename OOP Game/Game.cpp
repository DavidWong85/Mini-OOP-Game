#include "Game.h"

Game::Game() {}
Game::~Game() {}

void Game::Init(const char* title, int xpos, int ypos, int width, int height) 
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		TTF_Init();
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
		Mix_VolumeMusic(30); //reduce BGM volume.
		BGM = Mix_LoadMUS("assets/BGM.mp3");
		Hit = Mix_LoadWAV("assets/Click.wav");
		Wrong = Mix_LoadWAV("assets/Wrong.wav");
		std::cout << "Subsystem Initialised" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, 0);
		if (window)
		{
			std::cout << "Window created" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}
		isRunning = true;
	}
	
	SDL_ShowCursor(SDL_DISABLE);
	WindowSize = height;
	m_menu = new Menu();
	m_instructions = new Instructions();
	m_element = new Element(0, 0, WindowSize);
	m_player = new Player(0, 0, WindowSize);
	m_score = new Score(0, 0, WindowSize);

	m_menu->Init(renderer);
	m_instructions->Init(renderer);
	m_player->Init(renderer);
	m_element->Init(renderer);
	
}

void Game::HandleEvents() 
{
	SDL_PollEvent(&event);
}

void Game::Update(Game* game) 
{
	m_mouse->Update(game, m_menu, m_instructions, m_player, m_element, m_score, event);
	m_keyboard->Update(game, m_player, m_element, m_score, event);
	//Start
	if (gameState == 1)
	{
		if (playBGM == false)
		{
			playBGM = true;
			Mix_PlayMusic(BGM, -1);
		}
		m_score->Update(game ,m_menu);
		if (m_element->getCount() % m_element->getSpeed() == 0)
		{
			if (playSound == true)
			{
				Mix_PlayChannel(2, Wrong, 0);
			}

			if (playSound == false)
			{
				playSound = true;
			}
			m_score->setHealth(m_score->getHealth() - 1);
			m_element->Update();
			m_element->setCount(1);
		}
		m_element->setCount(m_element->getCount() + 1);
	}
	//Exit
	if (gameState == 3)
	{
		setRunning(false);
	}
	//Final Score Menu
	if (gameState == 4)
	{
		playBGM = false;
		Mix_HaltMusic();
		gameState = 0;
	}
	m_player->Update();
}

void Game::Render() 
{
	SDL_RenderClear(renderer);
	//Menu
	if (gameState == 0)
	{
		m_menu->Render(renderer);
	}
	//Start
	if (gameState == 1)
	{
		m_score->Render(renderer);
		m_element->Render(renderer);
	}
	//Instructions
	if (gameState == 2)
	{
		m_instructions->Render(renderer, m_menu);
	}
	m_player->Render(renderer);
	SDL_RenderPresent(renderer);
}

void Game::Clean() 
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}
