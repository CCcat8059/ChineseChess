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
				chessBoard[i][j] = new King(position, color);
			}
			else if (nameTable[i][j] == "Advisor") {
				chessBoard[i][j] = new Advisor(position, color);
			}
			else if (nameTable[i][j] == "Elephant") {
				chessBoard[i][j] = new Elephant(position, color);
			}
			else if (nameTable[i][j] == "Horse") {
				chessBoard[i][j] = new Horse(position, color);
			}
			else if (nameTable[i][j] == "Chariot") {
				chessBoard[i][j] = new Chariot(position, color);
			}
			else if (nameTable[i][j] == "Cannon") {
				chessBoard[i][j] = new Cannon(position, color);
			}
			else if (nameTable[i][j] == "Soldier") {
				chessBoard[i][j] = new Soldier(position, color);
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
					//清除提示可走
					for (int x = 0; x < chessBoard.size(); x++)
					{
						for (int y = 0; y < chessBoard[x].size(); y++)
						{
							chessBoard[x][y]->canMove_flag = false;
						}
					}
					// 如果判斷這個棋子的Move規則，可以移動到現在選的位置 = > swap
					if (chessBoard[tempX][tempY]->canMove(tempX, tempY, i, j, chessBoard) == true) {

						// if the color is opposite, eat it and swap
						// otherwise just swap

						std::string thitRoundColor;
						thitRoundColor = roundCount % 2 == 0 ? "red" : "black";
						//如果吃掉king就判斷獲勝

						if (chessBoard[i][j]->getName() == "king") {
							winner = thitRoundColor;
							return chessBoard[i][j];
						}
						if (chessBoard[tempX][tempY]->getColor() != chessBoard[i][j]->getColor()) {
							this->removeChess({ i,j });
						}
						Chess* temp = chessBoard[i][j];
						chessBoard[i][j] = chessBoard[tempX][tempY];
						chessBoard[tempX][tempY] = temp;
						swapChess(chessBoard[i][j], chessBoard[tempX][tempY]);
						chosenChessIndex = { -1,-1 };



						for (int _i = 0; _i < chessBoard.size(); _i++)//移動完檢查同色每個棋子是否造成將軍
						{
							for (int _j = 0; _j < chessBoard[_i].size(); _j++)
							{
								if (chessBoard[_i][_j]->getColor() == thitRoundColor) {
									Chess* myChess = chessBoard[_i][_j];

									for (int x = 0; x < chessBoard.size(); x++)//移動完檢查是否將軍
									{
										for (int y = 0; y < chessBoard[x].size(); y++)
										{
											if (myChess->canMove(_i, _j, x, y, chessBoard) && chessBoard[x][y]->getName() == "king") {
												checkmate = thitRoundColor;

											}
										}
									}
								}
							}
						}
						roundCount++;
						return temp;
					}

					// 無法移動，就Do Nothing
					else {
						chosenChessIndex = { -1,-1 };
						continue;
					}
				}
				else if (chessBoard[i][j]->getName() != "empty")
				{
					// store
					std::string thitRoundColor;
					thitRoundColor = roundCount % 2 == 0 ? "red" : "black";
					if (thitRoundColor == chessBoard[i][j]->getColor()) {
						chosenChessIndex = { i,j };

						for (int x = 0; x < chessBoard.size(); x++)
						{
							for (int y = 0; y < chessBoard[x].size(); y++)
							{
								chessBoard[x][y]->canMove_flag = chessBoard[i][j]->canMove(i, j, x, y, chessBoard);
							}
						}
					}
					return chessBoard[i][j];
				}
				else // click on empty position
				{
					for (int x = 0; x < chessBoard.size(); x++)
					{
						for (int y = 0; y < chessBoard[x].size(); y++)
						{
							chessBoard[x][y]->canMove_flag = false;
						}
					}
					return chessBoard[i][j];
				}
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
	if (chessBoard[target.x][target.y]->getName() != "empty") {
		std::string path = "image/" + chessBoard[target.x][target.y]->getColor() + "/" + chessBoard[target.x][target.y]->getName() + ".png";
		removedChesses.push_back(path);
	}
	delete chessBoard[target.x][target.y];
	sf::Vector2f position = sf::Vector2f(54 + target.y * 87.5 - 37.5, 50 + target.x * 85.5 - 37.5);
	chessBoard[target.x][target.y] = new Empty(position);
}