#include "TextureLoader.h"

TextureLoader * TextureLoader::TLInstance = 0;

void TextureLoader::addTexture(string Tag, char * Path, SDL_Renderer * Renderer)
{
	if (!IMG_Load(Path))
	{
		printf("IMG_Load : %s\n", IMG_GetError());
	}
	else
	{
		image = IMG_Load(Path);
		loadTexture = SDL_CreateTextureFromSurface(Renderer, image);

		Textures[Tag] = loadTexture;
		cout << "Texture " << Tag.c_str() << " successfully loaded" << endl;
	}
}

SDL_Texture * TextureLoader::getTexture(string Tag)
{
	return Textures[Tag];
}