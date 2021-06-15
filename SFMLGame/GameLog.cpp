#include "GameLog.h"

GameLog* GameLog::Instance()
{
	static GameLog gl;
	return &gl;
}

void GameLog::ShowCurretPath()
{
	std::cout << std::filesystem::current_path() << std::endl;
}

