#include "Collision.h"

Collision::Collision(sf::RectangleShape& body): _body(body)
{
}

Collision::~Collision()
{
}

bool Collision::CheckSpriteCollision(Collision & other, float push)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.x - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				Move(intersectX * 1.0f - push, 0.0f);
				other.Move(-intersectX * 1.0f - push, 0.0f);
			}
			else {
				Move(-intersectX * 1.0f - push, 0.0f);
				other.Move(intersectX * 1.0f - push, 0.0f);

			}
		}
		
	}
	else
	{
		if (deltaY> 0.0f)
		{
			Move(intersectY * 1.0f - push, 0.0f);
			other.Move(-intersectY * 1.0f - push, 0.0f);
		}
		else {
			Move(0.0f, -intersectY * 1.0f - push);
			other.Move(0.0f, intersectY * 1.0f - push);

		}
	}


	return false;
}

sf::Vector2f Collision::GetPosition()
{
	return sf::Vector2f();
}

sf::Vector2f Collision::GetHalfSize()
{
	return sf::Vector2f();
}

void Collision::Move(float dx, float dy)
{
}
