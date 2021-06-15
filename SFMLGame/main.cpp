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
	float currentFrame = 0.0f;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 800;
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
			currentFrame += 0.005 * time;
			if (currentFrame > 3.0f)
			{
				currentFrame -= 3.0f;
			}
			heroSprite.setTextureRect(sf::IntRect(96 * int(currentFrame), 96, 96, 96));
			heroSprite.move(-0.1f*time, 0.0f);
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D))))
		{
			currentFrame += 0.005 * time;
			if (currentFrame > 3.0f)
			{
				currentFrame -= 3.0f;
			}
			heroSprite.setTextureRect(sf::IntRect(96 * int(currentFrame) + 96, 96, -96, 96));
			heroSprite.move(0.1f*time, 0.0f);
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W))))
		{
			currentFrame += 0.005 * time;
			if (currentFrame > 3.0f)
			{
				currentFrame -= 3.0f;
			}
			heroSprite.setTextureRect(sf::IntRect(96 * int(currentFrame), 288, 96, 96));
			heroSprite.move(0.0f, -0.1f*time);
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S))))
		{
			currentFrame += 0.005 * time;
			if (currentFrame > 3.0f)
			{
				currentFrame -= 3.0f;
			}
			heroSprite.setTextureRect(sf::IntRect(96 * int(currentFrame), 0, 96, 96));
			heroSprite.move(0.0f, 0.1f*time);
		}


		window.clear();
		window.draw(heroSprite);
		window.display();
	}

	return 0;
}