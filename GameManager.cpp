#include "GameManager.h"

void check_mouse(const sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Right) {
			std::cout << event.mouseButton.x << std::endl;
			std::cout << event.mouseButton.y << std::endl;
		}
	}

	if (event.type == sf::Event::MouseButtonReleased) {
		std::cout << "realease" << std::endl;
	}
}

GameManager::GameManager()
{
	// Board init
	sf::VideoMode videoMode(480, 500);
	this->window = new sf::RenderWindow(videoMode, "Main menu", sf::Style::Titlebar | sf::Style::Close);

	this->bgTexture.loadFromFile("image/board.jpg");
	this->background = new sf::Sprite();
	this->background->setTexture(bgTexture);
	this->background->setPosition(20, 20);


	this->titleTexture.loadFromFile("image/title.png");
	this->title = new sf::Sprite();
	this->title->setTexture(titleTexture);
	this->title->setPosition(90, 30);

	this->startButton.setName("start_button");
	this->startButton.setPosition({ 117,150 });
	this->startButton.setTexture("image/start_button.png");

	this->loadButton.setName("load_button");
	this->loadButton.setPosition({ 117,250 });
	this->loadButton.setTexture("image/load_button.png");

	this->exitButton.setName("exit_button");
	this->exitButton.setPosition({ 117,350 });
	this->exitButton.setTexture("image/exit_button.png");

	this->flowControl = 0;
}

GameManager::~GameManager()
{
	delete this->window;
	delete this->background;
	delete this->title;
}

const bool GameManager::isRunning() const
{
	return window->isOpen();
}

void GameManager::update()
{
	while (window->pollEvent(ev))
	{
		switch (flowControl)
		{
		case 0:
			updateMainPage(); break;
		case 1:
			updateGamePage(); break;
		case 2:
			updateEndPage(); break;
			/*
			case 3:
				updateReplayPage(); break;
			*/
		}
	}
}

void GameManager::render()
{
	window->clear(sf::Color::White);
	if (flowControl == 0)
	{
		window->draw(*title);
		window->draw(startButton.getBody());
		window->draw(loadButton.getBody());
		window->draw(exitButton.getBody());
	}
	else if (flowControl == 1)
	{
		// draw Board
		window->draw(*this->background);
		board.drawBoard(window);
	}
	window->display();
}

void GameManager::updateMainPage()
{
	switch (ev.type)
	{
	case sf::Event::Closed:
		window->close();
		break;
	case sf::Event::MouseButtonPressed:
		std::cout << ev.mouseButton.x << " " << ev.mouseButton.y << '\n';
		// start, replay and exit button
		break;
	case sf::Event::KeyPressed:
		if (ev.key.code == sf::Keyboard::Escape)
			window->close();
		if (ev.key.code == sf::Keyboard::A)
		{
			flowControl = 1;	// enter game page
			delete this->window;
			sf::VideoMode videoMode(810, 875);
			this->window = new sf::RenderWindow(videoMode, "ChineseChess", sf::Style::Titlebar | sf::Style::Close);
		}
		break;
	}
}

void GameManager::updateGamePage()
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
		{
			std::cout << clickChess->getName() << ' ' << clickChess->getColor() << "\n";
		}
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

void GameManager::updateEndPage()
{
}

