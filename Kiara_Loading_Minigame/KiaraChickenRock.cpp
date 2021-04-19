#include "KiaraChickenRock.h"
#include "../Lib/LP.h"
#include "../Lib/ID.h"

 KiaraChickenRock::KiaraChickenRock(sf::Vector2f position, Scene* scene)
{
    scene_ = scene;
    tag_ = "Rock";
    name_ = "Rock";
    layerID_ = main_layer;
    position_ = position;
    velocity_ = sf::Vector2f(-(rand() % 2000 + 500), rand() % 1000 + 500);
    angleVelocity_ = rand() % 1000 + 100;
    imageWidth_ = 90;
    imageHeight_ = 61;
    SetLeft(-imageWidth_/2);
    SetRight(imageWidth_/2);
    SetTop(-imageHeight_/2);
    SetBottom(imageHeight_/2);

    sprite_ = LP::SetSprite(kiara_chicken_rock_image, position_);
    LP::SetSpriteOriginCenter(&sprite_);
}

 KiaraChickenRock::~KiaraChickenRock()
{}

void  KiaraChickenRock::Update(float delta_time)
{
    position_ += velocity_ * delta_time;
    sprite_.setPosition(position_);
    angle_ += angleVelocity_ * delta_time;
    sprite_.setRotation(angle_);
}

void  KiaraChickenRock::Draw(sf::RenderWindow& render_window) const
{
    render_window.draw(sprite_);
}

void  KiaraChickenRock::ReactOnCollision(GameObject& other)
{
    if (other.GetTag() == "Player") Kill();
}