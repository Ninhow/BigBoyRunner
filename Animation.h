#pragma once
#include <SFML/Graphics.hpp>
class Animation
{
public:
	Animation(sf::Texture * texture, sf::Vector2u imageCount, float switchTime);
	~Animation();

	void update(int row, float deltaTime);

private:

public:

	sf::IntRect uvRect;

private:
	sf::Vector2u _imageCount;
	sf::Vector2u _currentImage;

	float _totalTime;
	float _switchTime;

};

