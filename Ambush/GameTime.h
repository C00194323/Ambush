#pragma once
class GameTime
{
public:
	static GameTime* getInstance();
	float running();
	~GameTime();
protected:
	GameTime();//constructor
private:
	static GameTime* instance;
	static float total; //total game time
};

