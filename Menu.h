#pragma once

#include "DEFINITIONS.h"
#include "State.h"
#include "Game.h"
#include <iostream>

class Menu :public State
{
public:
	Menu(GameDataRef data);
	~Menu();


	void Init();

	void HandleInput();
	void Update(float deltaTime);
	void Draw(float deltaTime);
private:
	GameDataRef _data;


	sf::Sprite _background;
	sf::Sprite _title;
	sf::Sprite _playButton;
};

