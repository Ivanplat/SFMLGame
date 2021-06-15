#include <iostream>
#include "SFML/Graphics.hpp"
#include "GameLog.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "My SFML C++ Game");
	
	sf::Image heroImage;
	heroImage.loadFromFile("images/hero.png");

	sf::Texture heroTexture;
	heroTexture.loadFromImage(heroImage);

	sf::Sprite heroSprite;
	heroSprite.setTexture(heroTexture);
	heroSprite.setTextureRect(sf::IntRect(0, 192, 96, 96));
	heroSprite.setPosition(50, 25);

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
		window.draw(heroSprite);
		window.display();
	}

	return 0;
}