#include "Button.h"

Button::Button()
{
	this->name = "";
	this->body = sf::Sprite();
	this->texture = sf::Texture();
}

Button::Button(std::string path, sf::Vector2f position, std::string name)
{
	this->name = name;
	texture.loadFromFile(path);
	body.setTexture(texture);
	body.setPosition(position.x, position.y);
}

void Button::setTexture(std::string path)
{
	texture.loadFromFile(path);
	body.setTexture(texture);
}

bool Button::isClicked(sf::Vector2f clickPos)
{
	sf::Vector2f btnPos = body.getPosition();
	sf::Vector2f btnEnd = btnPos + sf::Vector2f(75, 75);
	if (clickPos.x<btnPos.x || clickPos.x>btnEnd.x)
		return false;
	if (clickPos.y<btnPos.y || clickPos.y>btnEnd.y)
		return false;
	return true;
}
