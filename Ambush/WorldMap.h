#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
class WorldMap
{
public:
	WorldMap() { width = 30; height = 30; };
	~WorldMap() {};
	void init();
	void Renderworld();

private:
	std::vector<std::vector<int>> World;
	int width;
	int height;
};

