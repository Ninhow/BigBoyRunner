#pragma once

#include "DEFINITIONS.h"
#include "State.h"
#include "Game.h"
#include <iostream>
/**
 * Menu class, first stage where the player decides to play.
 */
class Menu :public State
{
public:
	Menu(GameDataRef data);
	~Menu();


	void Init();
	/*! \brief Handles mouse input from the player.
 	*  
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


	sf::Sprite _background;
	sf::Sprite _title;
	sf::Sprite _playButton;
};

