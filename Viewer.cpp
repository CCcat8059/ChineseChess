#include "Viewer.h"

Viewer::Viewer()
{
	this->window = nullptr;
	this->boardBackground = nullptr;
	this->title = nullptr;
}

Viewer::~Viewer()
{
	if (this->window != nullptr)
		delete this->window;
	if (this->boardBackground != nullptr)
		delete this->boardBackground;
	if (this->title != nullptr)
		delete this->title;
}

void Viewer::initMainPage()
{
	if (this->window != nullptr)
		delete this->window;
	sf::VideoMode videoMode(480, 500);
	this->window = new sf::RenderWindow(videoMode, "Main menu", sf::Style::Titlebar | sf::Style::Close);

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
}

void Viewer::initGamePage()
{
	if (this->window != nullptr)
		delete this->window;
	sf::VideoMode videoMode(1500, 875);
	this->window = new sf::RenderWindow(videoMode, "ChineseChess", sf::Style::Titlebar | sf::Style::Close);
	// Board init
	this->boardTexture.loadFromFile("image/board.jpg");
	this->boardBackground = new sf::Sprite();
	this->boardBackground->setTexture(boardTexture);
	this->boardBackground->setPosition(20, 20);
}

void Viewer::initReplayPage()
{
	replay.selectFile();
	replay.readFile();
	replay.setMoveIndex(0);
	initGamePage();
	this->nextStepButton.setName("next_step_button");
	this->nextStepButton.setPosition({ 1280,80 });
	this->nextStepButton.setTexture("image/next_step_button.png");
}

int Viewer::updateMainPage(sf::Event ev)
{
	int flowControl = 0;
	switch (ev.type)
	{
	case sf::Event::Closed:
		window->close();
		break;
	case sf::Event::MouseButtonPressed:
		if (startButton.isClicked(ev))
		{
			flowControl = 1;	// enter game page
			return flowControl;
			// initGamePage();
		}
		else if (exitButton.isClicked(ev))
		{
			window->close();
		}
		else if (loadButton.isClicked(ev))
		{
			flowControl = 2;
			return flowControl;
		}
		break;
	case sf::Event::KeyPressed:
		if (ev.key.code == sf::Keyboard::Escape)
			window->close();
		break;
	}
	return flowControl;
}

int Viewer::updateGamePage(sf::Event ev, Board* board)
{
	int flowControl = 1;
	Chess* clickChess = nullptr;
	switch (ev.type)
	{
	case sf::Event::Closed:
		window->close();
		break;
	case sf::Event::MouseButtonPressed:
		// click Board
		clickChess = board->clickBoard(ev, window);
		if (clickChess != nullptr)
		{
			std::cout << clickChess->getName() << ' ' << clickChess->getColor() << "\n";

			// Function which judge is CheckMate or not
			std::string checkmate = board->getCheckmate();
			if (checkmate != "") { // if checkMate confirmed, send the message to player.
				std::string msg;
				if (checkmate == "red") msg = "red checkmate";
				if (checkmate == "black") msg = "black checkmate";
				MessageBoxA(NULL, msg.c_str(), "Message", MB_OKCANCEL | MB_ICONEXCLAMATION);
				board->setCheckmate("");
			}

			// Function which judge is over or not
			std::string winner = board->getWinner();
			if (winner != "") { // if overed, show the result, and player can choice play again or not.
				std::string msg;
				if (winner == "red") msg = "red win";
				if (winner == "black") msg = "black win";
				MessageBoxA(NULL, msg.c_str(), "Message", MB_OK);

				int result = MessageBoxA(NULL, "play again?", "Message", MB_OKCANCEL);
				(*board).resetBoard();
				if (result == 2) // back to main menu
				{
					flowControl = 0;
					return flowControl;
				}
			}
		}
		break;
	case sf::Event::KeyPressed:
		if (ev.key.code == sf::Keyboard::Escape)
			window->close();
		if (ev.key.code == sf::Keyboard::Delete)
		{
			Point index = board->getChosenChessIndex();
			if (index.x != -1 && index.y != -1)
			{
				board->removeChess(index);
				board->setChosenChessIndex({ -1,-1 });
			}
		}
		break;
	}
	return flowControl;
}

