#pragma once
#include <iostream>
#include <filesystem>

/*GameLog class as sigletone pattern*/

class GameLog
{
public:
	GameLog& operator=(const GameLog&) = delete;
	GameLog& operator=(const GameLog&&) = delete;
	GameLog(const GameLog&) = delete;
	GameLog(const GameLog&&) = delete;
public:
	static GameLog* Instance();
	void ShowCurretPath();
	void ShowErrorMessage(std::string message);

private:
	GameLog() = default;
};

