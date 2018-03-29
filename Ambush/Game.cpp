#include "Game.h"
Game::Game()
{
	gameRunning = true;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		exit(0);
	}
	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) < 0)
	{
		printf("SDL_Image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		exit(0);
	}
	if (TTF_Init() < 0)
	{
		printf("SDL_Image could not initialize! SDL_TTF Error: %s\n", TTF_GetError());
		exit(0);
	}
	window = SDL_CreateWindow("Argo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, SDL_WINDOW_SHOWN);

	gameRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawBlendMode(gameRenderer, SDL_BLENDMODE_BLEND);

	//Game Loop
	gameTime->getInstance();
	lastUpdate = gameTime->running();

	eventListener = new EventListener();
	input = new InputHandler(&m_event, eventListener);
	textureHandler = TextureLoader::Instance();

	gameWorld = new WorldMap();
	gameWorld->init(textureHandler, gameRenderer);
}


Game::~Game() {}

void Game::Run()
{
	while (gameRunning)
	{
		input->InputCheck(gameRunning);
		currentUpdate = gameTime->running();
		if ((currentUpdate - lastUpdate) > GameTick)
		{
			std::cout << "Updating ";
			lastUpdate = currentUpdate;
		}
		Sleep(500);//main process sleeps
		std::cout << ".";//alive indicator

		SDL_SetRenderDrawColor(gameRenderer, 0, 0, 0, 255);
		SDL_RenderClear(gameRenderer);
		
		gameWorld->Render(gameRenderer);

		SDL_RenderPresent(gameRenderer);
	}

}
