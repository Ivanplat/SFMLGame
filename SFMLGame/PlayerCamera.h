#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
class PlayerCamera
{
public:
	PlayerCamera() = default;
	~PlayerCamera() = default;
public:
	void Init();
	sf::View ViewMap();
	sf::View GetPlayerCoordinatesForView(float x, float y);
public:
	sf::View View;
};

