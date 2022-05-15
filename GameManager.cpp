#include "GameManager.h"

void check_mouse(const sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed) { //檢測鼠標 輸出鼠標座標
		if (event.mouseButton.button == sf::Mouse::Right) {
			std::cout << event.mouseButton.x << std::endl;
			std::cout << event.mouseButton.y << std::endl;
		}
	}

	if (event.type == sf::Event::MouseButtonReleased) { //檢測鼠標釋放
		std::cout << "realease" << std::endl;
	}
}

GameManager::GameManager()
{
	// Board init
	sf::VideoMode videoMode(810, 875);
	this->window = new sf::RenderWindow(videoMode, "ChineseChess", sf::Style::Titlebar | sf::Style::Close);

	this->bgTexture.loadFromFile("image/board.jpg");
	this->background = new sf::Sprite();
	this->background->setTexture(bgTexture);
	this->background->setPosition(20, 20);
}

GameManager::~GameManager()
{
	delete this->window;
	delete this->background;
	//delete[] this->Army;
}

const bool GameManager::isRunning() const
{
	return window->isOpen();
}

void GameManager::update()
{
	//std::cout << "update\n";
	while (window->pollEvent(ev))
	{/*
		std::cout << "ch = " << chosenFlag << std::endl;
		if (chosenFlag == 1) {
			std::cout << "1";
			for (int i = 0; i < 9; i++)
			{
				if (Army[i].isClicked(sf::Vector2f(ev.mouseButton.x, ev.mouseButton.y))) {
					chosen = &Army[i];
					std::cout << i << '\n';
					chosenFlag = true;
					//continue;
				}
			}
			if (ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left)
			{
				std::cout << "2";
				chosen->body.setPosition(ev.mouseButton.x-37.5, ev.mouseButton.y-37.5);
				chosenFlag = false;
				continue;
			}
		}
		*/
		Chess* clickChess = nullptr;
		switch (ev.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::MouseButtonPressed:
			// click Board
			clickChess = board.clickBoard(ev);
			if (clickChess != nullptr)
				cout << clickChess->getName() << " (" << clickChess->getColor() << ")\n";
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
	// draw Board
	board.drawBoard(window);
	window->display();
}