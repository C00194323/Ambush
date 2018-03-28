#pragma once
#include "SDL2\include\SDL.h"
#include "SDL2\include\SDL_image.h"
#include "SDL2\include\SDL_ttf.h"
#include "EventListener.h"
#include "InputManager.h"
#include "GameTime.h"
#include <Windows.h>
#include <iostream>

const float GameTick = 0.2f;

class Game
{
public:
	Game();
	~Game();
	void Run();

private:
	SDL_Window* window = nullptr;
	SDL_Renderer* gameRenderer = nullptr;
	bool gameRunning;
	SDL_Event m_event;

	EventListener * eventListener;
	InputHandler * input;

	float lastUpdate = 0.0f;
	float currentUpdate = 0.0f;
	GameTime* gameTime;

};

