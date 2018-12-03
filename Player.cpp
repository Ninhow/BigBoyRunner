#include "Player.h"

Player::Player(GameDataRef data) : _data(data){
    _data->assets.LoadTexture("Albin", "albinSprite.png");
    _row = 0;
    _faceRight = true;
    body.setSize(sf::Vector2f(100.0f, 150.0f));
    body.setPosition(206.0f, 206.0f);
    body.setTexture(&_data->assets.GetTexture("Albin"));


}
Player::~Player(){

}
void Player::Update(float deltaTime){
    sf::Vector2f movement (0.0f, 0.0f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        movement.x -= 2 * deltaTime;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        movement.x += 2 * deltaTime;
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
    movement.y += 981.00 * deltaTime;
    body.move(movement * deltaTime);
}
void Player::Init(){

    
}
void Player::Draw(){
    _data->window.draw(body);
}