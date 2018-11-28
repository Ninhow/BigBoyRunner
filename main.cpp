#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"
#include "Game.h"
#include "Menu.h"
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
int main() {

	//Game(SCREEN_WIDTH, SCREEN_HEIGHT, "SFML STARTER");
	std::ifstream file("Map.txt");

	

	sf::Texture tileTexture;
	sf::Sprite tiles;

	std::vector<std::vector<sf::Vector2i>> map;
	std::vector<sf::Vector2i> tempMap;
	tileTexture.loadFromFile("forestiles.png");

	if (file.is_open())
	{	std::cout << "DET ÖPPEN" << '\n';
		tileTexture.loadFromFile("forestiles.png");
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
	std::cout << "HELLO" << '\n';
	sf::RenderWindow window(sf::VideoMode(640, 480, 32), "SFML");
	sf::View view1;
	view1.reset((sf::FloatRect(320.f, 240.f, 640.f, 480.f)));
	window.setView(view1);

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{	
			if (evnt.type == sf::Event::Closed){
				window.close();
			}
				// If a key is pressed
				if (evnt.type == sf::Event::KeyPressed)
				{
					switch (evnt.key.code)
					{
					// If escape is pressed, close the application
					case  sf::Keyboard::Escape:
						window.close(); 
						break;
					// Process the up, down, left and right keys
					case sf::Keyboard::Up:
						break;
					case sf::Keyboard::Down:
						break;
					case sf::Keyboard::Left:
					    break;
					case sf::Keyboard::Right:
						view1.move(100,0);
						break;
					default:
						break;
					}
				}
		}
		window.clear(sf::Color::Cyan);

		for (unsigned int i = 0; i < map.size(); i++)
		{
			for (unsigned int j = 0; j < map[i].size(); j++)
			{
				if (map[i][j].x != -1 && map[i][j].y != -1)
				{	window.setView(window.getDefaultView());
					tiles.setPosition(j * 32, i * 32);
					tiles.setTextureRect(sf::IntRect(map[i][j].x * 32, map[i][j].y * 32, 32, 32));
					window.draw(tiles);
				}
			}
		}

		window.display();
	}
	return EXIT_SUCCESS;
}