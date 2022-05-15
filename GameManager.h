#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>

#include "Button.h"
#include "Chess.h"
#pragma once

using namespace std;

class GameManager
{
private:
	sf::RenderWindow* window;
	sf::Event ev;

	sf::Texture bgTexture;
	sf::Sprite* background;

	// board class variable
	Chess* chosen = new Chess;
	bool chosenFlag = false;
	int chosenX, chosenY;
	int nextX, nextY;


	// Board store the name of chesses
	std::vector<std::vector<std::string> > Board;
	// chessBoard store the class of chesses
	std::vector<std::vector<Chess*> > chessBoard;
public:
	GameManager();
	~GameManager();

	const bool isRunning() const;
	void update();
	void render();
	void draw();
	
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