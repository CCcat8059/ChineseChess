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
	~Chess() {};
	std::string getColor() { return color; };
	virtual void move() { return; }
	void update() {
		std::string path = "image/" + color + "/" + name + ".png";
	}
};

class Empty : public Chess {
public:
	Empty(sf::Vector2f position) : Button(position, "empty") {};
};

class King : public Chess {
public:
	King(sf::Vector2f position, std::string color) : Button(position, "king") {
		this->color = color;
		std::string path = "image/" + color + "/" + name + ".png";
		this->setTexture(path);
	};
	~King() {};
};

class Advisor : public Chess {
public:
	Advisor(sf::Vector2f position, std::string color) : Button(position, "advisor") {
		this->color = color;
		std::string path = "image/" + color + "/" + name + ".png";
		this->setTexture(path);
	};
	~Advisor() {};
};

class Elephant : public Chess {
public:
	Elephant(sf::Vector2f position, std::string color) : Button(position, "elephant") {
		this->color = color;
		std::string path = "image/" + color + "/" + name + ".png";
		this->setTexture(path);
	};
	~Elephant() {};
};

class Horse : public Chess {
public:
	Horse(sf::Vector2f position, std::string color) : Button(position, "horse") {
		this->color = color;
		std::string path = "image/" + color + "/" + name + ".png";
		this->setTexture(path);
	};
	~Horse() {};
};

class Chariot : public Chess {
public:
	Chariot(sf::Vector2f position, std::string color) : Button(position, "chariot") {
		this->color = color;
		std::string path = "image/" + color + "/" + name + ".png";
		this->setTexture(path);
	};
	~Chariot() {};
};

class Cannon : public Chess {
public:
	Cannon(sf::Vector2f position, std::string color) : Button(position, "cannon") {
		this->color = color;
		std::string path = "image/" + color + "/" + name + ".png";
		this->setTexture(path);
	};
	~Cannon() {};
};

class Soldier : public Chess {
public:
	Soldier(sf::Vector2f position, std::string color) : Button(position, "soldier") {
		this->color = color;
		std::string path = "image/" + color + "/" + name + ".png";
		this->setTexture(path);
	};
	~Soldier() {};
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