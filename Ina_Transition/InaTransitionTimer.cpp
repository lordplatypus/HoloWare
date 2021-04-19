#include "InaTransitionTimer.h"
#include "../Lib/LP.h"
#include "../Lib/ID.h"
#include "InaTransitionDoorClose.h"
#include <cmath>

InaTransitionTimer::InaTransitionTimer(sf::Vector2f position, float sec, Scene* scene)
{
    scene_ = scene;
    tag_ = "Timer";
    name_ = "InaTimer";
    layerID_ = timer_layer;
    position_ = position;
    sec_ = sec;
    if (sec_ - floor(sec_) > 0.0f) timer_ = sec_ - floor(sec_);
    //scale_= scale / 2.0f;

    end_ = LP::SetSprite(ina_transition_timer_end_image, position_);
    for (int i = 0; i < ceil(sec_); i++)
    {
        segments_.push_back(LP::SetSprite(ina_transition_timer_segment_image, sf::Vector2f(position_.x + 64 + 128 * i, position_.y)));
    }
    bomb_ = LP::SetSprite(ina_transition_timer_bomb_image, sf::Vector2f(position_.x + 64 + 128 * segments_.size(), position_.y));
    explosion_ = LP::SetSprite(transition_explosion_image, sf::Vector2f(position_.x + 32, position_.y + 32));
    LP::SetSpriteOriginCenter(&explosion_);
}

InaTransitionTimer::~InaTransitionTimer()
{}

void InaTransitionTimer::Update(float delta_time)
{
    timer_ -= delta_time;
    if (timer_ <= 0.0f)
    {
        timer_ = 1.0f;
        if (segments_.size() > 0)
        {
            segments_.pop_back();
            bomb_.setPosition(sf::Vector2f(position_.x + 64 + 128 * segments_.size(), position_.y));
        }
        else if (deathSequence_)
        {
            Kill();
            scene_->AddGameObject(new InaTransitionDoorClose(scene_));
        }
        else deathSequence_ = true;
    }
}

void InaTransitionTimer::Draw(sf::RenderWindow& render_window) const
{
    render_window.setView(*scene_->FindView("Transition"));
    
    render_window.draw(end_);
    for (auto segment : segments_) render_window.draw(segment);
    if (!deathSequence_) render_window.draw(bomb_);
    if (deathSequence_) render_window.draw(explosion_);

    render_window.setView(*scene_->FindView("Main"));
}