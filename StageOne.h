#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "State.h"
#include "Game.h"
#include "Map.h"
#include <memory>
#include <vector>
#include "Player.h"
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
	std::unique_ptr<Map> _map = std::make_unique<Map>(_data);
	std::unique_ptr<Player> _player = std::make_unique<Player>(_data);
	std::vector<std::vector<sf::Vector2i>> _cordinates;
};

