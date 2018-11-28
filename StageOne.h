#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "State.h"
#include "Game.h"
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
};

