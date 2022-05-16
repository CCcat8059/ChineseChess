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
	while (window->pollEvent(ev))
	{
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
			if (ev.key.code == sf::Keyboard::Delete)
			{
				Point index = board.getChosenChessIndex();
				if (index.x != -1 && index.y != -1)
				{
					board.removeChess(index);
					board.setChosenChessIndex({ -1,-1 });
				}
			}
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