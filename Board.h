#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <string>


#include "Chess.h"

class Board
{
private:

	// Board store the name of chesses
	std::vector<std::vector<std::string> > nameTable;
	// chessBoard store the class of chesses
	std::vector<std::vector<Chess*> > chessBoard;
	Point chosenChess;
	Point targetChess;
	bool chosenFlag = false;
public:
	Board();
	~Board();

	Chess* clickBoard(sf::Event&);
	void drawBoard(sf::RenderWindow*);
	std::vector<std::vector<Chess*> > getChessBoard() { return chessBoard; }
	void update();
};
