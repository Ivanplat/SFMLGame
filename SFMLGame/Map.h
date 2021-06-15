#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "InteractionInterface.h"

class Map
{
public:
	static Map* Instance();
	void Init(sf::String fn);
	void DrawMap(sf::RenderWindow& window);
	sf::String* GetMap();
public:
	void InteractWithMap(BaseGameActor* Caller);
private:
	Map() = default;
private:
	const int MAP_HEIGHT = 25;
	const int MAP_WIDTH = 40;
	sf::String FileName;
	sf::Image MapImage;
	sf::Texture MapTexture;
	sf::Sprite MapSprite;

	sf::String MapTitle[25] =
	{
	"0000000000000000000000000000000000000000",
	"0                                      0",
	"0   s                                  0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0000000000000000000000000000000000000000",
	};
};

