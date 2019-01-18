#include "Player.h"
#include <iostream>
#include <math.h>


Player::Player(sf::Texture& texture, sf::Vector2u imageCount, float switchTime) 
:_body(texture), _animation(_body, imageCount, switchTime), canJump(true), jumpHight(100), _row(0), _faceRight(true)
{
    _body.setPosition(206.0f, 206.0f);
}

Player::~Player(){

}

void Player::Update(float deltaTime){

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		velocity.x = 300.2f * _movementScale;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		velocity.x = -300.2f * _movementScale;
	}
	else
	{
		velocity.x = 0.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		
		if (!isJumping)
		{
			velocity.y = -280.f;
			isJumping = 1;
		}
		
	}
	else {
		velocity.y = 0.f;

	}

	//animation
    if(velocity.x == 0.0f){
        _row = 0;
    }else{
        _row = 1;
        if(velocity.x > 0.0f){
            _faceRight = false;
        }else{
            _faceRight = true;
        }
    }

	_animation.update(_row, deltaTime, _faceRight);
	_body.setTextureRect(_animation.uvRect);
	_body.move(velocity * deltaTime);
}

void Player::Draw(sf::RenderWindow& window){
    window.draw(_body);
}