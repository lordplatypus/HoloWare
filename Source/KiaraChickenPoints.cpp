#include "../Header/KiaraChickenPoints.h"
#include "../Header/LP.h"

KiaraChickenPoints::KiaraChickenPoints(sf::Vector2f position, Scene* scene)
{
    scene_ = scene;
    tag_ = "KiaraChickenPoints";
    name_ = "KiaraChickenPoints";
    position_ = position;
    velocity_ = sf::Vector2f(2000.0f, 2000.0f);

    text_ = LP::SetText("+" + std::to_string(100), position_, 64);
}

KiaraChickenPoints::~KiaraChickenPoints()
{
    LP::DeleteText(text_);
}

void KiaraChickenPoints::Update(float delta_time)
{
    if (position_.y < 1080 - 50 - 64) position_.y += velocity_.y * delta_time;
    else
    {
        position_.y = 1080 - 50 - 64;
        LP::SetTextColor(text_, 255, 255, 255, alpha_);
        timer_ -= delta_time;
        if (timer_ <= 0.0f)
        {
            alpha_--;
            if (alpha_ <= 0.0f) Kill();
            timer_ = 0.005f;
        }
    }

    LP::SetTextPosition(text_, position_);
}

void KiaraChickenPoints::Draw()
{
    LP::DrawText(text_);
}