#include "GameOver.h"
#include <iostream>

GameOver::GameOver(GameDataRef data): _data(data){
    sf::View view; 
    view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.5f));
    _data->window.setView(view);
    music.openFromFile("sos.ogg");
    music.play();
}

GameOver::~GameOver(){
    
}

void GameOver::Init(){
    _background.setTexture(_data->assets.GetTexture("gameover"));
    
}

void GameOver::HandleInput(){
    sf::Event evnt;
	while (_data->window.pollEvent(evnt))
	{
		if (sf::Event::Closed == evnt.type)
		{
			_data->window.close();
		}
	}
}

void GameOver::Update(float deltaTime){

}

void GameOver::Draw(float deltaTime){
    _data->window.clear();
	_data->window.draw(_background);
	_data->window.draw(_playButton);
	_data->window.display();
}