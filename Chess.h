#pragma once
#include <string>
#include <iostream>
#include <sstream>
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
	virtual bool canMove(const std::vector<std::vector<std::string>>& Board, int x1, int y1, int x2, int y2) { return 1; }
	virtual bool isClicked(sf::Vector2f) { return 1; }
	sf::Sprite getBody() { return body; }
	std::string getName() { return name; }
	std::string getColor() { return color; }
};

class Empty : public Chess {
public:
	Empty(sf::Vector2f position, std::string _color) {
		body.setPosition(position.x, position.y);
		name = "empty";
		this->color = _color;
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
	King(sf::Vector2f position, std::string _color){
		body.setPosition(position.x, position.y);
		name = "king";
		this->color = _color;
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

	bool canMove(const std::vector<std::vector<std::string>>& Board, int x1, int y1, int x2, int y2) {
		std::cout << "move func\n";
		// king 九宮格內，直行或橫行，每次一步
		// 列出所有可以走的點
		if (color == "red") {
			// x2, y2 在九宮格內
			// 要是直行或橫行
			// 只差一格
			if ((x2 >= 7 && x2 <= 9) && (y1 >= 3 && y2 <= 5)) {
				if ((x1 == x2 && abs(y1 - y2) == 1) || (abs(x1 - x2) == 1 && y1 == y2)) {
					return 1;
				}
			}
		}
		if (color == "black") {
			// x2, y2 在九宮格內
			// 要是直行或橫行
			// 只差一格
			if ((x2 >= 0 && x2 <= 2) && (y1 >= 3 && y2 <= 5)) {
				if ((x1 == x2 && abs(y1 - y2) == 1) || (abs(x1 - x2) == 1 && y1 == y2)) {
					return 1;
				}
			}
		}
		return 0;

		// 若想要的點是合法的 return 1
	}

};
class Advisor : public Chess {

public:
	Advisor() {
		name = "advisor";
	}
	Advisor(sf::Vector2f position, std::string _color) {
		body.setPosition(position.x, position.y);
		name = "advisor";
		this->color = _color;
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
	Elephant(sf::Vector2f position, std::string _color) {
		body.setPosition(position.x, position.y);
		name = "elephant";
		this->color = _color;
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
	Horse(sf::Vector2f position, std::string _color) {
		body.setPosition(position.x, position.y);
		name = "horse";
		this->color = _color;
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
	Chariot(sf::Vector2f position, std::string _color) {
		body.setPosition(position.x, position.y);
		name = "chariot";
		this->color = _color;
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
	Cannon(sf::Vector2f position, std::string _color) {
		body.setPosition(position.x, position.y);
		name = "cannon";
		this->color = _color;
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
	Soldier(sf::Vector2f position, std::string _color) {
		body.setPosition(position.x, position.y);
		name = "soldier";
		this->color = _color;
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
