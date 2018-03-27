#include "GameTime.h"
#include <Windows.h>
#include <process.h>

GameTime* GameTime::instance = 0;
float GameTime::total = 0.0f;
static const float INCREMENT = 0.1f;
static const int SLEEP = 1000;

void update(void *);

GameTime::GameTime()
{
}

GameTime::~GameTime()
{
}

GameTime* GameTime::getInstance()
{
	if (instance == 0)
	{
		instance = new GameTime();
		_beginthread(update, 0, &GameTime::total);
	}
	return instance;
}

float GameTime::running()
{
	return GameTime::total;
}

void update(void* running)
{
	while (true)
	{
		*((float*)running) += INCREMENT;
		Sleep(SLEEP);//Put process to sleep
	}
}