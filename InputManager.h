#pragma once
#include <SFML/Graphics.hpp>

/** \brief Gets mouse button Inputs.
*  
*
*/
class InputManager
{
public:
	InputManager();
	~InputManager();
	/*! \brief Checks if a specific sprite have been clicked.
 	*  
 	*@param object Sprite to be clicked.
	*@param SecondParameter wich button click
	*@param window Game window.
	*/
	bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button, sf::RenderWindow &window);

	/*! \brief Returns the mouse position in the screen.
 	*  
 	*@param window Game window.
	*/
	sf::Vector2i GetMousePosition(sf::RenderWindow &window);
};