int Viewer::updateReplayPage(sf::Event ev, Board* board)
{
	int flowControl = 2;
	switch (ev.type)
	{
	case sf::Event::Closed:
		window->close();
		break;
	case sf::Event::MouseButtonPressed:
		// std::cout << ev.mouseButton.x << ' ' << ev.mouseButton.y << '\n';
		if (nextStepButton.isClicked(ev))
		{
			std::string move = replay.getCurrent();
			sf::Event replayEV;
			replayEV.type = sf::Event::MouseButtonPressed;
			replayEV.mouseButton.x = 54 + (move[1] - '0') * 87.5 + 37.5;
			replayEV.mouseButton.y = 50 + (move[3] - '0') * 85.5 + 37.5;
			board->clickBoard(replayEV, window);
			replayEV.mouseButton.x = 54 + (move[6] - '0') * 87.5 + 37.5;
			replayEV.mouseButton.y = 50 + (move[8] - '0') * 85.5 + 37.5;
			board->clickBoard(replayEV, window);
			
			replay++;
			if (move == replay.getBackMove())
			{
				if (replay.getStatus() == -1) {
					std::string finish = "the replay log is finish";
					MessageBoxA(NULL, finish.c_str(), "Message", MB_OK);
					(*board).resetBoard();
				}
				else {
					std::string winner = (replay.getStatus() == 1 ? "red win" : "black win");
					MessageBoxA(NULL, winner.c_str(), "Message", MB_OK);
					(*board).resetBoard();
				}

				flowControl = 0;
				return flowControl;
			}
		}
		break;
	}
	return flowControl;
}

void Viewer::showMainPage()
{
	window->clear(sf::Color::White);
	window->draw(*title);
	window->draw(startButton.getBody());
	window->draw(loadButton.getBody());
	window->draw(exitButton.getBody());
	window->display();
}

void Viewer::showGamePage(Board* board)
{
	window->clear(sf::Color::White);
	window->draw(*this->boardBackground);
	// draw chess and the position that chess can move to
	for (auto& v : board->getBoard()) {
		for (auto& c : v) {
			sf::Sprite sp = c->getBody();
			if (c->canMove_flag) {
				if (c->getName() == "empty") {
					sf::CircleShape shape(37.f);
					shape.setPosition(sp.getPosition());
					shape.setFillColor(sf::Color::Color(255, 0, 0, 120));

					window->draw(shape);
					continue;
				}
				else {
					sp.setColor(sf::Color::Red);
					window->draw(sp);
				}
			}
			if (c->getName() != "empty")
				window->draw(sp);
		}
	}

	// display dead chesses and 
	std::vector<std::string> removedChesses = board->getRemovedChesses();
	for (int i = 0; i < removedChesses.size(); i++) {
		std::string path = removedChesses[i];
		sf::Vector2f position = sf::Vector2f(850 + (i / 8) * 100, 75 + (i % 8) * 100);
		sf::Texture texture;
		texture.loadFromFile(path);
		sf::Sprite sp;
		sp.setTexture(texture);
		sp.setPosition(position);
		window->draw(sp);
	}

	// display which side should move
	std::string thitRoundColor;
	thitRoundColor = board->getRoundCount() % 2 == 0 ? "red" : "black";
	sf::Font font;
	font.loadFromFile("font/arial.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString("Current Player : " + thitRoundColor);
	sf::Vector2f position = sf::Vector2f(850, 10);
	text.setPosition(position);
	text.setCharacterSize(50); // in pixels, not points!
	text.setFillColor(sf::Color::Black);
	window->draw(text);

	window->display();
}

void Viewer::showReplayPage(Board* board)
{
	window->clear(sf::Color::White);
	window->draw(nextStepButton.getBody());

	window->draw(*this->boardBackground);
	for (auto& v : board->getBoard())
	{
		for (auto& c : v)
		{
			if (c->getName() != "empty")
				window->draw(c->getBody());
		}
	}

	// display dead chesses and 
	std::vector<std::string> removedChesses = board->getRemovedChesses();
	for (int i = 0; i < removedChesses.size(); i++) {
		std::string path = removedChesses[i];
		sf::Vector2f position = sf::Vector2f(850 + (i / 8) * 100, 75 + (i % 8) * 100);
		sf::Texture texture;
		texture.loadFromFile(path);
		sf::Sprite sp;
		sp.setTexture(texture);
		sp.setPosition(position);
		window->draw(sp);
	}

	// display which side should move
	std::string thitRoundColor;
	thitRoundColor = board->getRoundCount() % 2 == 0 ? "red" : "black";
	sf::Font font;
	font.loadFromFile("font/arial.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString("Current Player : " + thitRoundColor);
	sf::Vector2f position = sf::Vector2f(850, 10);
	text.setPosition(position);
	text.setCharacterSize(50); // in pixels, not points!
	text.setFillColor(sf::Color::Black);
	window->draw(text);
	window->display();
}