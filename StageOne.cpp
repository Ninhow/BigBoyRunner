#include "StageOne.h"
#include <iostream>


StageOne::StageOne(GameDataRef data)
: _data(data), _player(std::make_unique<Player>( _data->assets.GetTexture("Albin"),
 sf::Vector2u(3,4), 100)), _collision(std::make_unique<Collision>())
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

	_cordinates = _map.get()->loadTextures("Map.txt");
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
{	auto collisionDetected= _collision.get()->CheckSpriteCollision(_player->bottom, _cordinates);
	_player->Update(deltaTime, collisionDetected);


	if (collisionDetected){
		
	}
/*
	std::cout << "Matrix x: "<< _cordinates[_player->pos.y][_player->pos.x].x << " Matrix y: " << _cordinates[_player->pos.y][_player->pos.x].y << std::endl;
	if(_cordinates[_player->pos.y][_player->pos.x].x != -1  && _cordinates[_player->pos.y][_player->pos.x].y != -1){
		std::cout << "COLLISION!" << std::endl;
	}*/


}

void StageOne::Draw(float deltaTime)
{
	_data->window.clear();
	_data->window.draw(_background);
	_map->DrawMap(_cordinates);
	_player->Draw(_data->window);
	_data->window.display();
}
