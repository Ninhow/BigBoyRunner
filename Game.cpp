#include "Game.h"
#include "IntroState.h"


Game::Game(int width, int height, std::string title)
{
	_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	
	_data->machine.AddState(StateRef(new IntroState(_data)));
	Run();
}


Game::~Game()
{
}

void Game::Run()
{
	float newTime, frameTime, interpolation;
	float currentTime = _clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	while (_data->window.isOpen())
	{
		_data->machine.ProcessStateChange();
		newTime = _clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;

		if (frameTime > 0.25f)
		{
			frameTime = 0.25f;
		}

		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= _deltaTime)
		{
			_data->machine.GetActiveState()->HandleInput();
			_data->machine.GetActiveState()->Update(_deltaTime);

			accumulator -= _deltaTime;
		}

		interpolation = accumulator / _deltaTime;
		_data->machine.GetActiveState()->Draw(interpolation);
		
	}
}
