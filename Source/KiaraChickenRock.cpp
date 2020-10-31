#include "../Header/KiaraChickenRock.h"
#include "../Header/LP.h"
#include "../Header/ID.h"

 KiaraChickenRock::KiaraChickenRock(sf::Vector2f position, Scene* scene)
{
    scene_ = scene;
    tag_ = "Rock";
    name_ = "Rock";
    position_ = position;
    velocity_ = sf::Vector2f(-(rand() % 2000 + 500), rand() % 1000 + 500);
    angleVelocity_ = rand() % 1000 + 100;
    imageWidth_ = 90;
    imageHeight_ = 61;
    SetLeft(0);
    SetRight(imageWidth_);
    SetTop(0);
    SetBottom(imageHeight_);

    sprite_ = LP::SetSprite(kiara_chicken_rock_image, position_);
    LP::SetSpriteOriginCenter(sprite_);
}

 KiaraChickenRock::~KiaraChickenRock()
{
    LP::DeleteSprite(sprite_);
}

void  KiaraChickenRock::Update(float delta_time)
{
    position_ += velocity_ * delta_time;
    angle_ += angleVelocity_ * delta_time;
    LP::SetSpriteRotation(sprite_, angle_);
}

void  KiaraChickenRock::Draw()
{
    LP::DrawSprite(sprite_, position_);
}

void  KiaraChickenRock::ReactOnCollision(GameObject& other)
{
    if (other.GetTag() == "Player") Kill();
}