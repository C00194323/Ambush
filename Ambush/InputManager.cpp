#pragma once
#include "InputManager.h"

void InputHandler::InputCheck(bool & gameRunning)
{
	while (SDL_PollEvent(m_e) != 0)
	{

		switch (m_e->type)
		{
		case SDL_QUIT:
			gameRunning = false;
			break;
		case SDL_KEYDOWN:
		{
			switch (m_e->key.keysym.sym)
			{
			case SDLK_RETURN:
				m_eventlisten->RETURN = true;
				break;
			case SDLK_ESCAPE:
				m_eventlisten->ESCAPE = true;
				break;
			case SDLK_SPACE:
				m_eventlisten->SPACE = true;
				break;
			case SDLK_a:
				std::cout << "A Pressed" << std::endl;
				m_eventlisten->A = true;
				break;
			case SDLK_d:
				m_eventlisten->D = true;
				break;
			case SDLK_s:
				m_eventlisten->S = true;
				break;
			case SDLK_w:
				m_eventlisten->W = true;
				break;
			case SDLK_UP:
				m_eventlisten->UP = true;
				break;
			case SDLK_DOWN:
				m_eventlisten->DOWN = true;
				break;
			case SDLK_LEFT:
				m_eventlisten->LEFT = true;
				break;
			case SDLK_RIGHT:
				m_eventlisten->RIGHT = true;
				break;
			case SDLK_LSHIFT:
				m_eventlisten->LEFTSHIFT = true;
				break;
			case SDLK_0:
				m_eventlisten->NUM_0 = true;
				break;
			case SDLK_1:
				m_eventlisten->NUM_1 = true;
				break;
			case SDLK_2:
				m_eventlisten->NUM_2 = true;
				break;
			case SDLK_3:
				m_eventlisten->NUM_3 = true;
				break;
			case SDLK_4:
				m_eventlisten->NUM_4 = true;
				break;
			case SDLK_5:
				m_eventlisten->NUM_5 = true;
				break;
			case SDLK_6:
				m_eventlisten->NUM_6 = true;
				break;
			case SDLK_7:
				m_eventlisten->NUM_7 = true;
				break;
			case SDLK_8:
				m_eventlisten->NUM_8 = true;
				break;
			case SDLK_9:
				m_eventlisten->NUM_9 = true;
				break;
			case SDLK_BACKSPACE:
				m_eventlisten->BACKSPACE = true;
				break;
			case SDLK_PERIOD:
				m_eventlisten->PERIOD = true;
				break;
			default:
				break;
			}
			break;
		}

		case SDL_KEYUP:
		{
			switch (m_e->key.keysym.sym)
			{
			case SDLK_RETURN:
				m_eventlisten->RETURN = false;
				break;
			case SDLK_ESCAPE:
				m_eventlisten->ESCAPE = false;
				break;
			case SDLK_SPACE:
				m_eventlisten->SPACE = false;
				break;
			case SDLK_a:
				m_eventlisten->A = false;
				break;
			case SDLK_d:
				m_eventlisten->D = false;
				break;
			case SDLK_s:
				m_eventlisten->S = false;
				break;
			case SDLK_w:
				m_eventlisten->W = false;
				break;
			case SDLK_UP:
				m_eventlisten->UP = false;
				break;
			case SDLK_DOWN:
				m_eventlisten->DOWN = false;
				break;
			case SDLK_LEFT:
				m_eventlisten->LEFT = false;
				break;
			case SDLK_RIGHT:
				m_eventlisten->RIGHT = false;
				break;
			case SDLK_LSHIFT:
				m_eventlisten->LEFTSHIFT = false;
				break;
			case SDLK_0:
				m_eventlisten->NUM_0 = false;
				break;
			case SDLK_1:
				m_eventlisten->NUM_1 = false;
				break;
			case SDLK_2:
				m_eventlisten->NUM_2 = false;
				break;
			case SDLK_3:
				m_eventlisten->NUM_3 = false;
				break;
			case SDLK_4:
				m_eventlisten->NUM_4 = false;
				break;
			case SDLK_5:
				m_eventlisten->NUM_5 = false;
				break;
			case SDLK_6:
				m_eventlisten->NUM_6 = false;
				break;
			case SDLK_7:
				m_eventlisten->NUM_7 = false;
				break;
			case SDLK_8:
				m_eventlisten->NUM_8 = false;
				break;
			case SDLK_9:
				m_eventlisten->NUM_9 = false;
				break;
			case SDLK_BACKSPACE:
				m_eventlisten->BACKSPACE = false;
				break;
			case SDLK_PERIOD:
				m_eventlisten->PERIOD = false;
				break;
			default:
				break;
			}
			break;
		}

		case SDL_MOUSEBUTTONDOWN:
		{
			switch (m_e->button.button)
			{
			case SDL_BUTTON_LEFT:
				m_eventlisten->LEFTMOUSE = true;
				break;
			case SDL_BUTTON_RIGHT:
				m_eventlisten->RIGHTMOUSE = true;
				break;
			case SDL_BUTTON_MIDDLE:
				m_eventlisten->WHEELCLICK = true;
				break;
			default:
				break;
			}
			break;
		}

		case SDL_MOUSEBUTTONUP:
		{
			switch (m_e->button.button)
			{
			case SDL_BUTTON_LEFT:
				m_eventlisten->LEFTMOUSE = false;
				break;
			case SDL_BUTTON_RIGHT:
				m_eventlisten->RIGHTMOUSE = false;
				break;
			case SDL_BUTTON_MIDDLE:
				m_eventlisten->WHEELCLICK = false;
				break;
			default:
				break;
			}
			break;
		}

		case SDL_JOYBUTTONDOWN:
		{
			switch (m_e->cbutton.button)
			{
			case SDL_CONTROLLER_BUTTON_A:
				m_eventlisten->CON_A = true;
				break;
			case SDL_CONTROLLER_BUTTON_B:
				m_eventlisten->CON_B = true;
				break;
			case SDL_CONTROLLER_BUTTON_X:
				m_eventlisten->CON_X = true;
				break;
			case SDL_CONTROLLER_BUTTON_Y:
				m_eventlisten->CON_Y = true;
				break;
			case SDL_CONTROLLER_BUTTON_START:
				m_eventlisten->CON_BACK = true;
				gameRunning = false;
				break;
			case SDL_CONTROLLER_BUTTON_BACK:
				m_eventlisten->CON_BACK = true;
				break;
			case SDL_CONTROLLER_BUTTON_GUIDE:
				m_eventlisten->CON_LEFTSHOULDER = true;
				break;
			case SDL_CONTROLLER_BUTTON_LEFTSTICK:
				m_eventlisten->CON_START = true;
				break;
			default:
				break;
			}
			break;
		}

		case SDL_JOYHATMOTION:
		{
			if (m_e->jhat.value & SDL_HAT_DOWN)
			{
				m_eventlisten->CON_DOWN = true;
			}
			if (m_e->jhat.value & SDL_HAT_UP)
			{
				m_eventlisten->CON_UP = true;
			}
			if (m_e->jhat.value & SDL_HAT_LEFT)
			{
				m_eventlisten->CON_LEFT = true;
			}
			if (m_e->jhat.value & SDL_HAT_RIGHT)
			{
				m_eventlisten->CON_RIGHT = true;
			}
		}

		case SDL_JOYAXISMOTION:
		{
			if (m_e->jaxis.axis == 0)
			{
				if (m_e->jaxis.value < -DEADZONE)
				{
					m_Leftdirection.x = m_e->jaxis.value;
					m_eventlisten->CON_LEFTANALOGUELEFT = true;
				}
				else if (m_e->jaxis.value > DEADZONE)
				{
					m_Leftdirection.x = m_e->jaxis.value;
					m_eventlisten->CON_LEFTANALOGUERIGHT = true;
				}
				else
				{
					m_eventlisten->CON_LEFTANALOGUELEFT = false;
					m_eventlisten->CON_LEFTANALOGUERIGHT = false;
				}
			}
			if (m_e->jaxis.axis == 1)
			{
				if (m_e->jaxis.value < -DEADZONE)
				{
					m_Leftdirection.y = m_e->jaxis.value;
					m_eventlisten->CON_LEFTANALOGUEUP = true;
				}
				else if (m_e->jaxis.value > DEADZONE)
				{
					m_Leftdirection.y = m_e->jaxis.value;
					m_eventlisten->CON_LEFTANALOGUEDOWN = true;
				}
				else
				{
					m_eventlisten->CON_LEFTANALOGUEUP = false;
					m_eventlisten->CON_LEFTANALOGUEDOWN = false;
				}
			}
			if (m_e->jaxis.axis == 2)
			{
				if (m_e->jaxis.value > DEADZONE)
				{
					m_eventlisten->CON_LEFTTRIGGER = true;
				}
				else
				{
					m_eventlisten->CON_LEFTTRIGGER = false;
				}
			}
			if (m_e->jaxis.axis == 3)
			{
				if (m_e->jaxis.value < -DEADZONE)
				{
					m_Rightdirection.x = m_e->jaxis.value;
					m_eventlisten->CON_RIGHTANALOGUELEFT = true;
				}
				else if (m_e->jaxis.value > DEADZONE)
				{
					m_Rightdirection.x = m_e->jaxis.value;
					m_eventlisten->CON_RIGHTANALOGUERIGHT = true;
				}
				else
				{
					m_eventlisten->CON_RIGHTANALOGUELEFT = false;
					m_eventlisten->CON_RIGHTANALOGUERIGHT = true;
				}
			}

			if (m_e->jaxis.axis == 4)
			{
				if (m_e->jaxis.value < -DEADZONE)
				{
					m_Rightdirection.y = m_e->jaxis.value;
					m_eventlisten->CON_RIGHTANALOGUEUP = true;
				}
				else if (m_e->jaxis.value > DEADZONE)
				{
					m_Rightdirection.y = m_e->jaxis.value;
					m_eventlisten->CON_RIGHTANALOGUEDOWN = true;
				}
				else
				{
					m_eventlisten->CON_RIGHTANALOGUEUP = false;
					m_eventlisten->CON_RIGHTANALOGUEDOWN = false;
				}
			}

			if (m_e->jaxis.axis == 5)
			{
				if (m_e->jaxis.value > DEADZONE)
				{
					//cout << m_e->jaxis.value << endl;
					m_eventlisten->CON_RIGHTTRIGGER = true;
				}
				else
				{
					m_eventlisten->CON_RIGHTTRIGGER = false;
				}
			}
			break;
		}

		case SDL_JOYBUTTONUP:
		{
			switch (m_e->jbutton.button)
			{
			case SDL_CONTROLLER_BUTTON_A:
				m_eventlisten->CON_A = false;
				break;
			case SDL_CONTROLLER_BUTTON_B:
				m_eventlisten->CON_B = false;
				break;
			case SDL_CONTROLLER_BUTTON_X:
				m_eventlisten->CON_X = false;
				break;
			case SDL_CONTROLLER_BUTTON_Y:
				m_eventlisten->CON_Y = false;
				break;
			case SDL_CONTROLLER_BUTTON_START:
				m_eventlisten->CON_BACK = true;
				break;
			case SDL_CONTROLLER_BUTTON_BACK:
				m_eventlisten->CON_BACK = true;
				break;
			case SDL_CONTROLLER_BUTTON_GUIDE:
				m_eventlisten->CON_LEFTSHOULDER = true;
				break;
			case SDL_CONTROLLER_BUTTON_LEFTSTICK:
				m_eventlisten->CON_START = true;
				break;
			default:
				break;
			}
			break;
		}

		case SDL_MOUSEMOTION:
		{
			SDL_GetMouseState(&m_eventlisten->mouseX, &m_eventlisten->mouseY);
			break;
		default:
			break;
		}
		}
	}
}

SDL_Point InputHandler::GetRightAnaloguerotation()
{
	SDL_Point rotationDirection;
	rotationDirection.y = m_Rightdirection.y;
	rotationDirection.x = m_Rightdirection.x;
	return rotationDirection;
}

SDL_Point InputHandler::GetLeftAnalogue()
{
	SDL_Point left;
	left.y = m_Leftdirection.y;
	left.x = m_Leftdirection.x;
	return left;
}

void InputHandler::PlayShootRumble()
{
	if (SDL_HapticRumblePlay(gControllerHaptic, 0.4, 100) != 0)
	{
		//printf("Warning: Unable to play rumble! %s\n", SDL_GetError());
	}
}
void InputHandler::PlayWallCollisionRumble()
{
	if (SDL_HapticRumblePlay(gControllerHaptic, 0.1, 150) != 0)
	{
		//printf("Warning: Unable to play rumble! %s\n", SDL_GetError());
	}
}

InputHandler::~InputHandler() {}