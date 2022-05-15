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

	Board = { {"black chariot", "black horse" , "black elephant","black advisor","black king"   ,"black advisor","black elephant","black horse" ,"black chariot"},

			  {"none empty"  , "none empty" , "none empty"   ,"none empty"  ,"none empty"  ,"none empty"  ,"none empty"   ,"none empty" ,"none empty"  },

			  {"none empty"  , "black cannon", "none empty"   ,"none empty"  ,"none empty"  ,"none empty"  ,"none empty"   ,"black cannon","none empty"  },

			  {"black soldier", "none empty" , "black soldier" ,"none empty"  ,"black soldier","none empty"  ,"black soldier" ,"none empty" ,"black soldier"},

			  {"none empty"  , "none empty" , "none empty"   ,"none empty"  ,"none empty"  ,"none empty"  ,"none empty"   ,"none empty" ,"none empty"  },

			  {"none empty"  , "none empty" , "none empty"   ,"none empty"  ,"none empty"  ,"none empty"  ,"none empty"   ,"none empty" ,"none empty"  },

			  {"red soldier", "none empty" , "red soldier" ,"none empty"  ,"red soldier","none empty"  ,"red soldier" ,"none empty" ,"red soldier"},

			  {"none empty"  , "red cannon", "none empty"   ,"none empty"  ,"none empty"  ,"none empty"  ,"none empty"   ,"red cannon","none empty"  },

			  {"none empty"  , "none empty" , "none empty"   ,"none empty"  ,"none empty"  ,"none empty"  ,"none empty"   ,"none empty" ,"none empty"  },

			  {"red chariot", "red horse" , "red elephant","red advisor","red king"   ,"red advisor","red elephant","red horse" ,"red chariot"} };
	
	//chessBoard = std::vector<std::vector<Chess*> > (10, std::vector<Chess*>(9));

	sf::VideoMode videoMode(810, 875);
	this->window = new sf::RenderWindow(videoMode, "ChineseChess", sf::Style::Titlebar | sf::Style::Close);

	this->bgTexture.loadFromFile("image/board.jpg");
	this->background = new sf::Sprite();
	this->background->setTexture(bgTexture);
	this->background->setPosition(20, 20);

	//draw();
	

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

    //
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

			std::cout << "chosen Flag = " << chosenFlag << " || ";
			// 選一個棋子
			// 判斷滑鼠選擇同顏色的棋子

			// 判斷滑鼠選擇其他棋子
				// 判斷是否可以走
					// 是 => swap(兩個位置的class)，換對方進攻
					// 否 => 不做任何動作
			//std::cout << "ch = " << chosenFlag << std::endl;
			if (chosenFlag == true) {
				std::cout << "chosen = " << chosen->getColor() << " "  << chosen->getName() << std::endl;
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 9; j++) {

						if (chessBoard[i][j]->isClicked(sf::Vector2f(ev.mouseButton.x, ev.mouseButton.y)) && ev.mouseButton.button == sf::Mouse::Left) {
							nextX = i, nextY = j;
							if (chosen->canMove(Board,chosenX,chosenY,i,j) && chessBoard[i][j]->getColor() != chessBoard[chosenX][chosenY]->getColor()) {
								std::string temp = Board[chosenX][chosenY];
								Board[chosenX][chosenY] = Board[i][j];
								Board[i][j] = temp;
								chosenFlag = false;
								//=======================
								//= 這邊需不需要解構子？ =
								//=======================
							}
							else {
								std::cout << "click = " << chessBoard[nextX][nextY]->getName() << " || ";
								if (chessBoard[nextX][nextY]->getName() != "empty") {
									chosen = chessBoard[i][j];
									std::cout << chosen->getName() << '\n';
									chosenFlag = true;
								}
								else {
									std::cout << "false \n";
									// 選到empty
									chosenFlag = false;
									continue;
								}
							}
						}
						else {
							continue;
						}
					}
				}
			}
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 9; j++)
				{
					if (chessBoard[i][j]->isClicked(sf::Vector2f(ev.mouseButton.x, ev.mouseButton.y))) {
						std::cout << i  << "," << j << " " << chessBoard[i][j]->getName() << '\n';
						chosenX = i, chosenY = j;
						chosenFlag = true;
					}
				}
			}


			// display
			/*
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 9; j++) {
					std::cout << Board[i][j] << " ";
				}
				std::cout << std::endl;
			}
			*/
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
	//board.drawBoard(window);

	this->draw();
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++)
		{
			window->draw(chessBoard[i][j]->getBody());
		}
	}
		
	window->display();

	// display Board
	
}

void GameManager::draw()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			std::stringstream ss;
			ss << Board[i][j];
			std::string color;
			std::string name;
			ss >> color;
			ss >> name;
			if (name == "empty") {
				chessBoard[i][j] = new Empty(sf::Vector2f(54 + j * 87.5 - 37.5, 50 + i * 85.5 - 37.5), color);
			}
			if (name == "king") {
				chessBoard[i][j] = new King(sf::Vector2f(54 + j * 87.5 - 37.5, 50 + i * 85.5 - 37.5), color);
			}
			if (name == "advisor") {
				chessBoard[i][j] = new Advisor(sf::Vector2f(54 + j * 87.5 - 37.5, 50 + i * 85.5 - 37.5), color);
			}
			if (name == "elephant") {
				chessBoard[i][j] = new Elephant(sf::Vector2f(54 + j * 87.5 - 37.5, 50 + i * 85.5 - 37.5), color);
			}
			if (name == "horse") {
				chessBoard[i][j] = new Horse(sf::Vector2f(54 + j * 87.5 - 37.5, 50 + i * 85.5 - 37.5), color);
			}
			if (name == "chariot") {
				chessBoard[i][j] = new Chariot(sf::Vector2f(54 + j * 87.5 - 37.5, 50 + i * 85.5 - 37.5), color);
			}
			if (name == "cannon") {
				chessBoard[i][j] = new Cannon(sf::Vector2f(54 + j * 87.5 - 37.5, 50 + i * 85.5 - 37.5), color);
			}
			if (name == "soldier") {
				chessBoard[i][j] = new Soldier(sf::Vector2f(54 + j * 87.5 - 37.5, 50 + i * 85.5 - 37.5), color);
			}
		}
	}
}



