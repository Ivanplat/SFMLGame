#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "PlayerCamera.h"
#include "Map.h"
#include "InteractionInterface.h"

class Character : public BaseGameActor
{
public:
	Character(sf::String fn, float x, float y, float w, float h) : FileName(fn), X(x), Y(y), Width(w), Height(h)
	{
		CharacterImage.loadFromFile("./images/" + FileName);
		CharacterImage.createMaskFromColor(sf::Color(41, 33, 59));
		CharacterTexture.loadFromImage(CharacterImage);
		CharacterSprite.setTexture(CharacterTexture);
		CharacterSprite.setTextureRect(sf::IntRect(w, h, w, h));
		Camera = PlayerCamera();
	}

public:
	float X = 0;
	float Y = 0;
	float Width = 0;
	float Height = 0;
	float dX = 0;
	float dY = 0;
	float Speed = 0;
	int Direction = 0;
	PlayerCamera Camera;
public:
	sf::String FileName;
	sf::Image CharacterImage;
	sf::Texture CharacterTexture;
	sf::Sprite CharacterSprite;
public:
	void Move();
	void Update();
	void InteractWithMap();
};

