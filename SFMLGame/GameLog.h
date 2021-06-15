#pragma once
#include <iostream>
#include <filesystem>
class GameLog
{
public:
	static GameLog* Instance();
	void ShowCurretPath();
	void ShowErrorMessage(std::string message);

private:
	GameLog() = default;
};

