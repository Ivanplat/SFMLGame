#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"

/*GameLogic class as sigletone pattern*/

class GameLogic
{
public:
	GameLogic& operator=(const GameLogic&) = delete;	// Delete assigment and copy operations for this class
	GameLogic& operator=(const GameLogic&&) = delete;	// Delete assigment and copy operations for this class
	GameLogic(const GameLogic&) = delete;				// Delete assigment and copy operations for this class
	GameLogic(const GameLogic&&) = delete;				// Delete assigment and copy operations for this class
	~GameLogic() = default;
public:
	static GameLogic* Instance();						//Function for getting the singletone instance
	int CheckPlayerDirection();							//Returns value from 0 to 3, but in case of no direction returns -1	
	void UpdateTime();									//Updating the game time
	void UpdateFrame();									//Updating the game frame
	int GetCameraAction();
public:
	int GetCurrentFrame();
	float GetTime();
	sf::Clock& GetClock();
	std::vector<sf::String>& GetMapTitle();
private:
	sf::Clock Clock;
	int CurrentFrame = 0;
	float Time;
	std::vector<sf::String> MapTitle;

private:
	GameLogic() = default;
};

