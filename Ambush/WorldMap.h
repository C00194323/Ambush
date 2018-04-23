#pragma once
#include "TextureLoader.h"
#include <iostream>
#include <algorithm>
#include <vector>
class WorldMap
{
public:
	WorldMap() { width = 1000; height = 1000; };
	~WorldMap() {};
	void init(TextureLoader * t, SDL_Renderer * render);
	void Render(SDL_Renderer * render);
	void Renderworld(SDL_Texture * t, SDL_Renderer * r);
	void CreateObstacles();
private:
	std::vector<std::vector<int>> World;
	int width;
	int height;
	TextureLoader* textureLoader;
	SDL_Rect pos;
};

