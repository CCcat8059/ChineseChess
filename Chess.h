#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>

#include "Button.h"

class Chess : virtual public Button {
protected:
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

	Empty(sf::Vector2f position, std::string color) : Button(position, "empty") {
		body.setPosition(position.x, position.y);
		name = "empty";
		this->color = _color;
		//texture.loadFromFile("image/black/king.png");
		body.setTexture(texture);

	};
};

class King : public Chess {
public:

	King(sf::Vector2f position, std::string color) : Button(position, "king") {
		body.setPosition(position.x, position.y);
		name = "king";
		this->color = _color;

		std::string path = "image/" + color + "/" + name + ".png";
		this->setTexture(path);
	};


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

	Advisor(sf::Vector2f position, std::string color) : Button(position, "advisor") {
		body.setPosition(position.x, position.y);
		name = "advisor";
		this->color = _color;
		std::string path = "image/" + color + "/" + name + ".png";
		this->setTexture(path);
	};
};

class Elephant : public Chess {
public:

	Elephant(sf::Vector2f position, std::string color) : Button(position, "elephant") {
		body.setPosition(position.x, position.y);
		name = "elephant";
		this->color = _color;
		std::string path = "image/" + color + "/" + name + ".png";
		this->setTexture(path);
	};
};

class Horse : public Chess {
public:

	Horse(sf::Vector2f position, std::string color) : Button(position, "horse") {
		body.setPosition(position.x, position.y);
		name = "horse";
		this->color = _color;

		std::string path = "image/" + color + "/" + name + ".png";
		this->setTexture(path);
	};
};

class Chariot : public Chess {
public:

	Chariot(sf::Vector2f position, std::string color) : Button(position, "chariot") {
		body.setPosition(position.x, position.y);
		name = "chariot";
		this->color = _color;
		std::string path = "image/" + color + "/" + name + ".png";
		this->setTexture(path);
	};
};

class Cannon : public Chess {
public:

	Cannon(sf::Vector2f position, std::string color) : Button(position, "cannon") {
		body.setPosition(position.x, position.y);
		name = "cannon";
		this->color = _color;
		std::string path = "image/" + color + "/" + name + ".png";
		this->setTexture(path);
	};
};

class Soldier : public Chess {
public:

	Soldier(sf::Vector2f position, std::string color) : Button(position, "soldier") {
		this->color = color;
		body.setPosition(position.x, position.y);
		name = "soldier";
		this->color = _color;
		std::string path = "image/" + color + "/" + name + ".png";
		this->setTexture(path);
	};
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
