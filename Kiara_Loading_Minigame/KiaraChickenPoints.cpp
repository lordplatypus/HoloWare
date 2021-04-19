#include "KiaraChickenPoints.h"
#include "../Lib/LP.h"
#include "../Lib/ID.h"

KiaraChickenPoints::KiaraChickenPoints(sf::Vector2f position, Scene* scene)
{
    scene_ = scene;
    tag_ = "KiaraChickenPoints";
    name_ = "KiaraChickenPoints";
    layerID_ = minigame_UI_layer;
    position_ = position;
    velocity_ = sf::Vector2f(2000.0f, 2000.0f);

    text_ = LP::SetText("+" + std::to_string(100), position_, 64);
}

KiaraChickenPoints::~KiaraChickenPoints()
{}

void KiaraChickenPoints::Update(float delta_time)
{
    if (position_.y < 1080 - 50 - 64) position_.y += velocity_.y * delta_time;
    else
    {
        position_.y = 1080 - 50 - 64;
        text_.setFillColor(sf::Color(255, 255, 255, alpha_));
        timer_ -= delta_time;
        if (timer_ <= 0.0f)
        {
            alpha_--;
            if (alpha_ <= 0.0f) Kill();
            timer_ = 0.005f;
        }
    }

    text_.setPosition(position_);
}

void KiaraChickenPoints::Draw(sf::RenderWindow& render_window) const
{
    render_window.draw(text_);
}