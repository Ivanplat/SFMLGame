#include <iostream>
#include "SFML/Graphics.hpp"
#include "GameLog.h"
#include "GameLogic.h"
#include "Character.h"
#include "Map.h"
#include "Window.h"

#include "GlobalDefiner.h"


int main()
{
	GameLog::Instance();
	GameLogic::Instance();
	Window::Instance();
	Map::Instance();

	GameWindow->Init();
	GMap->Init("map.png");

	Character MainCharacter("hero.png", 250.0f, 250.0f, 96.0f, 96.0f);

	while (GameWindow->MainWindow->isOpen())
	{
		Game->UpdateTime();
		GameWindow->EventHandler();
		MainCharacter.Update();
		MainCharacter.Camera.ViewMap();
		GameWindow->MainWindow->setView(MainCharacter.Camera.View);
		GameWindow->MainWindow->clear(sf::Color(128, 106, 89));
		GMap->DrawMap(*GameWindow->MainWindow);
		GameWindow->MainWindow->draw(MainCharacter.CharacterSprite);
		GameWindow->MainWindow->display();
	}

	return 0;
}