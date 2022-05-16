#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <string>

#include "Chess.h"

struct Point { int x; int y; };
class Board
{
private:
	Point chosenChessIndex;
	// Board store the name of chesses
	std::vector<std::vector<std::string>> nameTable;
	// chessBoard store the class of chesses
	std::vector<std::vector<Chess*>> chessBoard;
public:
	Board();
	~Board();

	std::vector<std::vector<Chess*>>& getBoard() { return chessBoard; };
	Point getChosenChessIndex() { return chosenChessIndex; };
	void setChosenChessIndex(Point p) { chosenChessIndex = { p.x,p.y }; };
	Chess* clickBoard(sf::Event&);
	void swapChess(Chess*, Chess*);
	void removeChess(Point);
	void drawBoard(sf::RenderWindow*);
};

