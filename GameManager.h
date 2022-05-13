#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include "Button.h"

#pragma once
class GameManager
{
private:
	sf::RenderWindow* window;
	sf::Event ev;

	sf::Texture bgTexture;
	sf::Sprite* background;

	Button* soldiers;
public:
	GameManager();
	~GameManager();

	const bool isRunning() const;
	void update();
	void render();
};

