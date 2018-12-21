#ifndef COLLISION_H
#define COLLISION_H


#include <SFML/Graphics.hpp>
#include <iostream>



class Collision
{
public:
	Collision();
	~Collision();

	bool CheckSpriteCollision(sf::Vector2i bottom, std::vector<std::vector<sf::Vector2i>> cordinates);
private:
};
#endif // !COLLISION_H