#include "Window.h"
#include "GlobalDefiner.h"
#include "GameLogic.h"

Window* Window::Instance()
{
    static Window window;
    return &window;
}

void Window::Init()
{
    MainWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "My SFML C++ Game");
}

void Window::EventHandler()
{
	sf::Event e;
	while (MainWindow->pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
		{
			MainWindow->close();
		}
	}
}

