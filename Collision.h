#pragma once
#include <SFML/Graphics.hpp>
class Collision
{
public:
	Collision(sf::RectangleShape& body);
	~Collision();

	bool CheckSpriteCollision(Collision& other, float push);
	sf::Vector2f GetPosition();
	sf::Vector2f GetHalfSize();
	void Move(float dx, float dy);
private:
	sf::RectangleShape& _body;
};
