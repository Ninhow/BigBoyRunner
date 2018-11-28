#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>



std::ifstream file("Map.txt");

sf::Texture tileTexture;
sf::Sprite tiles;

std::vector<std::vector<sf::Vector2i>> map;
std::vector<sf::Vector2i> tempMap;
tileTexture.loadFromFile("blocks.png");




if (file.is_open())
{
	tileTexture.loadFromFile("blocks.png");
	tiles.setTexture(tileTexture);

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
sf::RenderWindow window(sf::VideoMode(640, 480, 32), "SFML");

while (window.isOpen())
{
	sf::Event evnt;
	while (window.pollEvent(evnt))
	{
		switch (evnt.type) {
		case sf::Event::Closed:
			window.close();
			break;
		}
	}
	window.clear(sf::Color::Cyan);

	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j].x != -1 && map[i][j].y != -1)
			{
				tiles.setPosition(j * 32, i * 32);
				tiles.setTextureRect(sf::IntRect(map[i][j].x * 32, map[i][j].y * 32, 32, 32));
				window.draw(tiles);
			}
		}
	}
	window.display();
}