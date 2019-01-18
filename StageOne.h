#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "DEFINITIONS.h"
#include "State.h"
#include "Game.h"
#include "Map.h"
#include <memory>
#include <vector>
#include "Player.h"
#include "GameOver.h"


/**
*Stage One State. Creatures, map, player gets initialized and starts the first game stage.
*/
class StageOne: public State
{
public:
	StageOne(GameDataRef data);
	~StageOne();
	
	void Init();

	void HandleInput();
	/*! \brief Updates the StageOne.
 	*  
 	*@param deltaTime needs the deltaTime so the objects run at the same pace in different machines.
	 */
	void Update(float deltaTime);
	/*! \brief Updates the StageOne.
 	*  
 	*@param deltaTime needs the deltaTime so the objects run at the same pace in different machines.
	 */
	void Draw(float deltaTime);

private:
	GameDataRef _data;

	sf::Sprite _background;

	std::unique_ptr<Map> _map = std::make_unique<Map>(_data, 32, 147, 22);
	
	sf::View _camera;
	std::vector<std::vector<sf::Vector2i>> _cordinates;
	sf::Music music;
};

