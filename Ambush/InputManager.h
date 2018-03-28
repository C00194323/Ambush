#ifndef _INPUTHANDLER_H_
#define _INPUTHANDLER_H_

#pragma once
#include <iostream>
#include <vector>
#include "SDL.h"
#include "EventListener.h"

using namespace std;

class InputHandler
{
public:
	InputHandler() {};
	InputHandler(SDL_Event * e, EventListener * ep)
	{
		m_e = e; m_eventlisten = ep;
		m_Rightdirection.x = 0;
		m_Rightdirection.y = 0;

		m_Leftdirection.x = 0;
		m_Leftdirection.y = 0;

		for (int i = 0; i < SDL_NumJoysticks(); i++)
		{
			if (SDL_IsGameController(i))
			{
				controller = SDL_JoystickOpen(i);
				m_eventlisten->CON_CONNECTED = true;
			}
		}

		gControllerHaptic = SDL_HapticOpenFromJoystick(controller);

		if (gControllerHaptic == NULL)
		{
			printf("Warning: Controller does not support haptics! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get initialize rumble
			if (SDL_HapticRumbleInit(gControllerHaptic) < 0)
			{
				printf("Warning: Unable to initialize rumble! SDL Error: %s\n", SDL_GetError());
			}
		}
		if (SDL_HapticRumblePlay(gControllerHaptic, 0.75, 250) != 0)
		{
			printf("Warning: Unable to play rumble! %s\n", SDL_GetError());
		}
	};
	~InputHandler();

	void InputCheck(bool & gameRunning);
	SDL_Point GetRightAnaloguerotation();
	SDL_Point GetLeftAnalogue();
	void PlayShootRumble();
	void PlayWallCollisionRumble();
private:
	SDL_Event * m_e;
	EventListener * m_eventlisten;
	const int DEADZONE = 5000;
	SDL_Joystick *controller = nullptr;
	SDL_Haptic *gControllerHaptic = nullptr;
	SDL_Point m_Rightdirection;
	SDL_Point m_Leftdirection;



};
#endif