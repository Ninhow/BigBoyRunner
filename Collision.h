#ifndef COLLISION_H
#define COLLISION_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include "DEFINITIONS.h"
#include "Map.h"


class Collision
{
public:
	Collision();
	~Collision();

	bool CheckSpriteCollision(sf::Sprite& body, std::vector<std::vector<sf::Vector2i>>& cordinates);
	size_t toIndex(sf::Vector2i vec);
private:

	sf::Vector2i pos;
	sf::Vector2i bottom, top, rightBottom, rightTop;
	std::unique_ptr<Map> map;
};
#endif // !COLLISION_H