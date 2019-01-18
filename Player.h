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
/**
 * Player class, herer will all the character attibutes be decided.
 */
class Player{
    public:
    Player() = delete;
    /*! \brief Creaters the player.
 	*  
 	*@param texture Is the player texture.
 	*@param imageCount Number of images in the character animation grid.
    *@param switchTime How fast should the animation loob be.
	*/
    Player(sf::Texture& texture, sf::Vector2u imageCount, float switchTime);
    ~Player();
    /*! \brief Updates the player position.
 	*  
 	*@param deltaTime Pace the character is moving.
	*/
    void Update(float deltaTime);
    /*! \brief Updates the player position.
 	*  
 	*@param window Game window.
	*/
    void Draw(sf::RenderWindow& window);


	friend class Map;
    
    private:
    sf::Sprite _body;
    sf::Vector2i pos;
	sf::Vector2i bottom, top, rightBottom, rightTop;
    Animation _animation;

	

    float _movementScale = 1;
    sf::Vector2f velocity;
    bool canJump;
    float jumpHight;
    
    unsigned int _row;
    bool _faceRight;
	bool isJumping;
	
};

#endif // !MAP_H