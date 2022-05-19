#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>

#include "Board.h"
#include "Chess.h"
#pragma once

using namespace std;

class GameManager
{
private:
	int flowControl;
	sf::RenderWindow* window;
	sf::Event ev;

	sf::Texture bgTexture;
	sf::Sprite* background;

	Board board;

	sf::Texture titleTexture;
	sf::Sprite* title;
	Button startButton, exitButton, loadButton;
public:
	GameManager();
	~GameManager();

	const bool isRunning() const;
	void update();
	void render();

	void updateMainPage();
	void updateGamePage();
	void updateEndPage();
	// void updateReplayPage();


	friend void check_mouse(const sf::Event& event);
};

/*
紅棋：
帥 General
仕 Advisor
相 Elephant
傌 Horse
俥 Chariot
炮 Cannon
兵 Soldier


黑棋：
將 General
士 Advisor
象 Elephant
馬 Horse
車 Chariot
砲 Cannon
卒 Soldier
*/