#include "Collision.h"

Collision::Collision()
{
}

Collision::~Collision()
{
}

bool Collision::CheckSpriteCollision(sf::Vector2i bottom, std::vector<std::vector<sf::Vector2i>> cordinates)
{
	//std::cout << "Matrix x: "<< cordinates[_player->pos.y][player->pos.x].x << " Matrix y: " << cordinates[_player->pos.y][player->pos.x].y << std::endl;
	if(cordinates[bottom.y][bottom.x].x != -1  && cordinates[bottom.y][bottom.x].y != -1){
		std::cout << "COLLISION!" << std::endl;
		
		return true;
	}	
		
	return false;
}