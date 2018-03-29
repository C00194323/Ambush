#pragma once
#include "SDL2\include\SDL.h"
#include "SDL2\include\SDL_image.h"
#include "SDL2\include\SDL_ttf.h"
#include "EventListener.h"
#include "InputManager.h"
#include "GameTime.h"
//#include "Graph.h"
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "WorldMap.h"

const float GameTick = 0.2f;

//typedef GraphArc<std::pair<std::string, int>, int> Arc;
//typedef GraphNode<std::pair<std::string, pair<int, int>>, int> Node;

//void visit(Node * node) {
//
//	std::cout << "Visiting: " << node->data().first << std::endl;
//}

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
	WorldMap* gameWorld;

	float lastUpdate = 0.0f;
	float currentUpdate = 0.0f;
	GameTime* gameTime;

};

