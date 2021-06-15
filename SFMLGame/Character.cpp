#include "Character.h"
#include "GlobalDefiner.h"
#include "GameLogic.h"
#include "GameLog.h"

void Character::Move()
{
	switch (Direction)
	{
	case 0: dX = -Speed; dY = 0; break;
	case 1: dX = Speed; dY = 0; break;
	case 2: dX = 0; dY = -Speed; break;
	case 3: dX = 0; dY = Speed; break;
	}

	X += dX * Game->GetTime();
	Y += dY * Game->GetTime();

	Speed = 0;
	CharacterSprite.setPosition(X, Y);
	InteractWithMap();
}

void Character::Update()
{

	switch (Game->CheckPlayerDirection())
	{
	case 0:
	{
		Direction = 0;
		Speed = 0.1f;
		Game->UpdateFrame();
		CharacterSprite.setTextureRect(sf::IntRect(96 * int(Game->GetCurrentFrame()), 96, 96, 96));
		Camera.GetPlayerCoordinatesForView(X, Y);
	}
	break;
	case 1:
	{
		Direction = 1;
		Speed = 0.1f;
		Game->UpdateFrame();
		CharacterSprite.setTextureRect(sf::IntRect(96 * int(Game->GetCurrentFrame()) + 96, 96, -96, 96));
		Camera.GetPlayerCoordinatesForView(X, Y);
	}
	break;
	case 2:
	{
		Direction = 2;
		Speed = 0.1f;
		Game->UpdateFrame();
		CharacterSprite.setTextureRect(sf::IntRect(96 * int(Game->GetCurrentFrame()), 288, 96, 96));
		Camera.GetPlayerCoordinatesForView(X, Y);
	}break;
	case 3:
	{
		Direction = 3;
		Speed = 0.1f;
		Game->UpdateFrame();
		CharacterSprite.setTextureRect(sf::IntRect(96 * int(Game->GetCurrentFrame()), 0, 96, 96));
		Camera.GetPlayerCoordinatesForView(X, Y);
	}
	break;
	}
	Move();

}

void Character::InteractWithMap()
{
	GMap->InteractWithMap(this);
}
