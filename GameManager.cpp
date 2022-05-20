#include "GameManager.h"

GameManager::GameManager()
{
	flowControl = 0;
	viewer.initMainPage();
}

GameManager::~GameManager()
{
}

const bool GameManager::isRunning() const
{
	return viewer.windowIsRunning();
}

void GameManager::update()
{
	while (viewer.getWindow().pollEvent(ev))
	{
		int temp = 0;
		switch (flowControl)
		{
		case 0:
			temp = viewer.updateMainPage(ev); break;
		case 1:
			temp = viewer.updateGamePage(ev, &board); break;
		case 2:
			temp = viewer.updateEndPage(ev); break;
			/*
			case 3:
				updateReplayPage(); break;
			*/
		}
		if (flowControl != temp)
		{
			switch (temp)
			{
			case 0:
				viewer.initMainPage(); break;
			case 1:
				viewer.initGamePage(); break;
			case 2:
				viewer.initEndPage(); break;
			}
			flowControl = temp;
		}
	}
}

void GameManager::render()
{
	switch (flowControl)
	{
	case 0:
		viewer.showMainPage(); break;
	case 1:
		viewer.showGamePage(&board); break;
	case 2:
		viewer.showEndPage(); break;
	}
}