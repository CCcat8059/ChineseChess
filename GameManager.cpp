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
	Board = { {"Chariot", "Horse" , "Elephant","Advisor","King"   ,"Advisor","Elephant","Horse" ,"Chariot"},

			  {"Empty"  , "Empty" , "Empty"   ,"Empty"  ,"Empty"  ,"Empty"  ,"Empty"   ,"Empty" ,"Empty"  },

			  {"Empty"  , "Cannon", "Empty"   ,"Empty"  ,"Empty"  ,"Empty"  ,"Empty"   ,"Cannon","Empty"  },

			  {"Soldier", "Empty" , "Soldier" ,"Empty"  ,"Soldier","Empty"  ,"Soldier" ,"Empty" ,"Soldier"},

			  {"Empty"  , "Empty" , "Empty"   ,"Empty"  ,"Empty"  ,"Empty"  ,"Empty"   ,"Empty" ,"Empty"  },

			  {"Empty"  , "Empty" , "Empty"   ,"Empty"  ,"Empty"  ,"Empty"  ,"Empty"   ,"Empty" ,"Empty"  },

			  {"Soldier", "Empty" , "Soldier" ,"Empty"  ,"Soldier","Empty"  ,"Soldier" ,"Empty" ,"Soldier"},

			  {"Empty"  , "Cannon", "Empty"   ,"Empty"  ,"Empty"  ,"Empty"  ,"Empty"   ,"Cannon","Empty"  },

			  {"Empty"  , "Empty" , "Empty"   ,"Empty"  ,"Empty"  ,"Empty"  ,"Empty"   ,"Empty" ,"Empty"  },

			  {"Chariot", "Horse" , "Elephant","Advisor","King"   ,"Advisor","Elephant","Horse" ,"Chariot"} };
	
	chessBoard = std::vector<std::vector<Chess*> > (10, std::vector<Chess*>(9));
	sf::VideoMode videoMode(810, 875);
	this->window = new sf::RenderWindow(videoMode, "ChineseChess", sf::Style::Titlebar | sf::Style::Close);


	this->bgTexture.loadFromFile("image/board.jpg");
	this->background = new sf::Sprite();
	this->background->setTexture(bgTexture);
	this->background->setPosition(20, 20);

	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			std::string color;
			if (i <= 4 && j <= 9) color = "black";
			else color = "red";
			//std::cout << i << ", " << j << " = " << Board[i][j] << std::endl;
			if (Board[i][j] == "Empty") {
				chessBoard[i][j] = new Empty(sf::Vector2f(54 + j * 87.5 - 37.5, 50 + i * 85.5 - 37.5));
			}
			if (Board[i][j] == "King") {
				chessBoard[i][j] = new King(sf::Vector2f(54 + j * 87.5 - 37.5, 50 + i* 85.5 - 37.5), color);
			}
			if (Board[i][j] == "Advisor") {
				chessBoard[i][j] = new Advisor(sf::Vector2f(54 + j * 87.5 - 37.5, 50 + i * 85.5 - 37.5), color);
			}
			if (Board[i][j] == "Elephant") {
				chessBoard[i][j] = new Elephant(sf::Vector2f(54 + j * 87.5 - 37.5, 50 + i * 85.5 - 37.5), color);
			}
			if (Board[i][j] == "Horse") {
				chessBoard[i][j] = new Horse(sf::Vector2f(54 + j * 87.5 - 37.5, 50 + i * 85.5 - 37.5), color);
			}
			if (Board[i][j] == "Chariot") {
				chessBoard[i][j] = new Chariot(sf::Vector2f(54 + j * 87.5 - 37.5, 50 + i * 85.5 - 37.5), color);
			}
			if (Board[i][j] == "Cannon") {
				chessBoard[i][j] = new Cannon(sf::Vector2f(54 + j * 87.5 - 37.5, 50 + i * 85.5 - 37.5), color);
			}
			if (Board[i][j] == "Soldier") {
				chessBoard[i][j] = new Soldier(sf::Vector2f(54 + j * 87.5 - 37.5, 50 + i * 85.5 - 37.5), color);
			}
		}
	}
	
	
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
		switch (ev.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::MouseButtonPressed:
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 9; j++)
				{
					if (chessBoard[i][j]->isClicked(sf::Vector2f(ev.mouseButton.x, ev.mouseButton.y))) {
						std::cout << i  << "," << j << " " << chessBoard[i][j]->getName() << '\n';
					}
				}
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
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++)
		{
			window->draw(chessBoard[i][j]->getBody());
		}
	}
		
	window->display();
}


