#include "AssetManager.h"



AssetManager::AssetManager()
{
}


AssetManager::~AssetManager()
{
}

void AssetManager::LoadTexture(std::string name, std::string fileName)
{
	sf::Texture texture;
	if (texture.loadFromFile(fileName))
	{
		_textures[name] = texture;
	}
}

sf::Texture & AssetManager::GetTexture(std::string name)
{
	return _textures.at(name);
}

void AssetManager::LoadFont(std::string name, std::string fileName)
{
	sf::Font font;
	if (font.loadFromFile(fileName))
	{
		_fonts[name] = font;
	}
}

sf::Font & AssetManager::GetFont(std::string name)
{
	return _fonts.at(name);
}

void AssetManager::LoadSound(std::string name, std::string fileName){
	sf::SoundBuffer sound;
	if(sound.loadFromFile(fileName)){
		_sounds[name] = sound;
	}

}

sf::SoundBuffer& AssetManager::GetSound(std::string name){


	return _sounds.at(name);
}
