#include "WorldMap.h"

void WorldMap::init(TextureLoader * t, SDL_Renderer * render)
{
	//Loading in Tiles
	if (width && height > 200)
	{
		t->addTexture("Wall", "Resources/32/Wall.png", render);
		t->addTexture("Grass", "Resources/32/Grass.png", render);
		pos = { 0,0,32,32 };
	}
	else
	{
		t->addTexture("Wall", "Resources/64/Wall.png", render);
		t->addTexture("Grass", "Resources/64/Grass.png", render);
		pos = { 0,0,64,64 };
	}

	World.resize(width);
	for (int i = 0; i < width; i++)
	{
		World[i].resize(height);
	}

	for (int i = 0; i<width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			//Border Walls

			World[0][j] = 1;

			//Left Side
			World[i][0] = 1;

			//Right Side
			World[i][width - 1] = 1;

			//bottom
			World[height - 1][j] = 1;

			if (World[i][j] != 1)
			{
				World[i][j] = 2;
			}
		}
	}
	//Obstacles
	CreateObstacles();

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			std::cout << World[i][j];
		}
		std::cout << std::endl;
	}
	textureLoader = t;
}

void WorldMap::Render(SDL_Renderer * render)
{
	for (int i = 0; i<World.size(); i++)
	{
		for (int j = 0; j < World.at(i).size(); j++)
		{
			if (width && height > 200)
			{
				pos = { 32 * i, 32 * j, 32, 32 };
			}
			else
			{
				pos = { 64 * i, 64 * j, 64, 64 };

			}
			if (World.at(j).at(i) == 1)
			{
				Renderworld(textureLoader->getTexture("Wall"), render);
			}
			if (World.at(j).at(i) == 2)
			{
				Renderworld(textureLoader->getTexture("Grass"), render);
			}
		}
	}
}

void WorldMap::Renderworld(SDL_Texture *t, SDL_Renderer *r)
{
	SDL_SetTextureBlendMode(t, SDL_BLENDMODE_ADD);
	SDL_RenderCopy(r, t, NULL, &pos);
}

void WorldMap::CreateObstacles()
{
	//Obstacles

	// 3 walls with 1 touching the edge
	if (width == 30 && height == 30)
	{
		for (int i = 0; i < World.size() - 3; i++)
		{
			World[i][height / 6] = 1;

			for (int j = 4; j < World.size() - 4; j++)
			{
				World[j - 2][height / 3] = 1;
				World[j][height / 2] = 1;
			}
		}
	}

	// 6 walls with 2 touching the edge
	if (width == 100 && height == 100)
	{
		for (int i = 0; i < World.size() - 3; i++)
		{
			World[i][height / 14] = 1;
			World[i][height / 1.9] = 1;

			for (int j = 4; j < World.size() - 4; j++)
			{
				World[j-3][height/8] = 1;
				World[j-2][height / 2.7] = 1;
				World[j-4][height / 5] = 1;
				World[j-3][height/1.4] = 1;
			}
		}
	}

	// 18 walls with 4 touching the edge
	if (width == 1000 && height == 1000)
	{
		for (int i = 0; i < World.size() - 3; i++)
		{
			World[i][height / 6] = 1;

			for (int j = 4; j < World.size() - 4; j++)
			{
				World[j - 2][height / 3] = 1;
				World[j][height / 2] = 1;
			}
		}
	}
}
