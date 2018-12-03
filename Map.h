#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "State.h"
#include <fstream>
#include <cctype>
#include <string>
#include <vector>

class Map{
    public:
    Map() = delete;
    Map(GameDataRef data);

    void Init();
	void DrawMap(std::vector<std::vector<sf::Vector2i>> map);

    //returna vektorn här så blir det betydligt enklare!
    std::vector<std::vector<sf::Vector2i>> loadTextures(std::string fileName);

    private:
    sf::Clock _clock;
    GameDataRef _data;

	sf::Sprite _tiles;


};

#endif // !MAP_H