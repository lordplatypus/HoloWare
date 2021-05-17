#include "Points.h"
#include "../Lib/LP.h"
#include "../Lib/ID.h"

Points::Points(sf::Vector2f position, Scene* scene)
{
    scene_ = scene;
    tag_ = "Points";
    name_ = "Points";
    layerID_ = minigame_UI_layer;
    position_ = position;
    velocity_ = sf::Vector2f(500.0f, 500.0f);

    text_ = LP::SetText("+" + std::to_string(100), position_, 64);
    text_.setScale(0.3f, 0.3f);
}

Points::~Points()
{}

void Points::Update(float delta_time)
{
    if (position_.y < 270 - 30) position_.y += velocity_.y * delta_time;
    else
    {
        position_.y = 270 - 30;
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

void Points::Draw(sf::RenderWindow& render_window) const
{
    render_window.draw(text_);
}