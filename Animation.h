#ifndef ANIMATION_H
#define ANIMATION_h
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "State.h"
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <memory>

/**
*Animation class for the update of pixels, the class receive pictures of spritesheets and 
*manages the cordinates at the sheet for other classes to be able to update
*/
class Animation
{
public:
	Animation() = delete;
	/*! \brief Animation constructor
	*@param texture Texture sheet.
	*@param imageCount Image count of the texture sheet in the X axis
	*@param switchTime Switch time for every sheet frame.
	*/
	Animation(sf::Sprite& texture, sf::Vector2u imageCount, float switchTime);
	~Animation();
	/*! \brief Updates the character animation.
	*@param row Number of rows in the texture sheet.
	*@param deltaTime Pace time of the game.
	*@param faceRight Checks if the player is facing right or left
	*/
	void update(int row, float deltaTime, bool faceRight);
public:

	//Part of a sprite
	sf::IntRect uvRect;
private:
	sf::Vector2u _imageCount;
	sf::Vector2u _currentImage;

	float _totalTime;
	float _switchTime;

};

#endif // !ANIMATION_H