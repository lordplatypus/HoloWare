#include "../Header/InaTransitionTimer.h"
#include "../Header/LP.h"
#include "../Header/ID.h"
#include "../Header/InaTransitionDoorClose.h"

InaTransitionTimer::InaTransitionTimer(sf::Vector2f position, int sec, Camera* camera, Scene* scene, float scale)
{
    scene_ = scene;
    camera_ = camera;
    tag_ = "Timer";
    name_ = "InaTimer";
    position_ = position;
    sec_ = sec;
    scale_= scale;

    end_ = LP::SetSprite(ina_transition_timer_end_image, position_);
    for (int i = 0; i < sec_; i++)
    {
        segments_.push_back(LP::SetSprite(ina_transition_timer_segment_image, sf::Vector2f(position_.x + 64 + 128 * i, position_.y)));
    }
    bomb_ = LP::SetSprite(ina_transition_timer_bomb_image, sf::Vector2f(position_.x + 64 + 128 * segments_.size(), position_.y));
    explosion_ = LP::SetSprite(transition_explosion_image, sf::Vector2f(position_.x + 32, position_.y + 32));
    LP::SetSpriteOriginCenter(explosion_);
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
            scene_->AddGameObject(new InaTransitionDoorClose(camera_, scene_, scale_));
        }
        else 
        {
            deathSequence_ = true;
            scene_->OnLoss();
        }
    }
}

void InaTransitionTimer::Draw()
{
    LP::DrawSprite(end_);
    for (auto segment : segments_) LP::DrawSprite(segment);
    if (!deathSequence_) LP::DrawSprite(bomb_, sf::Vector2f(position_.x + 64 + 128 * segments_.size(), position_.y));
    if (deathSequence_) LP::DrawSprite(explosion_);
}