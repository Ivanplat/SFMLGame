#pragma once
#include "BaseActorComponent.h"
class PlayerScoreComponent : public BaseActorComponent
{
public:
	void UpdateScore(int value);
	int GetScore();
private:
	int Score = 0;
};

