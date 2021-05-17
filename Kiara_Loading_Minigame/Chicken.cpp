#include "Chicken.h"
#include "../Lib/LP.h"
#include "../Lib/ID.h"

 Chicken::Chicken(sf::Vector2f position, Scene* scene)
{
    scene_ = scene;
    tag_ = "Chicken";
    name_ = "Chicken";
    layerID_ = main_layer;
    position_ = position;
    velocity_ = sf::Vector2f(-(rand() % 200 + 10), rand() % 100 + 50);
    angleVelocity_ = rand() % 100 + 10;
    imageWidth_ = 8;
    imageHeight_ = 5;

    sprite_ = LP::SetSprite(kiara_chicken_chicken_image, position_);
    LP::SetSpriteOriginCenter(&sprite_);
}

 Chicken::~Chicken()
{}

void  Chicken::Update(float delta_time)
{
    position_ += velocity_ * delta_time;
    sprite_.setPosition(position_);
    angle_ += angleVelocity_ * delta_time;
    sprite_.setRotation(angle_);
}

void  Chicken::Draw(sf::RenderWindow& render_window) const
{
    render_window.setView(*scene_->FindView("Main"));
    render_window.draw(sprite_);
}

void  Chicken::ReactOnCollision(GameObject& other)
{
    if (other.GetTag() == "Player") Kill();
}