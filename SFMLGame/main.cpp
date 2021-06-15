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

	sf::Clock clock;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 800;
		std::cout << time << std::endl;
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A))))
		{
			heroSprite.move(-0.1f*time, 0.0f);
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D))))
		{
			heroSprite.move(0.1f*time, 0.0f);
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W))))
		{
			heroSprite.move(0.0f, -0.1f*time);
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S))))
		{
			heroSprite.move(0.0f, 0.1f*time);
		}


		window.clear();
		window.draw(heroSprite);
		window.display();
	}

	return 0;
}