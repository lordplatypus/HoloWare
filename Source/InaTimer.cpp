#include "../Header/InaTimer.h"
#include "../Header/LP.h"
#include "../Header/ID.h"

InaTimer::InaTimer(sf::Vector2f position, int sec, float scale, Scene* scene)
{
    scene_ = scene;
    tag_ = "Timer";
    name_ = "InaTimer";
    position_ = position;
    sec_ = sec;

    end_ = LP::SetSprite(ina_timer_end_image, position_);
    for (int i = 0; i < sec_; i++)
    {
        segments_.push_back(LP::SetSprite(ina_timer_segment_image, sf::Vector2f(position_.x + 64 + 128 * i, position_.y)));
    }
    bomb_ = LP::SetSprite(ina_timer_bomb_image, sf::Vector2f(position_.x + 64 + 128 * segments_.size(), position_.y));
}

InaTimer::~InaTimer()
{
    for (auto segment : segments_) LP::DeleteSprite(segment);
    LP::DeleteSprite(end_);
    LP::DeleteSprite(bomb_);
}

void InaTimer::Update(float delta_time)
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
    }
}

void InaTimer::Draw()
{
    LP::DrawSprite(end_);
    for (auto segment : segments_) LP::DrawSprite(segment);
    LP::DrawSprite(bomb_, sf::Vector2f(position_.x + 64 + 128 * segments_.size(), position_.y));
}