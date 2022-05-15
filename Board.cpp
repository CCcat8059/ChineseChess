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
				chessBoard[i][j] = new Empty(position, color, {i,j});
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

	chosenChess = { -1,-1 };
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
				targetChess = { i,j };
				//std::cout << "chosenFlag = " << chosenFlag << " | " << chosenChess.x << " , " << chosenChess.y << " to " << targetChess.x << " , " << targetChess.y << std::endl;
				// =============================
				//  這裡應該要判斷，是否有交換進攻
				// =============================
				if (chosenChess.x == targetChess.x && chosenChess.y == targetChess.y) {
					std::cout << "take down\n";
					//chosenChess = { -1,-1 };
					chosenFlag = false;
					continue;
				}
				if (chosenFlag == true && chosenChess.x != -1 && chosenChess.y != -1) // 已經選擇一個棋子了
				{
					std::cout << "take down\n";
					std::cout << "chosenFlag = " << chosenFlag << " | " << chosenChess.x << " , " << chosenChess.y << " to " << targetChess.x << " , " << targetChess.y << std::endl;
					//std::cout << "before: " << chessBoard[chosenChess.x][chosenChess.y] << " to " << chessBoard[targetChess.x][targetChess.y] << "\n";
					
					Chess* temp = chessBoard[chosenChess.x][chosenChess.y];
					//::cout << "temp = " << temp->getName() << " ";
					chessBoard[chosenChess.x][chosenChess.y] = chessBoard[targetChess.x][targetChess.y];
					//std::cout << "chosen become = " << chessBoard[chosenChess.x][chosenChess.y]->getName() << " ";
					chessBoard[targetChess.x][targetChess.y] = temp;
					//std::cout << "target become = " << chessBoard[targetChess.x][targetChess.y]->getName() << "\n";
					
					//std::cout << "after: " << chessBoard[chosenChess.x][chosenChess.y]->getName() << " to " << chessBoard[targetChess.x][targetChess.y]->getName() << "\n\n";
					//chosenChess = { -1,-1 };
					chosenFlag = false;
				}
				else
				{
					std::cout << "take up\n";
					// store
					chosenChess = { i,j };
					//std::cout << chosenChess.x << "," << chosenChess.y << std::endl;
					chosenFlag = true;
					return chessBoard[i][j];
				}
			}
		}
	}
	return nullptr;
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
