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


class Animation
{
public:
	Animation() = delete;
	Animation(sf::Sprite& texture, sf::Vector2u imageCount, float switchTime);
	~Animation();

	void update(int row, float deltaTime, bool faceRight);

public:

	sf::IntRect uvRect;

private:
	sf::Vector2u _imageCount;
	sf::Vector2u _currentImage;

	float _totalTime;
	float _switchTime;

};

#endif // !ANIMATION_H