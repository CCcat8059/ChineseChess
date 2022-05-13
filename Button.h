#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>

class Button
{
private:
	sf::Texture texture;
public:
	sf::Sprite body;
	std::string name;

	Button();
	Button(std::string, sf::Vector2f = { 0,0 }, std::string = "defaultBtnName");
	void setTexture(std::string);
	bool isClicked(sf::Vector2f);
};

