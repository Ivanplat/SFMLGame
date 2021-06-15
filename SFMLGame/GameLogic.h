#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

/*GameLogic class as sigletone pattern*/

class GameLogic
{
public:
	GameLogic& operator=(const GameLogic&) = delete;
	GameLogic& operator=(const GameLogic&&) = delete;
	GameLogic(const GameLogic&) = delete;
	GameLogic(const GameLogic&&) = delete;
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

