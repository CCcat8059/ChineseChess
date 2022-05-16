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
						// 不能被卡到馬腳
						if (abs(x1 - x2) == 1) { // 左跟右
							if (y1 < y2) { // 往右
								if (chessBoard[x1][y1 + 1]->getName() == "empty") {
									return true;
								}
							}
							if (y1 > y2) { // 往左
								if (chessBoard[x1][y1 - 1]->getName() == "empty") {
									return true;
								}
							}
						}
						if (abs(y1 - y2) == 1) { // 上跟下
							if (x1 > x2) { // 往上
								if (chessBoard[x1 - 1][y1]->getName() == "empty") {
									return true;
								}
							}
							if (x1 < x2) { // 往下
								if (chessBoard[x1 + 1][y1]->getName() == "empty") {
									return true;
								}
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
	// 判斷要去的點，只能是empty或是不同的顏色
	if (chessBoard[x2][y2]->getColor() != color) {
		// 判斷兩點之間是否直線
		if ((x1 == x2 && y1 != y2) || (x1 != x2 && y1 == y2)) {
			// 再判斷之間是否有棋子
			if (x1 == x2) { // 橫的
				if (y1 < y2) { // 往右
					for (int i = y1 + 1; i < y2; i++) {
						if (chessBoard[x1][i]->getName() != "empty") return false;
					}
				}
				if (y1 > y2) { // 往左
					for (int i = y1 - 1; i > y2; i--) {
						if (chessBoard[x1][i]->getName() != "empty") return false;
					}
				}

			}
			if (y1 == y2) { // 橫的
				if (x1 < x2) { // 往下
					for (int i = x1 + 1; i < x2; i++) {
						if (chessBoard[i][y1]->getName() != "empty") return false;
					}
				}
				if (x1 > x2) { // 往左
					for (int i = x1 - 1; i > x2; i--) {
						if (chessBoard[i][y1]->getName() != "empty") return false;
					}
				}
			}
			return true;
		}
	}
	return false;
	
}

bool Cannon::canMove(int x1, int y1, int x2, int y2, std::vector<std::vector<Chess*>> chessBoard)
{
	// 判斷要去的點，
	if (chessBoard[x2][y2]->getColor() != color) {
		// 判斷兩點之間是否直線
		if ((x1 == x2 && y1 != y2) || (x1 != x2 && y1 == y2)) {
			// 再判斷之間是否有棋子
			if (x1 == x2) { // 橫的
				if (y1 < y2) { // 往右
					if (chessBoard[x2][y2]->getName() == "empty") { // 要去的點是empty
						for (int i = y1 + 1; i < y2; i++) {
							if (chessBoard[x1][i]->getName() != "empty") return false;
						}
					}
					else { // 要去的點是不同顏色的棋子
						int countChess = 0;
						for (int i = y1 + 1; i < y2; i++) {
							if (chessBoard[x1][i]->getName() != "empty") countChess++;
						}
						if (countChess != 1) return false;
					}
					
				}
				if (y1 > y2) { // 往左
					if (chessBoard[x2][y2]->getName() == "empty") { // 要去的點是empty
						for (int i = y1 - 1; i > y2; i--) {
							if (chessBoard[x1][i]->getName() != "empty") return false;
						}
					}
					else { // 要去的點是不同顏色的棋子
						int countChess = 0;
						for (int i = y1 - 1; i > y2; i--) {
							if (chessBoard[x1][i]->getName() != "empty") countChess++;
						}
						if (countChess != 1) return false;
					}
				}

			}
			if (y1 == y2) { // 橫的
				if (x1 < x2) { // 往下
					if (chessBoard[x2][y2]->getName() == "empty") { // 要去的點是empty
						for (int i = x1 + 1; i < x2; i++) {
							if (chessBoard[i][y1]->getName() != "empty") return false;
						}
					}
					else { // 要去的點是不同顏色的棋子
						int countChess = 0;
						for (int i = x1 + 1; i < x2; i++) {
							if (chessBoard[i][y1]->getName() != "empty") countChess++;
						}
						if (countChess != 1) return false;
					}

				}
				if (x1 > x2) { // 往左
					if (chessBoard[x2][y2]->getName() == "empty") { // 要去的點是empty
						for (int i = x1 - 1; i > x2; i--) {
							if (chessBoard[i][y1]->getName() != "empty") return false;
						}
					}
					else { // 要去的點是不同顏色的棋子
						int countChess = 0;
						for (int i = x1 - 1; i > x2; i--) {
							if (chessBoard[i][y1]->getName() != "empty") countChess++;
						}
						if (countChess != 1) return false;
					}
				}
			}
			return true;
		}
	}

	// 判斷要去的點，是不同的顏色
	if (chessBoard[x2][y2]->getColor() != color) {
		// 判斷兩點之間是否直線
		if ((x1 == x2 && y1 != y2) || (x1 != x2 && y1 == y2)) {
			// 再判斷之間是否有棋子
			if (x1 == x2) { // 橫的
				if (y1 < y2) { // 往右
					for (int i = y1 + 1; i < y2; i++) {
						if (chessBoard[x1][i]->getName() != "empty") return false;
					}
				}
				if (y1 > y2) { // 往左
					for (int i = y1 - 1; i > y2; i--) {
						if (chessBoard[x1][i]->getName() != "empty") return false;
					}
				}

			}
			if (y1 == y2) { // 橫的
				if (x1 < x2) { // 往下
					for (int i = x1 + 1; i < x2; i++) {
						if (chessBoard[i][y1]->getName() != "empty") return false;
					}
				}
				if (x1 > x2) { // 往左
					for (int i = x1 - 1; i > x2; i--) {
						if (chessBoard[i][y1]->getName() != "empty") return false;
					}
				}
			}
			return true;
		}
	}
	return false;
}

bool Soldier::canMove(int x1, int y1, int x2, int y2, std::vector<std::vector<Chess*>> chessBoard)
{
	if (color == "red") {
		if (chessBoard[x2][y2]->getColor() != color) {
			// 只能直走 往上
			if (y1 == y2 && x2 - x1 == -1) return true;
			// 有過河 => 可以左跟右
			if (x1 <= 4) { // 過河
				if (x1 == x2 && abs(y1-y2) == 1) {
					return true;
				}
			}
		}
	}
	if (color == "black") {
		if (chessBoard[x2][y2]->getColor() != color) {
			// 只能直走 往下
			if (y1 == y2 && x2 - x1 == 1) return true;
			// 有過河 => 可以左跟右
			if (x1 >= 5) { // 過河
				if (x1 == x2 && abs(y1 - y2) == 1) {
					return true;
				}
			}
		}
	}
	return false;
}
