#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <map>
#include <iostream>

using namespace std;

class TextureLoader
{
private:
	static TextureLoader * TLInstance;
	map<string, SDL_Texture*> Textures;

	TextureLoader()
	{
		Textures = map<string, SDL_Texture*>();
	};

	SDL_Surface * image;
	SDL_Texture * loadTexture;

public:
	void addTexture(string Tag, char * Path, SDL_Renderer * Renderer);

	SDL_Texture * getTexture(string Tag);

	static TextureLoader * Instance()
	{
		if (!TLInstance)
		{
			TLInstance = new TextureLoader;
		}

		return TLInstance;
	}
};
