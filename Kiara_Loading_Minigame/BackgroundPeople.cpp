#include "BackgroundPeople.h"
#include "../Lib/LP.h"
#include "../Lib/ID.h"

BackgroundPeople::BackgroundPeople(sf::Vector2f position, Scene* scene)
{
    scene_ = scene;
    tag_ = "BackgroundPeople";
    name_ = "BackgroundPeople";
    layerID_ = background_layer;
    position_ = position;
    imageWidth_ = 32;
    imageHeight_ = 50;

    SetActive(false);

    sprites_ = LP::SetMultiFrameSprite(kiara_chicken_people_image, 32, 50, 4, 1);
    for (int i = 0; i < sprites_.size(); i++) sprites_[i].setPosition(position_);
}

BackgroundPeople::~BackgroundPeople()
{}

void BackgroundPeople::Update(float delta_time)
{
    AnimationHandle(delta_time);
}

void BackgroundPeople::Draw(sf::RenderWindow& render_window) const
{
    render_window.setView(*scene_->FindView("Main"));
    render_window.draw(sprites_[frame_]);
}

void BackgroundPeople::SetOutcome(const bool& outcome)
{
    if (outcome) 
    {
        state_ = hype;
        frame_ = 2;
    }
    else 
    {
        state_ = normal;
        frame_ = 0;
    }
}

void BackgroundPeople::AnimationHandle(float delta_time)
{
    timer_ += delta_time;
    if (timer_ >= maxTime_)
    {
        if (state_ == normal)
        {
            if (frame_ == 0) frame_ = 1;
            else frame_ = 0;
        }
        else if (state_ == hype)
        {
            if (frame_ == 2) frame_ = 3;
            else frame_ = 2;
        }
        timer_ = 0.0f;
        maxTime_ = (rand() % 3 + 3) / 10.0f;
    }
}