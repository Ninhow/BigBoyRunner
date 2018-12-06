#include "Player.h"

Player::Player(sf::Texture& texture, sf::Vector2u imageCount, float switchTime) :_animation(texture, imageCount, switchTime){
    
    
    _row = 0;
    _faceRight = true;
    body.setSize(sf::Vector2f(100.0f, 150.0f));
    body.setPosition(206.0f, 206.0f);
    body.setTexture(&texture);


}
Player::~Player(){

}
void Player::Update(float deltaTime){
    sf::Vector2f movement (0.0f, 0.0f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        movement.x -= 1 * deltaTime;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        movement.x += 1 * deltaTime;
    }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		movement.y -= 1 * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		movement.y += 1 * deltaTime;
	}
    if(movement.x == 0.0f){
        _row = 0;
    }else{
        _row = 1;
        if(movement.x > 0.0f){
            _faceRight = true;
        }else{
            _faceRight = false;
        }
    }
    //movement.y += 981.00 * deltaTime;
	_animation.update(_row, deltaTime, _faceRight);
	body.setTextureRect(_animation.uvRect);
	body.move(movement);
}
void Player::Draw(sf::RenderWindow& window){
    window.draw(body);
}