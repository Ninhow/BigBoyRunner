#include "Map.h"
#include <iostream>

Map::Map(GameDataRef data, int tileWidth, int nTilesW, int nTilesH):
 _data(data), _tileWidth(tileWidth), _nTilesW(nTilesW), _nTilesH(nTilesH),
 _player(std::make_unique<Player>(_data->assets.GetTexture("Albin"),
 sf::Vector2u(3, 4), 100)), _camera(_player->_body.getPosition(), sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT)){

}

void Map::Init(){
    _data->assets.LoadTexture("tile1", "forestiles2.png");
	_data->assets.LoadTexture("tile2", "tile2.png");
	_data->assets.LoadTexture("tile3", "tile3.png");
}


int Map::toIndex(int x, int y)
{
	return y * _nTilesW + x;
}

int Map::toIndex(sf::Vector2i vec)
{
	return vec.y * _nTilesW + vec.x;
}

//GÖR OM TILL 1 VECTOR OCH LÄS BÄTTRE!!
void Map::loadTextures(std::string fileName){


    std::ifstream file(fileName);
    std::vector<std::vector<sf::Vector2i>> map;
	std::vector<sf::Vector2i> tempMap;

	std::vector<int> tmp1;
    if (file.is_open())
	{
		std::string str;
		while(std::getline(file, str, ','))
		{
			int tmp;

			if (str == "\n1" )
			{
				str = "1";
				tmp = std::stol(str);
			}
			else if (str == "\n"){
				break;
			}
			tmp = std::stol(str);
			tilesCord.push_back(tmp);

		}
	}
	else {
		std::cerr << "File couldn't be opened!" << std::endl;
	}

	for (int y = 0; y < _nTilesH; y++)
	{
		for (int x = 0; x < _nTilesW; x++)
		{

			tilesMap.push_back({ sf::Vector2i(x * _tileWidth, y * _tileWidth),
				tilesCord[toIndex(x, y)]});
		}
	}
}


void Map::update(float deltaTime, sf::RenderWindow &window)
{
	
	acc.y = 0.2;
	vel.y += acc.y;
	_player->_body.move(vel);
	auto bounds = _player->_body.getLocalBounds();
	sf::Vector2f offset(bounds.width, bounds.height);
	_camera.setCenter(_player->_body.getPosition().x + (SCREEN_WIDTH / 3), SCREEN_HEIGHT / 2);
	window.setView(_camera);
	collision();
	_player->Update(deltaTime);
	CPburgers();
}

sf::Vector2f Map::GetSize() const{
	return sf::Vector2f((_tileWidth * _nTilesW), (_tileWidth * _nTilesH) );
}

