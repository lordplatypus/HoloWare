#include "KiaraChickenChicken.h"
#include "../Lib/LP.h"
#include "../Lib/ID.h"

 KiaraChickenChicken::KiaraChickenChicken(sf::Vector2f position, Scene* scene)
{
    scene_ = scene;
    tag_ = "Chicken";
    name_ = "Chicken";
    layerID_ = main_layer;
    position_ = position;
    velocity_ = sf::Vector2f(-(rand() % 2000 + 500), rand() % 1000 + 500);
    angleVelocity_ = rand() % 1000 + 100;
    imageWidth_ = 59;
    imageHeight_ = 90;
    SetLeft(-imageWidth_/2);
    SetRight(imageWidth_/2);
    SetTop(-imageHeight_/2);
    SetBottom(imageHeight_/2);

    sprite_ = LP::SetSprite(kiara_chicken_chicken_image, position_);
    LP::SetSpriteOriginCenter(&sprite_);
}

 KiaraChickenChicken::~KiaraChickenChicken()
{}

void  KiaraChickenChicken::Update(float delta_time)
{
    position_ += velocity_ * delta_time;
    sprite_.setPosition(position_);
    angle_ += angleVelocity_ * delta_time;
    sprite_.setRotation(angle_);
}

void  KiaraChickenChicken::Draw(sf::RenderWindow& render_window) const
{
    render_window.setView(*scene_->FindView("Main"));
    render_window.draw(sprite_);
}

void  KiaraChickenChicken::ReactOnCollision(GameObject& other)
{
    if (other.GetTag() == "Player") Kill();
}