#include "Chess.h"

Chess::Chess(std::string path, sf::Vector2f position, std::string name, std::string color)
{
	this->name = name;
	texture.loadFromFile(path);
	body.setTexture(texture);
	body.setPosition(position.x, position.y);
	this->color = color;
}
