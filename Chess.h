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
	virtual void move();
	sf::Sprite getBody() { return body; }
	std::string getName() { return name; }
};

class Empty : public Chess {
public:
	
	Empty(sf::Vector2f position) {
		body.setPosition(position.x, position.y);
		name = "empty";
		//texture.loadFromFile("image/black/king.png");
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
class King : public Chess {
public:
	King() {
		name = "king";
	}
	King(sf::Vector2f position, std::string color){
		body.setPosition(position.x, position.y);
		name = "king";
		std::string path = "image/" + color + "/" + name + ".png";
		texture.loadFromFile(path);
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
class Advisor : public Chess {

public:
	Advisor() {
		name = "advisor";
	}
	Advisor(sf::Vector2f position, std::string color) {
		body.setPosition(position.x, position.y);
		name = "advisor";
		std::string path = "image/" + color + "/" + name + ".png";
		texture.loadFromFile(path);
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

class Elephant : public Chess {

public:
	Elephant() {
		name = "elephant";
	}
	Elephant(sf::Vector2f position, std::string color) {
		body.setPosition(position.x, position.y);
		name = "elephant";
		std::string path = "image/" + color + "/" + name + ".png";
		texture.loadFromFile(path);
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

class Horse : public Chess {

public:
	Horse() {
		name = "horse";
	}
	Horse(sf::Vector2f position, std::string color) {
		body.setPosition(position.x, position.y);
		name = "horse";
		std::string path = "image/" + color + "/" + name + ".png";
		texture.loadFromFile(path);
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

class Chariot : public Chess {

public:
	Chariot() {
		name = "chariot";
	}
	Chariot(sf::Vector2f position, std::string color) {
		body.setPosition(position.x, position.y);
		name = "chariot";
		std::string path = "image/" + color + "/" + name + ".png";
		texture.loadFromFile(path);
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

class Cannon : public Chess {

public:
	Cannon() {
		name = "cannon";
	}
	Cannon(sf::Vector2f position, std::string color) {
		body.setPosition(position.x, position.y);
		name = "cannon";
		std::string path = "image/" + color + "/" + name + ".png";
		texture.loadFromFile(path);
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

class Soldier : public Chess {

public:
	Soldier() {
		name = "soldier";
	}
	Soldier(sf::Vector2f position, std::string color) {
		body.setPosition(position.x, position.y);
		name = "soldier";
		std::string path = "image/" + color + "/" + name + ".png";
		texture.loadFromFile(path);
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
/*
帥 General
仕 Advisor
相 Elephant
傌 Horse
俥 Chariot
炮 Cannon
兵 Soldier
*/
