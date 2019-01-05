#include "StageOne.h"
#include <iostream>


StageOne::StageOne(GameDataRef data)
: _data(data)
{
}

StageOne::~StageOne()
{
}

//Initialize needed systems
void StageOne::Init()
{
	_background.setTexture(_data->assets.GetTexture("MENU"));
	_map.get()->Init();

	 _cordinates = _map.get()->loadTextures("Map2.txt");
}

//Handle stage inputs! 
//(Change player so stage handle the input and transfers to player.)
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
//Update Stage
void StageOne::Update(float deltaTime)
{
	
	_map->update(deltaTime);
	//_player->Update(deltaTime);
}

void StageOne::Draw(float deltaTime)
{

	//_camera.setCenter(_data->window.getSize().x / 2, _data->window.getSize().y / 2);
	//.move(_player->_body.getPosition().x - (SCREEN_WIDTH / 2), 0);


	_data->window.clear();
	//_data->window.setView(_camera);
	_data->window.draw(_background);
	_map->DrawMap(deltaTime);
	//_player->Draw(_data->window);
	_data->window.display();
}
