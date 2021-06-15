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

	GameWindow->Init();

	Character MainCharacter("hero.png", 250.0f, 250.0f, 96.0f, 96.0f);
	Map GameMap("map.png");

	while (GameWindow->MainWindow->isOpen())
	{
		Game->UpdateTime();
		GameWindow->EventHandler();
		MainCharacter.Update();
		GameWindow->MainWindow->clear();
		GameMap.DrawMap(*GameWindow->MainWindow);
		GameWindow->MainWindow->draw(MainCharacter.CharacterSprite);
		GameWindow->MainWindow->display();
	}

	return 0;
}