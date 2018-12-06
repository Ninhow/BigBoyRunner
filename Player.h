#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <memory>
#include "Animation.h"
#include "Collision.h"

class Player{
    public:
    Player() = delete;
    Player(sf::Texture& texture, sf::Vector2u imageCount, float switchTime);
    ~Player();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);

	Collision GetCollision() { return Collision(body); }
    private:
    sf::Clock _clock;
    Animation _animation;
    sf::RectangleShape body;
    unsigned int _row;
    bool _faceRight;
	/*LÅT PLAYER VARA FÖR SIG... INGEN DATA INGENTING... BARA SJÄLVA SPELARE*/

};

#endif // !MAP_H