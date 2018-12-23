#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "State.h"
#include "Game.h"
#include "Map.h"
#include <memory>
#include <vector>
#include "Player.h"
#include "Collision.h"

/*
Stage One State. Creatures, map, player gets initialized and starts the first game stage.
*/
class StageOne: public State
{
public:
	StageOne(GameDataRef data);
	~StageOne();
	
	void Init();

	void HandleInput();
	void Update(float deltaTime);
	void Draw(float deltaTime);

private:
	GameDataRef _data;

	sf::Sprite _background;
	sf::View _camera;
	std::unique_ptr<Map> _map = std::make_unique<Map>(_data, 32, 31, 11);
	std::unique_ptr<Player> _player;
	std::unique_ptr<Collision> _collision;
	std::vector<std::vector<sf::Vector2i>> _cordinates;
};

