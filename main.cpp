#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

int main()
{
	// test
	sf::RenderWindow window(sf::VideoMode(640, 480), "Just A title", sf::Style::Titlebar | sf::Style::Close);
	sf::Event ev;
	sf::CircleShape circle(30);
	circle.setFillColor(sf::Color(85, 255, 85));
	while (window.isOpen())
	{
		while (window.pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				circle.setPosition(ev.mouseButton.x, ev.mouseButton.y);
				std::cout << ev.mouseButton.x << ' ' << ev.mouseButton.y << '\n';
				break;
			case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::Escape)
					window.close();
				break;
			}
		}
		window.clear(sf::Color::White);
		window.draw(circle);
		window.display();
	}
}