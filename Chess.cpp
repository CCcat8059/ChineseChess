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
