#pragma once

#include <map>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
/**
 * Assets Manager class is the class that stores all kind of resources needed for the game.
 */
class AssetManager
{
public:
	AssetManager();
	~AssetManager();
	/*! \brief Load Tetures.
	*@param name Name of the texture for the map storage.
	*@param fileName Name of the texture file.
	*/
	void LoadTexture(std::string name, std::string fileName);
	sf::Texture& GetTexture(std::string name);
	/*! \brief Load Tetures.
	*@param name Name of the font for the map storage.
	*@param fileName Name of the font file.
	*/
	void LoadFont(std::string name, std::string fileName);
	sf::Font& GetFont(std::string name);
	/*! \brief Load Tetures.
	*@param name Name of the sound for the map storage.
	*@param fileName Name of the sound file.
	*/
	void LoadSound(std::string name, std::string fileName);
	sf::SoundBuffer& GetSound(std::string name);


private:
	std::map<std::string, sf::Texture> _textures;
	std::map<std::string, sf::Font> _fonts;
	std::map<std::string, sf::SoundBuffer> _sounds;
};

