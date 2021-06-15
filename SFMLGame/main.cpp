#include <iostream>
#include "SFML/Graphics.hpp"
#include "GameLog.h"
#include "GameLogic.h"
#include "Character.h"
#include "Map.h"

#include "GlobalDefiner.h"


int main()
{
	GameLog::Instance();
	GameLogic::Instance();

	sf::RenderWindow window(sf::VideoMode(800, 600), "My SFML C++ Game");
	
	Character MainCharacter("hero.png", 250.0f, 250.0f, 96.0f, 96.0f);
	Map GameMap("map.png");

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
		GameMap.DrawMap(window);
		window.draw(MainCharacter.CharacterSprite);
		window.display();
	}

	return 0;
}