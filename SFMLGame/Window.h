#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
/*Window class as sigletone pattern*/

class Window
{
public:
	Window& operator=(const Window&) = delete;
	Window& operator=(const Window&&) = delete;
	Window(const Window&) = delete;
	Window(const Window&&) = delete;
public:
	static Window* Instance();
	void Init();
	void EventHandler();
public:
	sf::RenderWindow* MainWindow;
private:
	Window() = default;
};

