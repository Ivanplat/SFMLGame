#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
class GameLogic
{
public:
	static GameLogic* Instance();
	int CheckPlayerDirection();
	void UpdateTime();
	void UpdateFrame();
public:
	int GetCurrentFrame();
	float GetTime();
	sf::Clock& GetClock();
private:
	sf::Clock Clock;
	int CurrentFrame = 0;
	float Time;

private:
	GameLogic() = default;
};

