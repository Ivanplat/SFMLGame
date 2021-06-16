#include "Map.h"
#include "GlobalDefiner.h"
#include "GameLog.h"
#include "GameLogic.h"
#include "Character.h"

Map* Map::Instance()
{
	static Map map;
	return &map;
}

void Map::Init(sf::String fn)
{
	FileName = fn;
	MapImage.loadFromFile("./images/" + FileName);
	MapTexture.loadFromImage(MapImage);
	MapSprite.setTexture(MapTexture);
}

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

				window.draw(this->MapSprite);
			}
		}
	}
	catch (const std::exception& e)
	{
		std::string message = e.what();
		Log->ShowErrorMessage(message);
	}
}

sf::String* Map::GetMap()
{
	return MapTitle;
}

void Map::InteractWithMap(BaseGameActor* Caller)
{
	if (Character* Char = static_cast<Character*>(Caller))
	{
		for (int i = (Char->Y / 32); i < (Char->Y + Char->Height) / 32; i++)
		{
			for (int j = (Char->X / 32); j < (Char->X + Char->Width) / 32; j++)
			{
				if (MapTitle[i][j] == '0')
				{
					if (Char->dY > 0)
					{
						Char->Y = i * 32 - Char->Height;
					}
					if (Char->dY < 0)
					{
						Char->Y = i * 32 + 32;
					}
					if (Char->dX > 0)
					{
						Char->X = j * 32 - Char->Width;
					}
					if (Char->dX < 0)
					{
						Char->X = j * 32 + 32;
					}
				}
				if (MapTitle[i][j] == 's')
				{
					Char->ScoreComponent->UpdateScore(1);
					MapTitle[i][j] = ' ';
				}
			}
		}
	}
}