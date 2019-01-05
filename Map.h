#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
#include <memory>
#include "Game.h"
#include "State.h"
#include "Player.h"
#include <fstream>
#include <cctype>
#include <string>
#include <vector>


struct Tile
{
	sf::Vector2i pos;
	int collide = 0;
};


class Map{


    public:
    Map() = delete;
    Map(GameDataRef data, int tileWidth, int nTilesW, int nTilesH);

    void Init();
	void DrawMap(float deltaTime);
	void update(float deltaTime);
    //returna vektorn här så blir det betydligt enklare!
    std::vector<std::vector<sf::Vector2i>> loadTextures(std::string fileName);

	/* test */

	int toIndex(int x, int y);

	int toIndex(sf::Vector2i vec);
	   	  
	sf::Vector2f vel, acc;
	friend class StageOne;
	
    private:
    sf::Clock _clock;
    GameDataRef _data;
	Tile tile;
	std::vector<Tile> tilesMap;
	sf::Sprite _tiles;
	std::vector<int> tilesCord;
	int _tileWidth, _nTilesW, _nTilesH;
	std::unique_ptr<Player> _player;
	sf::View _camera;
};

#endif // !MAP_H