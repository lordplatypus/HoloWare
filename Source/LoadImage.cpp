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
    LP::SetFont("./Resource/Kiara/Blue Sky 8x8.ttf");
    LP::SetTexture(kiara_image, "./Resource/Kiara/Kiara.png", 1142, 1043);
    LP::SetTexture(background_image, "./Resource/Kiara/Background.png", 1920, 1080);
    LP::SetTexture(chicken_image, "./Resource/Kiara/Chicken.png", 59, 90);
    LP::SetTexture(shadow_image, "./Resource/Kiara/Shadow.png", 448, 99);
}