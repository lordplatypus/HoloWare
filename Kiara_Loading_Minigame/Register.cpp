#include "Register.h"
#include "../Lib/LP.h"
#include "../Lib/ID.h"

Register::Register(sf::Vector2f position, ParticleManager* pm, Scene* scene)
{
    scene_ = scene;
    pm_ = pm;
    tag_ = "Register";
    name_ = "Register";
    layerID_ = background_layer;
    position_ = position;
    imageWidth_ = 61;
    imageHeight_ = 42;

    SetActive(false);

    sprites_ = LP::SetMultiFrameSprite(kiara_chicken_register_image, 61, 42, 11, 1);
    for (int i = 0; i < sprites_.size(); i++) sprites_[i].setPosition(position_);
}

Register::~Register()
{}

void Register::Update(float delta_time)
{
    AnimationHandle(delta_time);
}

void Register::Draw(sf::RenderWindow& render_window) const
{
    render_window.setView(*scene_->FindView("Main"));
    render_window.draw(sprites_[frame_]);
}

void Register::SetOutcome(const bool& outcome)
{
    if (outcome) state_ = hype;
    else state_ = normal;
}

void Register::AnimationHandle(float delta_time)
{
    timer_ += delta_time;
    if (state_ == normal && timer_ >= maxTime_)
    {
        if (frame_ == 0) frame_ = 1;
        else frame_ = 0;
        timer_ = 0.0f;
        maxTime_ = (rand() % 3 + 3) / 10.0f;
    }
    else if (state_ == hype && timer_ >= maxTime_)
    {
        if (frame_ < 10) frame_++;
        else 
        {
            frame_ = 2;
            pm_->Money(sf::Vector2f(position_.x + imageWidth_ / 2, position_.y + imageHeight_ - 10), scene_);
        }
        timer_ = 0.0f;
        maxTime_ = 0.2f;
    }
}