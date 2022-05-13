#pragma once
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Chess
{
protected:
	sf::Texture texture;
	sf::Sprite body;
	std::string name;
	std::string color;

public:
	Chess() {};
	Chess(std::string path, sf::Vector2f position, std::string name, std::string color);
	virtual void move() { return; }
	virtual bool isClicked(sf::Vector2f) { return 1; }
	sf::Sprite getBody() { return body; }
};

class Empty : public Chess {
public:
	Empty(sf::Vector2f position) {
		body.setPosition(position.x, position.y);
		name = "empty";
	};
};
class General : public Chess {
public:
	General() {
		name = "general";
	}
	General(sf::Vector2f position){
		body.setPosition(position.x, position.y);
		name = "general";
		texture.loadFromFile("image/black/king.png");
		body.setTexture(texture);
	};
	
	bool isClicked(sf::Vector2f clickPos)
	{
		sf::Vector2f btnPos = body.getPosition();
		sf::Vector2f btnEnd = btnPos + sf::Vector2f(75, 75);
		if (clickPos.x<btnPos.x || clickPos.x>btnEnd.x)
			return false;
		if (clickPos.y<btnPos.y || clickPos.y>btnEnd.y)
			return false;
		return true;
	}

};