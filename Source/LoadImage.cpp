#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Header/LoadImage.h"
#include "../Header/ID.h"
#include "../Header/LP.h"

LoadImage::LoadImage()
{}

LoadImage::~LoadImage()
{
    
}

void LoadImage::Load()
{
    LP::SetFont("./Blue Sky 8x8.ttf");
    LP::SetTexture(kiara_image, "./Kiara.png", 1142, 1043);
    LP::SetTexture(background_image, "./Background.png", 1920, 1080);
    LP::SetTexture(chicken_image, "./Chicken.png", 59, 90);
    LP::SetTexture(shadow_image, "./Shadow.png", 448, 99);
}