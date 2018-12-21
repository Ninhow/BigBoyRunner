#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <memory>
#include "Animation.h"
#include "DEFINITIONS.h"
/*
Player Class with player controls and animation as a komposition


*/
class Player{
    public:
    Player() = delete;
    Player(sf::Texture& texture, sf::Vector2u imageCount, float switchTime);
    ~Player();
    void Update(float deltaTime, bool colide);
    void Draw(sf::RenderWindow& window);
    void updatePos();

     
    friend class StageOne;
    private:
    sf::Sprite _body;
    sf::Vector2i pos;
	sf::Vector2i bottom, top, rightBottom, rightTop;
    Animation _animation;


    sf::Vector2f velocity;
    bool canJump;
    float jumpHight;
    //Number of rows in the spritesheet
    unsigned int _row;
    //WHat site the player is facing, needed for the animation(Try to make a better way later.)
    bool _faceRight;
};

#endif // !MAP_H