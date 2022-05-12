#include <SFML/Graphics.hpp>

#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

int main()
{
	// test cccat
	sf::RenderWindow window(sf::VideoMode(1330, 1445), "ChineseChess", sf::Style::Titlebar | sf::Style::Close);
	sf::Event ev;
	sf::Texture bk;
	if (!bk.loadFromFile("board.jpg"))
		return EXIT_FAILURE;
	sf::Sprite spriteBg(bk);
	while (window.isOpen())
	{
		
		window.clear(sf::Color::White);
		window.draw(spriteBg);
		window.display();
	}
}

