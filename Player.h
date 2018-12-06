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

    private:
    sf::Clock _clock;
    Animation _animation;
    sf::Sprite _body;
    unsigned int _row;
    bool _faceRight;
	/*L�T PLAYER VARA F�R SIG... INGEN DATA INGENTING... BARA SJ�LVA SPELARE*/

};

#endif // !MAP_H