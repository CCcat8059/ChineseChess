#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "Button.h"
#include "Board.h"

class Viewer
{
private:
	sf::RenderWindow* window;

	// main page object
	sf::Texture titleTexture;
	sf::Sprite* title;
	Button startButton, exitButton, loadButton;

	// game page object
	sf::Texture boardTexture;
	sf::Sprite* boardBackground;
public:
	Viewer();
	~Viewer();

	const bool windowIsRunning() const { return window->isOpen(); };
	sf::RenderWindow& getWindow() { return *window; };

	void initMainPage();
	void initGamePage();
	void initReplayPage();

	int updateMainPage(sf::Event);
	int updateGamePage(sf::Event, Board*);
	int updateReplayPage(sf::Event);

	void showMainPage();
	void showGamePage(Board*);
	void showReplayPage();
};
