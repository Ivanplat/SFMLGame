#include "GameLogic.h"
#include "GameLog.h"

GameLogic* GameLogic::Instance()
{
    static GameLogic gl;
    return &gl;
}

int GameLogic::CheckPlayerDirection()
{
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A))))
	{
		return 0;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D))))
	{
		return 1;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W))))
	{
		return 2;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S))))
	{
		return 3;
	}
	return -1;
}

void GameLogic::UpdateTime()
{
	Time = Clock.getElapsedTime().asMicroseconds();
	Clock.restart();
	Time /= 800;
}

void GameLogic::UpdateFrame()
{
	CurrentFrame += 0.005 * Time;
	if (CurrentFrame > 3)
	{
		CurrentFrame -= 3;
	}
}

int GameLogic::GetCurrentFrame()
{
	return CurrentFrame;
}

float GameLogic::GetTime()
{
	return Time;
}

sf::Clock& GameLogic::GetClock()
{
	return Clock;
}
