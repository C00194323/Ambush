#ifndef _EVENTLISTENER_H_
#define _EVENTLISTENER_H_

#pragma once
#include <iostream>
#include <list>

class EventListener
{

public:
	EventListener() {};
	~EventListener() {};

	bool CON_CONNECTED = false;
	bool RETURN = false;
	bool W = false;
	bool A = false;
	bool S = false;
	bool D = false;
	bool LEFTSHIFT = false;
	bool SPACE = false;
	bool ESCAPE = false;
	bool UP = false;
	bool DOWN = false;
	bool LEFT = false;
	bool RIGHT = false;
	bool NUM_0 = false;
	bool NUM_1 = false;
	bool NUM_2 = false;
	bool NUM_3 = false;
	bool NUM_4 = false;
	bool NUM_5 = false;
	bool NUM_6 = false;
	bool NUM_7 = false;
	bool NUM_8 = false;
	bool NUM_9 = false;
	bool PERIOD = false;
	bool BACKSPACE = false;
	bool LEFTMOUSE = false;
	bool RIGHTMOUSE = false;
	bool WHEELCLICK = false;
	bool CON_A = false;
	bool CON_B = false;
	bool CON_X = false;
	bool CON_Y = false;
	bool CON_BACK = false;
	bool CON_START = false;
	bool CON_UP = false;
	bool CON_DOWN = false;
	bool CON_LEFT = false;
	bool CON_RIGHT = false;
	bool CON_RIGHTSHOULDER = false;
	bool CON_LEFTSHOULDER = false;
	bool CON_LEFTTRIGGER = false;
	bool CON_RIGHTTRIGGER = false;
	bool CON_LEFTANALOGUEUP = false;
	bool CON_LEFTANALOGUEDOWN = false;
	bool CON_LEFTANALOGUELEFT = false;
	bool CON_LEFTANALOGUERIGHT = false;
	bool CON_RIGHTANALOGUEUP = false;
	bool CON_RIGHTANALOGUEDOWN = false;
	bool CON_RIGHTANALOGUELEFT = false;
	bool CON_RIGHTANALOGUERIGHT = false;
	



	int mouseX;
	int mouseY;

};
#endif