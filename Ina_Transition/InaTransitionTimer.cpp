#include "InaTransitionTimer.h"
#include "../Lib/LP.h"
#include "../Lib/ID.h"
#include "InaTransitionDoorClose.h"
#include <cmath>

InaTransitionTimer::InaTransitionTimer(sf::Vector2f position, float sec, Camera* camera, Scene* scene, float scale)
{
    scene_ = scene;
    camera_ = camera;
    tag_ = "Timer";
    name_ = "InaTimer";
    position_ = position;
    sec_ = sec;
    if (sec_ - floor(sec_) > 0.0f) timer_ = sec_ - floor(sec_);
    scale_= scale / 2.0f;

    end_ = LP::SetSprite(ina_transition_timer_end_image, position_);
    LP::SetSpriteScale(end_, scale_, scale_);
    for (int i = 0; i < ceil(sec_); i++)
    {
        segments_.push_back(LP::SetSprite(ina_transition_timer_segment_image, sf::Vector2f(position_.x + (64 * scale_) + (128 * scale_) * i, position_.y)));
        LP::SetSpriteScale(segments_[i], scale_, scale_);
    }
    bomb_ = LP::SetSprite(ina_transition_timer_bomb_image, sf::Vector2f(position_.x + (64 * scale_) + (128 * scale_) * segments_.size(), position_.y));
    LP::SetSpriteScale(bomb_, scale_, scale_);
    explosion_ = LP::SetSprite(transition_explosion_image, sf::Vector2f(position_.x + 32 * scale_, position_.y + 32 * scale_));
    LP::SetSpriteOriginCenter(explosion_);
    LP::SetSpriteScale(explosion_, scale_, scale_);
}

InaTransitionTimer::~InaTransitionTimer()
{
    for (auto segment : segments_) LP::DeleteSprite(segment);
    LP::DeleteSprite(end_);
    LP::DeleteSprite(bomb_);
    LP::DeleteSprite(explosion_);
}

void InaTransitionTimer::Update(float delta_time)
{
    timer_ -= delta_time;
    if (timer_ <= 0.0f)
    {
        timer_ = 1.0f;
        if (segments_.size() > 0)
        {
            LP::DeleteSprite(segments_.back());
            segments_.pop_back();
        }
        else if (deathSequence_)
        {
            Kill();
            scene_->AddGameObject(new InaTransitionDoorClose(camera_, scene_, scale_ * 2.0f));
        }
        else deathSequence_ = true;
    }
}

void InaTransitionTimer::Draw()
{
    LP::DrawSprite(end_);
    for (auto segment : segments_) LP::DrawSprite(segment);
    if (!deathSequence_) LP::DrawSprite(bomb_, sf::Vector2f(position_.x + (64 * scale_) + (128 * scale_) * segments_.size(), position_.y));
    if (deathSequence_) LP::DrawSprite(explosion_);
}