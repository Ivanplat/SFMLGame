#include <iostream>
#include "SFML/Graphics.hpp"
#include "GameLog.h"
#include "GameLogic.h"
#include "Character.h"

#include "GlobalDefiner.h"


int main()
{
	GameLog::Instance();
	GameLogic::Instance();

	sf::RenderWindow window(sf::VideoMode(800, 600), "My SFML C++ Game");
	
	Character MainCharacter("hero.png", 250.0f, 250.0f, 96.0f, 96.0f);

	float currentFrame = 0.0f;

	while (window.isOpen())
	{
		Game->UpdateTime();

		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		MainCharacter.Update();

		window.clear();
		window.draw(MainCharacter.CharacterSprite);
		window.display();
	}

	return 0;
}