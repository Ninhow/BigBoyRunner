#include "StageOne.h"
#include <iostream>



StageOne::StageOne(GameDataRef data)
: _data(data){
	music.openFromFile("theme.ogg");
    music.play();
}

StageOne::~StageOne()
{
	music.stop();
}

//Initialize needed systems
void StageOne::Init()
{
	_background.setTexture(_data->assets.GetTexture("MENU"));
	_data->assets.GetTexture("MENU").setRepeated(true);

	_map->_bigBoy.setBuffer(_data->assets.GetSound("bigboy"));
	_map.get()->Init();
	_map.get()->loadTextures("Map2.txt");


	auto texRect = _background.getTextureRect();
	texRect.width = _map->GetSize().x;
	_background.setTextureRect(texRect);
	
	
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
	
	_map->update(deltaTime, _data->window);
	if(_map->_gameOver){
		_data->machine.AddState(StateRef(new GameOver(_data)));
		
		
	}
}

void StageOne::Draw(float deltaTime)
{
	_data->window.clear();
	_data->window.draw(_background);
	_map->DrawMap(deltaTime);
	_data->window.display();
}