void Map::collision(){

	auto pos = static_cast<sf::Vector2i>(_player->_body.getPosition());
	pos /= 32;


	sf::Vector2i left = pos + sf::Vector2i(0, 0),
		right = pos + sf::Vector2i(1, 0);

	if (tilesCord[toIndex(left)] > 0 )
	{
		auto newPos = tilesMap[toIndex(left)].pos;
		auto playerPos = _player->_body.getPosition();
		newPos.x += 32;
		_player->_body.setPosition(newPos.x, playerPos.y);
		_player->isJumping = 1;

		if(tilesCord[toIndex(left)] == 5){
			tilesCord[toIndex(left)] = 0;
			tilesMap[toIndex(left)].collide = 0;
			burger++;
			_bigBoy.play();
		}else if(tilesCord[toIndex(left)] > 5){
			EndGame();
		}
	}
	else if (tilesCord[toIndex(right)] > 0)
	{
		auto newPos = tilesMap[toIndex(right)].pos;
		auto playerPos = _player->_body.getPosition();
		newPos.x -= 32;
		_player->_body.setPosition(newPos.x, playerPos.y);

		_player->isJumping = 1;

		if(tilesCord[toIndex(right)] == 5){
			tilesCord[toIndex(right)] = 0;
			tilesMap[toIndex(right)].collide = 0;
			burger++;
			_bigBoy.play();
		}else if(tilesCord[toIndex(right)] > 6){
			EndGame();
		}
	}

	pos = static_cast<sf::Vector2i>(_player->_body.getPosition());
	pos /= 32;

	sf::Vector2i bottom = pos + sf::Vector2i(0, 1),
		top = pos,
		bottomRight = pos + sf::Vector2i(1, 1),
		rightTop = pos + sf::Vector2i(1, 0);

	if (tilesCord[toIndex(bottom)] > 0 || tilesCord[toIndex(bottomRight)] > 0)
	{	

		vel.y = acc.y = 0.f;
		auto newPos = tilesMap[toIndex(bottom)].pos;
		auto playerPos = _player->_body.getPosition();
		newPos.y -= 32;
		_player->_body.setPosition(playerPos.x, newPos.y + 0.5f);

		_player->isJumping = false;


		if(tilesCord[toIndex(bottom)] == 5 ){
			tilesCord[toIndex(bottom)] = 0;
			tilesMap[toIndex(bottom)].collide = 0;
			burger++;
			_bigBoy.play();
		}else if(tilesCord[toIndex(bottomRight)] == 5){
			tilesCord[toIndex(bottomRight)] = 0;
			tilesMap[toIndex(bottomRight)].collide = 0;
			burger++;
			_bigBoy.play();
		}else if(tilesCord[toIndex(bottom)] > 5){
			EndGame();
		}
	}
	else if (tilesCord[toIndex(top)] > 0 || tilesCord[toIndex(rightTop)] > 0)
	{

		auto newPos = tilesMap[toIndex(top)].pos;
		auto playerPos = _player->_body.getPosition();
		newPos.y += 32 + 1;
		_player->_body.setPosition(playerPos.x, newPos.y + 0.5f);

		if(tilesCord[toIndex(top)] == 5){
			tilesCord[toIndex(top)] = 0;
			tilesMap[toIndex(top)].collide = 0;
			burger++;
			_bigBoy.play();
		}else if(tilesCord[toIndex(rightTop)] == 5){
			tilesCord[toIndex(rightTop)] = 0;
			tilesMap[toIndex(rightTop)].collide = 0;
			burger++;
			_bigBoy.play();
		}else if(tilesCord[toIndex(top)] > 5){
			EndGame();
		}
	}
}

void Map::CPburgers(){ 

	switch(burger){
		case 1:
			_player->_movementScale = 1.5f;
		break;

		case 2:
			_player->_movementScale = 2.0f;
		break;

		case 3:
			_player->_movementScale = 2.5f;
		break;

		case 4:
			_player->_movementScale = 3.0f;
		break;
	}

}


void Map::DrawMap( float deltaTime){
	for (auto t : tilesMap)
	{
		switch(t.collide){
			case 1: 
			_tiles.setTexture(_data->assets.GetTexture("tile1"));
			_tiles.setPosition(static_cast<sf::Vector2f>(t.pos));
			_data->window.draw(_tiles);
			break;

			case 2:
			_tiles.setTexture(_data->assets.GetTexture("tile2"));
			_tiles.setPosition(static_cast<sf::Vector2f>(t.pos));
			_data->window.draw(_tiles);
			break;

			case 3:
			_tiles.setTexture(_data->assets.GetTexture("tile3"));
			_tiles.setPosition(static_cast<sf::Vector2f>(t.pos));
			_data->window.draw(_tiles);
			break;

			case 6:
			_tiles.setTexture(_data->assets.GetTexture("big1"));
			_tiles.setPosition(static_cast<sf::Vector2f>(t.pos));
			_data->window.draw(_tiles);
			break;

			case 8:
			_tiles.setTexture(_data->assets.GetTexture("big3"));
			_tiles.setPosition(static_cast<sf::Vector2f>(t.pos));
			_data->window.draw(_tiles);
			break;

			case 9:
			_tiles.setTexture(_data->assets.GetTexture("big4"));
			_tiles.setPosition(static_cast<sf::Vector2f>(t.pos));
			_data->window.draw(_tiles);
			break;

			case 5:
			_burgers.setTexture(_data->assets.GetTexture("burger"));
			_burgers.setPosition(static_cast<sf::Vector2f>(t.pos));
			_data->window.draw(_burgers);
			break;
		}
		
	}
	_data->window.draw(_player->_body);
}

void Map::EndGame(){

	_gameOver = true;
}