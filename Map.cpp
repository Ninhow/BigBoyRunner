#include "Map.h"
#include <iostream>
Map::Map(GameDataRef data): _data(data){

}

void Map::Init(){
    _data->assets.LoadTexture("MapTiles", "forestiles.png");
    _tiles.setTexture(_data->assets.GetTexture("MapTiles"));
}

//GÖR OM TILL 1 VECTOR OCH LÄS BÄTTRE!!
std::vector<std::vector<sf::Vector2i>> Map::loadTextures(std::string fileName){
    std::ifstream file(fileName);
    std::vector<std::vector<sf::Vector2i>> map;
	std::vector<sf::Vector2i> tempMap;
    if (file.is_open())
	{
		while (!file.eof())
		{
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
			}
		}
	}
    return map;
}


void Map::DrawMap(std::vector<std::vector<sf::Vector2i>> map){
    //auto view = _data->window.getView();
    
    //_data->window.clear();

    for (unsigned int i = 0; i < map.size(); i++)
    {
        for (unsigned int j = 0; j < map[i].size(); j++)
        {
            if (map[i][j].x != -1 && map[i][j].y != -1)
            {	//window.setView(window.getDefaultView());
                _tiles.setPosition(j * 32, i * 32);
                _tiles.setTextureRect(sf::IntRect(map[i][j].x * 32, map[i][j].y * 32, 32, 32));
                _data->window.draw(_tiles);
            }
        }
    }
    //_data->window.display();

}
