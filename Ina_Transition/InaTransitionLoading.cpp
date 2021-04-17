#include "InaTransitionLoading.h"
#include "../Lib/LP.h"
#include "../Lib/ID.h"

InaTransitionLoading::InaTransitionLoading(sf::Vector2f position, Scene* scene)
{
    scene_ = scene;
    tag_ = "Loading";
    name_ = "InaLoading";
    position_ = position;
    imageWidth_ = 32;
    imageHeight_ = 32;

    letterSprites_ = LP::SetSprite(ina_transition_loading_image, imageWidth_, imageHeight_, 10, 1);
    scales_.push_back(0.5f);
    for (int i = 1; i < letterSprites_.size(); i++) scales_.push_back(1.0f);

    for (auto i : letterSprites_) LP::SetSpriteOriginCenter(i);
    LP::SetSpriteScale(letterSprites_[0], scales_[0], scales_[0]);
}

InaTransitionLoading::~InaTransitionLoading()
{
    for (auto i : letterSprites_) LP::DeleteSprite(i);
}

void InaTransitionLoading::Update(float delta_time)
{
    timer_ += delta_time;
    if (timer_ >= 0.2f)
    {
        scales_[num_] = 1.0f;
        LP::SetSpriteScale(letterSprites_[num_], scales_[num_], scales_[num_]);
        if (num_+1 < scales_.size()) num_++;
        else num_ = 0;
        scales_[num_] = 0.5f;
        LP::SetSpriteScale(letterSprites_[num_], scales_[num_], scales_[num_]);
        timer_ = 0.0f;
    }
}

void InaTransitionLoading::Draw()
{
    for (int i = 0; i < letterSprites_.size(); i++) LP::DrawSprite(letterSprites_[i], sf::Vector2f(position_.x + i * 32, position_.y));
}

void InaTransitionLoading::ReactOnCollision(GameObject& other)
{}