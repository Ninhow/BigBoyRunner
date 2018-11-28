#include "StageOne.h"



StageOne::StageOne(GameDataRef data): _data(data)
{
}

StageOne::~StageOne()
{
}

void StageOne::Init()
{
	_background.setTexture(_data->assets.GetTexture("MENU"));
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
	_data->window.display();
}
