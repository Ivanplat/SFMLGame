#include "GameLog.h"
#include <Windows.h>

GameLog* GameLog::Instance()
{
	static GameLog gl;
	return &gl;
}

void GameLog::ShowCurretPath()
{
	std::cout << std::filesystem::current_path() << std::endl;
}

void GameLog::ShowErrorMessage(std::string message)
{
	HWND hWnd{};
	std::wstring w(message.begin(), message.end());
	LPCWSTR m = w.c_str();
	MessageBox(hWnd, m, L"Error", MB_ICONERROR);
}

