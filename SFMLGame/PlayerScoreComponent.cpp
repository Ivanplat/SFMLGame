#include "PlayerScoreComponent.h"

void PlayerScoreComponent::UpdateScore(int value)
{
	Score += value;
}

int PlayerScoreComponent::GetScore()
{
	return Score;
}
