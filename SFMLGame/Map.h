#pragma once
#include "SFML/Graphics.hpp"
class Map
{
public:

	Map(sf::String fn) : FileName(fn)
	{
		MapImage.loadFromFile("./images/" + FileName);
		MapTexture.loadFromImage(MapImage);
		MapSprite.setTexture(MapTexture);
	}
public:
	void DrawMap(sf::RenderWindow& window);
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

