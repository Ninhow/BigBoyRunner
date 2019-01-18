#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Menu.h"

/**
 * Introduction of the game, image for about 2 seconds.
 */
class IntroState:public State
{
public:
	IntroState(GameDataRef data);
	~IntroState();
	/*!
 	* Initializes needed engine parts needed.
 	*/
	void Init();
	/**
 	* Handles Input during this stage
 	*/
	void HandleInput();
	/*! \brief Updates the menu frames.
 	*  
 	*@param deltaTime Pace timing.
	*/
	void Update(float deltaTime);
	/*! \brief Updates the menu frames.
 	*  
 	*@param deltaTime Pace timing.
	*/
	void Draw(float deltaTime);


private:
	GameDataRef _data;

	sf::Clock _clock;

	sf::Texture _backgroundTexture;
	sf::Sprite _background;
	
};

