#include "Board.h"

Board::Board()
{
	nameTable = { {"Chariot", "Horse" , "Elephant","Advisor","King"   ,"Advisor","Elephant","Horse" ,"Chariot"},

				  {"Empty"  , "Empty" , "Empty"   ,"Empty"  ,"Empty"  ,"Empty"  ,"Empty"   ,"Empty" ,"Empty"  },

				  {"Empty"  , "Cannon", "Empty"   ,"Empty"  ,"Empty"  ,"Empty"  ,"Empty"   ,"Cannon","Empty"  },

				  {"Soldier", "Empty" , "Soldier" ,"Empty"  ,"Soldier","Empty"  ,"Soldier" ,"Empty" ,"Soldier"},

				  {"Empty"  , "Empty" , "Empty"   ,"Empty"  ,"Empty"  ,"Empty"  ,"Empty"   ,"Empty" ,"Empty"  },

				  {"Empty"  , "Empty" , "Empty"   ,"Empty"  ,"Empty"  ,"Empty"  ,"Empty"   ,"Empty" ,"Empty"  },

				  {"Soldier", "Empty" , "Soldier" ,"Empty"  ,"Soldier","Empty"  ,"Soldier" ,"Empty" ,"Soldier"},

				  {"Empty"  , "Cannon", "Empty"   ,"Empty"  ,"Empty"  ,"Empty"  ,"Empty"   ,"Cannon","Empty"  },

				  {"Empty"  , "Empty" , "Empty"   ,"Empty"  ,"Empty"  ,"Empty"  ,"Empty"   ,"Empty" ,"Empty"  },

				  {"Chariot", "Horse" , "Elephant","Advisor","King"   ,"Advisor","Elephant","Horse" ,"Chariot"} };

	chessBoard.resize(10);
	for (auto& c : chessBoard)
		c.resize(9);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			std::string color = (i <= 4 && j <= 9) ? "black" : "red";
			sf::Vector2f position = sf::Vector2f(54 + j * 87.5 - 37.5, 50 + i * 85.5 - 37.5);

			if (nameTable[i][j] == "Empty") {
				chessBoard[i][j] = new Empty(position);
			}
			else if (nameTable[i][j] == "King") {
				chessBoard[i][j] = new King(position, color, { i,j });
			}
			else if (nameTable[i][j] == "Advisor") {
				chessBoard[i][j] = new Advisor(position, color, { i,j });
			}
			else if (nameTable[i][j] == "Elephant") {
				chessBoard[i][j] = new Elephant(position, color, { i,j });
			}
			else if (nameTable[i][j] == "Horse") {
				chessBoard[i][j] = new Horse(position, color, { i,j });
			}
			else if (nameTable[i][j] == "Chariot") {
				chessBoard[i][j] = new Chariot(position, color, { i,j });
			}
			else if (nameTable[i][j] == "Cannon") {
				chessBoard[i][j] = new Cannon(position, color, { i,j });
			}
			else if (nameTable[i][j] == "Soldier") {
				chessBoard[i][j] = new Soldier(position, color, { i,j });
			}
		}
	}

	chosenChessIndex = { -1,-1 };
}

Board::~Board()
{
	for (auto& v : chessBoard)
	{
		for (auto& c : v)
			delete c;
	}
}

Chess* Board::clickBoard(sf::Event& ev)
{
	for (int i = 0; i < chessBoard.size(); i++)
	{
		for (int j = 0; j < chessBoard[i].size(); j++)
		{
			if (chessBoard[i][j]->isClicked(ev))
			{
				int tempX = chosenChessIndex.x, tempY = chosenChessIndex.y;
				if (tempX != -1 && tempY != -1)
				{
					// swap
					Chess* temp = chessBoard[i][j];
					chessBoard[i][j] = chessBoard[tempX][tempY];
					chessBoard[tempX][tempY] = temp;
					swapChess(chessBoard[i][j], chessBoard[tempX][tempY]);
					chosenChessIndex = { -1,-1 };
					return temp;
				}
				else if (chessBoard[i][j]->getName() != "empty")
				{
					std::cout << "take up\n";
					// store
					chosenChessIndex = { i,j };
					return chessBoard[i][j];
				}
				else // click on empty position
					return chessBoard[i][j];
			}
		}
	}
	return nullptr;
}

void Board::swapChess(Chess* a, Chess* b)
{
	sf::Vector2f tempPos = a->getBody().getPosition();
	a->getBody().setPosition(b->getBody().getPosition());
	b->getBody().setPosition(tempPos);
}

void Board::removeChess(Point target)
{
	delete chessBoard[target.x][target.y];
	sf::Vector2f position = sf::Vector2f(54 + target.y * 87.5 - 37.5, 50 + target.x * 85.5 - 37.5);
	chessBoard[target.x][target.y] = new Empty(position);
}

void Board::drawBoard(sf::RenderWindow* window)
{
	//for (auto& v : chessBoard)
	//	for (auto& c : v)
	//		window->draw(c->getBody());
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++)
		{
			window->draw(chessBoard[i][j]->getBody());
		}
	}
}

void Board::update()
{
	for (auto& v : chessBoard) {
		for (auto& c : v) {
			c->update();
		}
	}
}
