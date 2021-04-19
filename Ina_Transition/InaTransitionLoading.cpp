#include "InaTransitionLoading.h"
#include "../Lib/LP.h"
#include "../Lib/ID.h"

InaTransitionLoading::InaTransitionLoading(sf::Vector2f position, Scene* scene)
{
    scene_ = scene;
    tag_ = "Loading";
    name_ = "InaLoading";
    layerID_ = main_layer;
    position_ = position;
    imageWidth_ = 32;
    imageHeight_ = 32;

    letterSprites_ = LP::SetMultiFrameSprite(ina_transition_loading_image, imageWidth_, imageHeight_, 10, 1);
    scales_.push_back(0.5f);
    for (int i = 1; i < letterSprites_.size(); i++) scales_.push_back(1.0f);

    for (int i = 0; i < letterSprites_.size(); i++) letterSprites_[i].setPosition(position_.x + i * 32, position_.y);

    for (auto sprite : letterSprites_) LP::SetSpriteOriginCenter(&sprite);
    letterSprites_[0].setScale(scales_[0], scales_[0]);
}

InaTransitionLoading::~InaTransitionLoading()
{}

void InaTransitionLoading::Update(float delta_time)
{
    timer_ += delta_time;
    if (timer_ >= 0.2f)
    {
        scales_[num_] = 1.0f;
        letterSprites_[num_].setScale(scales_[num_], scales_[num_]);
        if (num_+1 < scales_.size()) num_++;
        else num_ = 0;
        scales_[num_] = 0.5f;
        letterSprites_[num_].setScale(scales_[num_], scales_[num_]);
        timer_ = 0.0f;
    }
}

void InaTransitionLoading::Draw(sf::RenderWindow& render_window) const
{
    render_window.setView(*scene_->FindView("Transition"));
    for (auto sprite : letterSprites_) render_window.draw(sprite);
    render_window.setView(*scene_->FindView("Main"));
}