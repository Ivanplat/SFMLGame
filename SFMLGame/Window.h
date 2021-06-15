#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
/*Window class as sigletone pattern*/

class Window
{
public:
	Window& operator=(const Window&) = delete;	// Delete assigment and copy operations for this class
	Window& operator=(const Window&&) = delete; // Delete assigment and copy operations for this class
	Window(const Window&) = delete;				// Delete assigment and copy operations for this class
	Window(const Window&&) = delete;			// Delete assigment and copy operations for this class
public:
	static Window* Instance();					//Function for getting the singletone instance
	void Init();								//Initialization the window	
	void EventHandler();						//Handle the events in while-loop
public:
	sf::RenderWindow* MainWindow;
private:
	Window() = default;							
};

