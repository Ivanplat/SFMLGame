#include "Map.h"
#include "GlobalDefiner.h"
#include "GameLog.h"

void Map::DrawMap(sf::RenderWindow& window)
{
	try
	{

		for (int i = 0; i < MAP_HEIGHT; i++)
		{
			for (int j = 0; j < MAP_WIDTH; j++)
			{
				if (MapTitle[i][j] == ' ')
				{
					MapSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
				}
				if (MapTitle[i][j] == 's')
				{
					MapSprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
				}
				if (MapTitle[i][j] == '0')
				{
					MapSprite.setTextureRect(sf::IntRect(64, 0, 32, 32));
				}
				MapSprite.setPosition(j * 32, i * 32);

				window.draw(MapSprite);
			}
		}
	}
	catch (const std::exception& e)
	{
		std::string message = e.what();
		Log->ShowErrorMessage(message);
	}
}
