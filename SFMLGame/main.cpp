#include <iostream>
#include "SFML/Graphics.hpp"
#include "GameLog.h"
#include "GameLogic.h"
#include "Character.h"
#include "Map.h"
#include "Window.h"
#include "RenderText.h"

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

	RenderText* text = Game->SpawnGameObject<RenderText>();
	text->SetText("Alo");
	text->SetSize(100);

	while (GameWindow->MainWindow->isOpen())
	{
		Game->UpdateTime();
		GameWindow->EventHandler();
		MainCharacter.Update();
		MainCharacter.Camera->ViewMap();
		GameWindow->MainWindow->setView(MainCharacter.Camera->View);
		text->SetPosition(MainCharacter.Camera->View.getCenter().x, MainCharacter.Camera->View.getCenter().y);
		GameWindow->MainWindow->clear(sf::Color(128, 106, 89));
		GMap->DrawMap(*GameWindow->MainWindow);
		GameWindow->MainWindow->draw(text->GetTextObject());
		GameWindow->MainWindow->draw(MainCharacter.CharacterSprite);
		GameWindow->MainWindow->display();
	}

	return 0;
}