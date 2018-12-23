#include "StageOne.h"
#include <iostream>


StageOne::StageOne(GameDataRef data)
: _data(data), _player(std::make_unique<Player>( _data->assets.GetTexture("Albin"),
 sf::Vector2u(3,4), 100)), _collision(std::make_unique<Collision>()), _camera(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1024.0f, 768.0f))
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
	_player->Update(deltaTime);
}

void StageOne::Draw(float deltaTime)
{

	_camera.setCenter(_data->window.getSize().x / 2, _data->window.getSize().y / 2);
	_camera.move(_player->_body.getPosition().x - (SCREEN_WIDTH / 2), 0);


	_data->window.clear();
	_data->window.setView(_camera);
	_data->window.draw(_background);
	_map->DrawMap(_cordinates);
	_player->Draw(_data->window);
	_data->window.display();
}
