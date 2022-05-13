#include "GameManager.h"

GameManager::GameManager()
{
	sf::VideoMode videoMode(808, 872);
	this->window = new sf::RenderWindow(videoMode, "ChineseChess", sf::Style::Titlebar | sf::Style::Close);


	this->bgTexture.loadFromFile("image/board.jpg");
	this->background = new sf::Sprite();
	this->background->setTexture(bgTexture);
	this->background->setPosition(20, 20);


	this->soldiers = new Button[5];
	for (int i = 0; i < 5; i++)
	{
		this->soldiers[i].setTexture("image/red/soldier.png");
		this->soldiers[i].body.setPosition(60 + i * 170 - 37.5, 300 - 37.5);
	}
}

GameManager::~GameManager()
{
	delete this->window;
	delete this->background;
	delete[] this->soldiers;
}

const bool GameManager::isRunning() const
{
	return window->isOpen();
}

void GameManager::update()
{
	while (window->pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::MouseButtonPressed:
			for (int i = 0; i < 5; i++)
			{
				if (soldiers[i].isClicked(sf::Vector2f(ev.mouseButton.x, ev.mouseButton.y)))
					std::cout << i << '\n';
			}
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape)
				window->close();
			break;
		}
	}
}

void GameManager::render()
{
	window->clear(sf::Color::White);
	window->draw(*this->background);
	for (int i = 0; i < 5; i++)
		window->draw(this->soldiers[i].body);
	window->display();
}
