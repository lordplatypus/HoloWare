#include "../Header/Chicken.h"
#include "../Header/LP.h"
#include "../Header/ID.h"

 Chicken::Chicken(sf::Vector2f position, Scene* scene)
{
    scene_ = scene;
    tag_ = "Chicken";
    name_ = "Chicken";
    position_ = position;
    velocity_ = sf::Vector2f(-(rand() % 2000 + 500), rand() % 1000 + 500);
    angleVelocity_ = rand() % 1000 + 100;
    imageWidth_ = 59;
    imageHeight_ = 90;
    SetLeft(0);
    SetRight(imageWidth_);
    SetTop(0);
    SetBottom(imageHeight_);

    sprite_ = LP::SetSprite(chicken_image, position_);
    LP::SetSpriteOriginCenter(sprite_);
}

 Chicken::~Chicken()
{
    LP::DeleteSprite(sprite_);
}

void  Chicken::Update(float delta_time)
{
    position_ += velocity_ * delta_time;
    angle_ += angleVelocity_ * delta_time;
    LP::SetSpriteRotation(sprite_, angle_);
}

void  Chicken::Draw()
{
    LP::DrawSprite(sprite_, position_);
}

void  Chicken::ReactOnCollision(GameObject& other)
{
    if (other.GetTag() == "Player") Kill();
}