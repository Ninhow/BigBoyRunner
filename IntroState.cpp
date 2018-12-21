#include "IntroState.h"
#include "DEFINITIONS.h"
#include <iostream>

IntroState::IntroState(GameDataRef data) : _data(data)
{
	_data->assets.LoadTexture("Albin", "albinSprite.png");
	
}


IntroState::~IntroState()
{
}

void IntroState::Init()
{
	_data->assets.LoadTexture("Intro State", INTRO_FILEPATH);

	_background.setTexture(_data->assets.GetTexture("Intro State"));
}

void IntroState::HandleInput()
{
	sf::Event evnt;
	while (_data->window.pollEvent(evnt))
	{
		if (sf::Event::Closed == evnt.type)
		{
			_data->window.close();
		}
	}
}

void IntroState::Update(float deltaTime)
{
	if (_clock.getElapsedTime().asSeconds() > INTRO_STATE_SHOWTIME)
	{
		_data->machine.AddState(StateRef(new Menu(_data)));
	}
}

void IntroState::Draw(float deltaTime)
{
	_data->window.clear();
	_data->window.draw(_background);
	_data->window.display();
}
