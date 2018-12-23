#include "Map.h"
#include <iostream>
Map::Map(GameDataRef data, int tileWidth, int nTilesW, int nTilesH): _data(data), _tileWidth(tileWidth), _nTilesW(nTilesW), _nTilesH(nTilesH) {

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



void Map::DrawMap(std::vector<std::vector<sf::Vector2i>> map){
    //auto view = _data->window.getView();
    
    //_data->window.clear();
	/*
    for (unsigned int i = 0; i < map.size(); i++)
    {
        for (unsigned int j = 0; j < map[i].size(); j++)
        {
            if (map[i][j].x != -1 && map[i][j].y != -1)
            {
				tile.pos = sf::Vector2i(j * 32, i * 32);
				_tiles.setTextureRect(sf::IntRect(map[i][j].x * 32, map[i][j].y * 32, 32, 32));
                _tiles.setPosition(j * 32, i * 32);
				tilesMap.push_back(tile);
                _data->window.draw(_tiles);
            }
        }
    }*/


	for (auto t : tilesMap)
	{
		if (t.collide == 1)
		{
			_tiles.setPosition(static_cast<sf::Vector2f>(t.pos));
			_data->window.draw(_tiles);
		}
	}

    //_data->window.display();

}

