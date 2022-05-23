#pragma once
#include <windows.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

class Replay
{
private:
	std::string readPath;
	std::vector<std::string> moveLog;
	int readMoveIndex;
	int gameStatus;	// -1: in game, 0: red win, 1: black win
public:
	Replay() { readPath = ""; readMoveIndex = 0; gameStatus = -1; };

	void selectFile();
	void readFile();

	std::string getBackMove() { return moveLog.back(); };
	int getStatus() { return gameStatus; };
	std::string getCurrent() { return moveLog[readMoveIndex]; };

	std::string operator++(int);
};

