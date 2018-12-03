#include "StageOne.h"
#include <iostream>


StageOne::StageOne(GameDataRef data): _data(data)
{
}

StageOne::~StageOne()
{
}

void StageOne::Init()
{
	_background.setTexture(_data->assets.GetTexture("MENU"));
	_data->assets.LoadTexture("Albin", "albinSprite.png");
	_map->Init();
	_cordinates = _map->loadTextures("Map.txt");
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
	_map->DrawMap(_cordinates);
	_player->Update(deltaTime);
	_player->Draw();
	_data->window.display();
}
