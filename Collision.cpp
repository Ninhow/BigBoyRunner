#include "Collision.h"

Collision::Collision()
{
}

Collision::~Collision()
{
}

bool Collision::CheckSpriteCollision(sf::Sprite& body,  std::vector<std::vector<sf::Vector2i>>& cordinates)
{
	pos = (static_cast<sf::Vector2i>(body.getPosition()));
	pos /= TILE_WIDTH;

	bottom = pos + sf::Vector2i(0, 1);
	top = pos + sf::Vector2i(0, -1),
	rightBottom = pos + sf::Vector2i(1, 1),
	rightTop = pos + sf::Vector2i(1, -1);
	sf::Vector2i left = pos + sf::Vector2i(-1, 0),
		right = pos + sf::Vector2i(1, 0);

	std::cout << "first: "<< cordinates[bottom.y][bottom.x].x << std::endl << cordinates[bottom.y][bottom.x].y << std::endl;
	std::cout << "second: " << cordinates[rightBottom.y][rightBottom.x].x << std::endl << cordinates[rightBottom.y][rightBottom.x].y << std::endl;


	if(cordinates[bottom.y][bottom.x].x != -1  && cordinates[bottom.y][bottom.x].y != -1 && cordinates[rightBottom.y][rightBottom.x].x != -1 && cordinates[rightBottom.y][rightBottom.x].y != -1){
		std::cout << "COLLISION" << std::endl;
		return true;
	}else if(cordinates[top.y][top.x].x != -1 && cordinates[top.y][top.x].y != -1 && cordinates[rightTop.y][rightTop.x].x != -1 && cordinates[rightTop.y][rightTop.x].y != -1) {
		
		return true;
	}else if (cordinates[left.y][left.x].x != -1 && cordinates[left.y][left.x].y != -1){
		return true;
	}
	else {
		return false;
	}


	
}