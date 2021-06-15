#pragma once
#include <iostream>
#include <filesystem>
class GameLog
{
public:
	static GameLog* Instance();
	void ShowCurretPath();

private:
	GameLog() = default;
};

