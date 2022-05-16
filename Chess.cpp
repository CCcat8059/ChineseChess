#include "Chess.h"

// TODO every chesses' move

bool King::canMove(int x1, int y1, int x2, int y2, std::vector<std::vector<Chess*>> chessBoard)
{
	if (y2 >= 3 && y2 <= 5) {
		if (color == "red") {
			if (chessBoard[x2][y2]->getColor() != color) {
				if (x2 >= 7 && x2 <= 9) {
					if (abs(x1 - x2 + y1 - y2) == 1) {
						return true;
					}
				}
			}
		}
		if (color == "black") {
			if (chessBoard[x2][y2]->getColor() != color) {
				if (x2 >= 0 && x2 <= 2) {
					if (abs(x1 - x2 + y1 - y2) == 1) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool Advisor::canMove(int x1, int y1, int x2, int y2, std::vector<std::vector<Chess*>> chessBoard)
{
	if (y2 >= 3 && y2 <= 5) {
		if (color == "red") {
			if (chessBoard[x2][y2]->getColor() != color) {
				if (x2 >= 7 && x2 <= 9) {
					if (abs(x1 - x2) + abs(y1 - y2) == 2) {
						return true;
					}
				}
			}
		}
		if (color == "black") {
			if (chessBoard[x2][y2]->getColor() != color) {
				if (x2 >= 0 && x2 <= 2) {
					if (abs(x1 - x2) + abs(y1 - y2) == 2) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool Elephant::canMove(int x1, int y1, int x2, int y2, std::vector<std::vector<Chess*>> chessBoard)
{
	if (y2 >= 0 && y2 <= 8) {
		if (color == "red") {
			if (chessBoard[x2][y2]->getColor() != color) {
				if (x2 >= 5 && x2 <= 9) {
					if (abs(x1 - x2) + abs(y1 - y2) == 4) {
						// 如果田字中間有棋子就不能走
						if (x1 > x2 && y1 < y2) { // 往右上走
							if (chessBoard[x1-1][y1+1]->getName() == "empty") {
								return true;
							}
						} 
						if (x1> x2 && y1 > y2){ // 往左上走
							if (chessBoard[x1-1][y1-1]->getName() == "empty") {
								return true;
							}
						}
						if (x1 < x2 && y1 < y2) { // 往右下走
							if (chessBoard[x1+1][y1+1]->getName() == "empty") {
								return true;
							}
						}
						if (x1 < x2 && y1 > y2) { // 往左下走
							if (chessBoard[x1+1][y1-1]->getName() == "empty") {
								return true;
							}
						}
					}
				}
			}
		}
		if (color == "black") {
			if (chessBoard[x2][y2]->getColor() != color) {
				if (x2 >= 0 && x2 <= 4) {
					if (abs(x1 - x2) + abs(y1 - y2) == 4) {
						// 如果田字中間有棋子就不能走
						if (x1 > x2 && y1 < y2) { // 往右上走
							if (chessBoard[x1 - 1][y1 + 1]->getName() == "empty") {
								return true;
							}
						}
						if (x1 > x2 && y1 > y2) { // 往左上走
							if (chessBoard[x1 - 1][y1 - 1]->getName() == "empty") {
								return true;
							}
						}
						if (x1 < x2 && y1 < y2) { // 往右下走
							if (chessBoard[x1 + 1][y1 + 1]->getName() == "empty") {
								return true;
							}
						}
						if (x1 < x2 && y1 > y2) { // 往左下走
							if (chessBoard[x1 + 1][y1 - 1]->getName() == "empty") {
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}

bool Horse::canMove(int x1, int y1, int x2, int y2, std::vector<std::vector<Chess*>> chessBoard)
{
	if (y2 >= 0 && y2 <= 8) {
		if (color == "red") {
			if (chessBoard[x2][y2]->getColor() != color) {
				if (x2 >= 0 && x2 <= 9) {
					if (abs(x1 - x2) + abs(y1 - y2) == 3) {
						// 如果田字中間有棋子就不能走
						if (x1 > x2 && y1 < y2) { // 往右上走
							if (chessBoard[x1 - 1][y1 + 1]->getName() == "empty") {
								return true;
							}
						}
						if (x1 > x2 && y1 > y2) { // 往左上走
							if (chessBoard[x1 - 1][y1 - 1]->getName() == "empty") {
								return true;
							}
						}
						if (x1 < x2 && y1 < y2) { // 往右下走
							if (chessBoard[x1 + 1][y1 + 1]->getName() == "empty") {
								return true;
							}
						}
						if (x1 < x2 && y1 > y2) { // 往左下走
							if (chessBoard[x1 + 1][y1 - 1]->getName() == "empty") {
								return true;
							}
						}
					}
				}
			}
		}
		if (color == "black") {
			if (chessBoard[x2][y2]->getColor() != color) {
				if (x2 >= 0 && x2 <= 9) {
					if (abs(x1 - x2) + abs(y1 - y2) == 3) {
						// 如果田字中間有棋子就不能走
						if (x1 > x2 && y1 < y2) { // 往右上走
							if (chessBoard[x1 - 1][y1 + 1]->getName() == "empty") {
								return true;
							}
						}
						if (x1 > x2 && y1 > y2) { // 往左上走
							if (chessBoard[x1 - 1][y1 - 1]->getName() == "empty") {
								return true;
							}
						}
						if (x1 < x2 && y1 < y2) { // 往右下走
							if (chessBoard[x1 + 1][y1 + 1]->getName() == "empty") {
								return true;
							}
						}
						if (x1 < x2 && y1 > y2) { // 往左下走
							if (chessBoard[x1 + 1][y1 - 1]->getName() == "empty") {
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}

bool Chariot::canMove(int x1, int y1, int x2, int y2, std::vector<std::vector<Chess*>> chessBoard)
{
	return false;
}

bool Cannon::canMove(int x1, int y1, int x2, int y2, std::vector<std::vector<Chess*>> chessBoard)
{
	return false;
}

bool Soldier::canMove(int x1, int y1, int x2, int y2, std::vector<std::vector<Chess*>> chessBoard)
{
	return false;
}
