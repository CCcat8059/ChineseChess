#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <string>

#include "Chess.h"

class Board
{
private:
	struct point { int x; int y; };
	// Board store the name of chesses
	std::vector<std::vector<std::string>> nameTable;
	// chessBoard store the class of chesses
	std::vector<std::vector<Chess*>> chessBoard;
	point chosenChess;
public:
	Board();
	~Board();

	Chess* clickBoard(sf::Event&);
	void drawBoard(sf::RenderWindow*);
};

