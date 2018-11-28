#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Menu.h"


class IntroState:public State
{
public:
	IntroState(GameDataRef data);
	~IntroState();

	void Init();
	void HandleInput();
	void Update(float deltaTime);
	void Draw(float deltaTime);


private:
	GameDataRef _data;

	sf::Clock _clock;

	sf::Texture _backgroundTexture;
	sf::Sprite _background;
};

