

#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "DEFINITIONS.h"
#include <SFML/Audio.hpp>



class GameOver :public State{
    public:
    GameOver() = delete;
    GameOver(GameDataRef data);
	~GameOver();

	void Init();
	void HandleInput();
	void Update(float deltaTime);
	void Draw(float deltaTime);


    private:
    GameDataRef _data;
	sf::Sprite _background;
	sf::Sprite _playButton;
	sf::Music music;
};

#endif 