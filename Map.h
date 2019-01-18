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
#include <SFML/Audio.hpp>
/**
*	Struct with tile informations that are needed for collision and debuging.
*/
struct Tile
{
	sf::Vector2i pos; /**< Vector with x and y position. */
	int collide = 0;  /**< Does a tile have collision or not. */
};

/**
*	Map class where the game levels will be created and with help of other classes create the game inviroment.
*/

class Map{


    public:
    Map() = delete;
	/*! \brief Updates the menu frames.
 	*  
 	*@param data Variable that links all the engine parts to each other.
	*@param tileWidth Tile size.
	*@param nTilesW Width of the map.
	*@param nTilesH Height of the map.
	*/
    Map(GameDataRef data, int tileWidth, int nTilesW, int nTilesH);
	/*! \brief Initializes all the needed parts of the map.
 	*
	*/
    void Init();
	/*! \brief Updates the menu frames.
 	*  
 	*@param deltaTime Pace timing.
	*/
	void DrawMap(float deltaTime);
	/*! \brief Updates the menu frames.
 	*  
 	*@param deltaTime Pace timing.
	*@param window Reference to the game window.
	*/
	void update(float deltaTime, sf::RenderWindow &window);
	/*! \brief Updates the menu frames.
 	*  
 	*@param deltaTime Pace timing.
	*/
   	void loadTextures(std::string fileName);
	/*! \brief Transforms x and y intro the right the index of the tile map vector.
 	*  
 	*@param x X-axis coordinate.
	*@param y Y-axis coordinate
	*/
	int toIndex(int x, int y);
	/*! \brief Updates the player collision with the map.
	*/
	void collision();
	/*! \brief Spawn all the burgers based on the tile map.
 	*  
 	*@param deltaTime Pace timing.
	*/
	void CPburgers();
	/*! \brief Transforms a vector coordinate into the vector index och the tile map.
 	*  
 	*@param vec Coordinate vector.
	*/
	int toIndex(sf::Vector2i vec);
	/*! \brief Get map size.
 	*  
	*/
	sf::Vector2f GetSize() const;

	/*! \brief Checks if the game has ended.
	*
	*/
	void EndGame();

	   	  
	
	friend class StageOne;
	
    private:
    sf::Clock _clock;
    GameDataRef _data;

	sf::Sprite _tiles;
	sf::Vector2f vel, acc;
	sf::Sprite _burgers;
	int burger = 0;
	bool _gameOver = false;
	std::vector<Tile> tilesMap;
	
	std::vector<int> tilesCord;

	int _tileWidth, _nTilesW, _nTilesH;

	std::unique_ptr<Player> _player;

	sf::View _camera;


	sf::Sound _bigBoy;
};

#endif // !MAP_H