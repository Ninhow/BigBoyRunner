#include "Map.h"
#include <iostream>
Map::Map(GameDataRef data, int tileWidth, int nTilesW, int nTilesH): _data(data), _tileWidth(tileWidth), _nTilesW(nTilesW), _nTilesH(nTilesH), _player(std::make_unique<Player>(_data->assets.GetTexture("Albin"),
	sf::Vector2u(3, 4), 100)), _camera(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1024.0f, 768.0f)){

}
//int tileWidth, int nTilesW, int nTilesH
void Map::Init(){
    _data->assets.LoadTexture("MapTiles", "forestiles2.png");
    _tiles.setTexture(_data->assets.GetTexture("MapTiles"));
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
std::vector<std::vector<sf::Vector2i>> Map::loadTextures(std::string fileName){


    std::ifstream file(fileName);
    std::vector<std::vector<sf::Vector2i>> map;
	std::vector<sf::Vector2i> tempMap;

	std::vector<int> tmp1;
    if (file.is_open())
	{
		while (!file.eof())
		{
			std::string newline;
			std::string str;
			std::getline(file, str, ',');
			int tmp;
			if (str == "\n1")
			{
				str = "1";
				tmp = std::stol(str);
			}
			else if (str == "\n"){
				break;
			}
			tmp = std::stol(str);
			tilesCord.push_back(tmp);

			/*
			for (int y = 0; y < _nTilesH; y++)
			{
				for (int x = 0; x < _nTilesW; x++)
				{
					tilesMap.push_back({ sf::Vector2i(x*_tileWidth, y*_tileWidth),
						matrix[toIndex(x, y)] });
				}
			}*/

			/*
			std::string str;
			file >> str;
			if (!isdigit(str[0]) || !isdigit(str[2]))
			{
				tempMap.push_back(sf::Vector2i(-1, -1));
			}
			else {
				tempMap.push_back(sf::Vector2i(str[0] - '0', str[2] - '0'));
			}
			if (file.peek() == '\n')
			{
				map.push_back(tempMap);
				tempMap.clear();
			}*/
		}
	}
	else {
		std::cerr << "File couldn't be opened!" << std::endl;
	}

	for (int y = 0; y < _nTilesH; y++)
	{
		for (int x = 0; x < _nTilesW; x++)
		{

			std::cout << tilesCord[toIndex(x, y)] << std::endl;
			tilesMap.push_back({ sf::Vector2i(x * _tileWidth, y * _tileWidth),
				tilesCord[toIndex(x, y)]});
		}
	}


    return map;
}


void Map::update(float deltaTime)
{
	
	acc.y = 0.2;
	vel.x += acc.x;
	vel.y += acc.y;
	_player->_body.move(vel);


	auto pos = static_cast<sf::Vector2i>(_player->_body.getPosition());
	pos /= 32;

	sf::Vector2i bottom = pos + sf::Vector2i(0, 1),
		top = pos + sf::Vector2i(0, -1),
		rightBottom = pos + sf::Vector2i(1, 1),
		rightTop = pos + sf::Vector2i(1, -1);

	if (tilesCord[toIndex(bottom)] == 1 || tilesCord[toIndex(rightBottom)] == 1)
	{
		vel.y = acc.y = 0.f;
		auto newPos = tilesMap[toIndex(bottom)].pos;
		auto playerPos = _player->_body.getPosition();
		newPos.y -= 32;
		_player->_body.setPosition(playerPos.x, newPos.y);
		_player->isJumping = false;
	}
	else if (tilesCord[toIndex(top)] == 1 || tilesCord[toIndex(rightTop)] == 1)
	{
		//vel.y = acc.y = 0.f;
		auto newPos = tilesMap[toIndex(top)].pos;
		auto playerPos = _player->_body.getPosition();
		newPos.y += 32 + 1;
		_player->_body.setPosition(playerPos.x, newPos.y);
	}


	pos = static_cast<sf::Vector2i>(_player->_body.getPosition());
	pos /= 32;

	sf::Vector2i left = pos + sf::Vector2i(0, 0),
		right = pos + sf::Vector2i(1, 0);

	if (tilesCord[toIndex(left)] == 1)
	{
		auto newPos = tilesMap[toIndex(left)].pos;
		auto playerPos = _player->_body.getPosition();
		newPos.x += 32;
		_player->_body.setPosition(newPos.x, playerPos.y);
		vel.x = 0.f;
	}
	else if (tilesCord[toIndex(right)] == 1)
	{
		auto newPos = tilesMap[toIndex(right)].pos;
		auto playerPos = _player->_body.getPosition();
		newPos.x -= 32;
		_player->_body.setPosition(newPos.x, playerPos.y);
		vel.x = 0.f;
	}

	
	_player->Update(deltaTime);
	auto p = _player->_body.getPosition();
	std::cout << p.x << ' ' << p.y << '\n';
	
}


void Map::DrawMap( float deltaTime){
    	
	
	for (auto t : tilesMap)
	{
		if (t.collide == 1)
		{
			_tiles.setPosition(static_cast<sf::Vector2f>(t.pos));
			_data->window.draw(_tiles);
		}
	}
	_data->window.draw(_player->_body);
	
    //_data->window.display();

}

