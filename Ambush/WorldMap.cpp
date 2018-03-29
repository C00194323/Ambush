#include "WorldMap.h"

void WorldMap::init()
{
	
	World.resize(width);
	for (int i = 0; i < width; i++)
	{
		World[i].resize(height);
	}

	for (int i = 0; i<width; i++)
	{
		for (int j = 0; j<height; j++)
		{
			//Border Walls
			World[0][i] = 1;
			World[i][0] = 1;
			World[j][height - 1] = 1;
			World[width - 1][j] = 1;
		}
	}

	//Obstacles
	for (int i = 0; i < width*7/8; i++)
	{
		World[i+1][width / 5] = 2;
	}

	for (int i = 0; i<World.size(); i++)
	{
		for (int j = 0; j<World.at(i).size(); j++)
		{
			if (World.at(i).at(j) == 1)
			{
				
			}
			std::cout << World[i][j];
		}
		std::cout << std::endl;
	}
}

void WorldMap::Renderworld()
{
	
}
