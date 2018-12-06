#include "StageOne.h"
#include <iostream>


StageOne::StageOne(GameDataRef data): _data(data), _player(std::make_unique<Player>( _data->assets.GetTexture("Albin"), sf::Vector2u(3,4), 100))
{
}

StageOne::~StageOne()
{
}

void StageOne::Init()
{
	_background.setTexture(_data->assets.GetTexture("MENU"));
	_data->assets.LoadTexture("Albin", "albinSprite.png");
}

void StageOne::HandleInput()
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

void StageOne::Update(float deltaTime)
{
	
}

void StageOne::Draw(float deltaTime)
{
	_data->window.clear();
	_data->window.draw(_background);
	_player->Update(deltaTime);
	_player->Draw(_data->window);
	_data->window.display();
}
