#include "Animation.h"



Animation::Animation(sf::Texture * texture, sf::Vector2u imageCount, float switchTime): _imageCount(imageCount), _switchTime(switchTime)
{
	_totalTime = 0.0f;
	_currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}

Animation::~Animation()
{
}

void Animation::update(int row, float deltaTime)
{
	_currentImage.y = row;
	_totalTime += deltaTime;
	if (_totalTime >= deltaTime)
	{
		_totalTime -= _switchTime;
		_currentImage.x++;
		if (_currentImage.x >= _imageCount.x)
		{
			_currentImage.x = 0;
		}
	}

	uvRect.left = _currentImage.x * uvRect.width;
	uvRect.top = _currentImage.y * uvRect.height;
}
