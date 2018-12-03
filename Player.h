#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "State.h"
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <memory>

class Player{
    public:
    Player() = delete;
    Player(GameDataRef data);
    ~Player();
    void Init();
    void Update(float deltaTime);
    void Draw();


    private:
    sf::Clock _clock;
    GameDataRef _data;
    //Animation _animation;
    sf::RectangleShape body;
    unsigned int _row;
    bool _faceRight;


};

#endif // !MAP_H