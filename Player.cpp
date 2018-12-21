#include "Player.h"
#include <iostream>
#include <math.h>

Player::Player(sf::Texture& texture, sf::Vector2u imageCount, float switchTime) 
:_body(texture), _animation(_body, imageCount, switchTime), _row(0), _faceRight(true), canJump(true), jumpHight(100)
{
    _body.setPosition(206.0f, 206.0f);
}

Player::~Player(){

}

void Player::updatePos(){

    pos = (static_cast<sf::Vector2i>(_body.getPosition()));
    pos /= TILE_WIDTH;

    bottom = pos + sf::Vector2i(0, 1);
    top = pos + sf::Vector2i(0, -1),
	rightBottom = pos + sf::Vector2i(1, 1),
	rightTop = pos + sf::Vector2i(1, -1);

    std::cout << bottom.x << " " << bottom.y << std::endl;
}

//Player Updates, such as movement and also spritesheet update and movimentation,
// deltaTime dependent for the use in different computers
void Player::Update(float deltaTime, bool colide){

    updatePos();
    velocity.x *= 0.5f;

    //std::cout << "after pos: " << pos.x << " " << pos.y << std::endl;

    sf::Vector2f movement (0.0f, 0.0f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        velocity.x -= 200;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        velocity.x += 200;
    }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){

        std::cout << "SPACE PRESSED!" << std::endl;
        canJump = false;
        velocity.y = -sqrtf(2.0f * 981.0f * jumpHight);

        }


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
    if (colide){
        velocity.y = 0.0f;
        canJump = true;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump){

        std::cout << "SPACE PRESSED!" << std::endl;
        canJump = false;
        velocity.y = -sqrtf(2.0f * 981.0f * jumpHight);

        }
    }else{
        velocity.y += 981.00 * deltaTime;
    }

	_animation.update(_row, deltaTime, _faceRight);
	_body.setTextureRect(_animation.uvRect);
	_body.move(velocity * deltaTime);
}

//Draw the player
void Player::Draw(sf::RenderWindow& window){
    window.draw(_body);
}