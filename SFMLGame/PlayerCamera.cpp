#include "PlayerCamera.h"
#include "GlobalDefiner.h"
#include "GameLogic.h"

void PlayerCamera::Init()
{
    View = sf::View();
    View.reset(sf::FloatRect(0.0f, 0.0f, 640.0f, 480.0f));
}

sf::View PlayerCamera::ViewMap()
{
    switch (Game->CheckPlayerDirection())
    {
    case 0:
    {
        View.move(0.1f * Game->GetTime(), 0);
    }break;
    case 1:
    {        
        View.move(0, 0.1f * Game->GetTime());
    }break;
    case 2:
    {   View.move(-0.1f * Game->GetTime(), 0);
    }break;
    case 3:
    {
        View.move(0, -0.1f * Game->GetTime());
    }break;
    }
    return View;
}

sf::View PlayerCamera::GetPlayerCoordinatesForView(float x, float y)
{
    View.setCenter(x + 100, y);
    return View;
}
