#include "Menu.h"
#include "StageOne.h"


Menu::Menu(GameDataRef data): _data(data)
{
}

Menu::~Menu()
{
}

void Menu::Init()
{
	_data->assets.LoadTexture("MENU", MENU_BACKGROUND_FILEPATH);
	_data->assets.LoadTexture("MENUTEXT", TITLE_FILEPATH);
	_data->assets.LoadTexture("MENUBUTTON", PLAY_BUTTON_FILEPATH);
	_data->assets.LoadSound("bigboy", "output.ogg");
	_data->assets.LoadTexture("big1", "big1.png");
	_data->assets.LoadTexture("big2", "big2.png");
	_data->assets.LoadTexture("big3", "big3.png");
	_data->assets.LoadTexture("big4", "big4.png");
	_data->assets.LoadTexture("gameover", "gamover.png");

	_background.setTexture(_data->assets.GetTexture("MENU"));
	
	_title.setTexture(_data->assets.GetTexture("MENUTEXT"));
	_playButton.setTexture(_data->assets.GetTexture("MENUBUTTON"));

	_title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), _title.getGlobalBounds().height / 2);
	_playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2));
}

void Menu::HandleInput()
{
	sf::Event evnt;
	while (_data->window.pollEvent(evnt))
	{
		if (sf::Event::Closed == evnt.type)
		{
			_data->window.close();
		}
		if (_data->input.IsSpriteClicked(_playButton, sf::Mouse::Left, _data->window)) {
			_data->machine.AddState(StateRef(new StageOne(_data)));
		}
	}
}

void Menu::Update(float deltaTime)
{
}

void Menu::Draw(float deltaTime)
{
	_data->window.clear();
	_data->window.draw(_background);
	_data->window.draw(_playButton);
	_data->window.draw(_title);
	_data->window.display();
}