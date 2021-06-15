#include <iostream>
#include "SFML/Graphics.hpp"



int main()
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "My SFML C++ Game");
	sf::CircleShape shape(50.0f);

	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}