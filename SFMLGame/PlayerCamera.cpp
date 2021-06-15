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
    switch (Game->GetCameraAction())
    {
    case 0: View.move(0.1f *     Game->GetTime(), 0);  break;
    case 1: View.move(0, 0.1f *  Game->GetTime());     break;
    case 2: View.move(-0.1f *    Game->GetTime(), 0);  break;
    case 3: View.move(0, -0.1f * Game->GetTime());     break;
    case 4: View.zoom(1.01f);                          break;
    case 5: View.zoom(0.99f);                          break;
    }
    return View;
}

sf::View PlayerCamera::GetPlayerCoordinatesForView(float x, float y)
{
    float tempX = x;
    float tempY = y;

    if (x < 320){tempX = 320;}          //Set end coordinates for the camera 
    if (y < 240){tempY = 240;}          //Set end coordinates for the camera 
    if (y > 554){tempY = 554;}          //Set end coordinates for the camera 

    View.setCenter(tempX, tempY);
    return View;
}
