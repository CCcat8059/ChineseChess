#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <string>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "Chess.h"

struct Point { int x; int y; };
class Board
{
private:
	Point chosenChessIndex;
	// Board store the name of chesses
	std::vector<std::vector<std::string> > nameTable;
	// chessBoard store the class of chesses
	std::vector<std::vector<Chess*>> chessBoard;
	std::vector<std::string> removedChesses; // removed chess img path
	int roundCount = 0;
	std::string checkmate = "";
	std::string winner = "";
public:
	Board();
	~Board();

	std::vector<std::vector<Chess*>>& getBoard() { return chessBoard; };
	Point getChosenChessIndex() { return chosenChessIndex; };
	int getRoundCount() { return roundCount; };
	std::vector<std::string> getRemovedChesses() { return removedChesses; };
	std::string getCheckmate() { return checkmate; };
	void setCheckmate(std::string checkmate) { this->checkmate = checkmate; };
	std::string getWinner() { return winner; };
	void setChosenChessIndex(Point p) { chosenChessIndex = { p.x,p.y }; };
	Chess* clickBoard(sf::Event&, sf::RenderWindow* window);
	void swapChess(Chess*, Chess*);
	void removeChess(Point);
	std::vector<std::vector<Chess*> > getChessBoard() { return chessBoard; }
};
