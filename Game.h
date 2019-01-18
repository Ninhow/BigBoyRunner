#ifndef GAME_H
#define GAME_H
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "InputManager.h"
#include "AssetManager.h"
/**
*The game engine main access source.
*/
struct GameData {
	StateMachine machine;
	sf::RenderWindow window;
	AssetManager assets;
	InputManager input;
};


using GameDataRef = std::shared_ptr<GameData>;

class Game
{
public:
	/*! \brief Load Tetures.
	*@param width Screen width.
	*@param height Screen height.
	*@param title Screen title.
	*/
	Game(int width, int height, std::string title);
	~Game();

private:

	const float _deltaTime = 1.0f / 60.0f;
	sf::Clock _clock;
	GameDataRef _data = std::make_shared<GameData>();

	void Run();
};
#endif
