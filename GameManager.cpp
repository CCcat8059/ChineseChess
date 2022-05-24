#include "GameManager.h"

GameManager::GameManager()
{
	flowControl = 0;
	this->ev = sf::Event();
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
			temp = viewer.updateReplayPage(ev, &board); break;
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
				viewer.initReplayPage(); break;
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
		viewer.showReplayPage(&board); break;
	}
}