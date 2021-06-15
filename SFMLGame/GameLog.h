#pragma once
#include <iostream>
#include <filesystem>

/*GameLog class as sigletone pattern*/

class GameLog
{
public:
	GameLog& operator=(const GameLog&) = delete;	// Delete assigment and copy operations for this class
	GameLog& operator=(const GameLog&&) = delete;	// Delete assigment and copy operations for this class
	GameLog(const GameLog&) = delete;				// Delete assigment and copy operations for this class
	GameLog(const GameLog&&) = delete;				// Delete assigment and copy operations for this class
public:
	static GameLog* Instance();						//Function for getting the singletone instance
	void ShowCurretPath();							//Write in console current path
	void ShowErrorMessage(std::string message);		//Create messagebox with error description

private:
	GameLog() = default;
};

