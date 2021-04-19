#include "InaTransitionHP.h"
#include "../Lib/LP.h"
#include "../Lib/ID.h"

InaTransitionHP::InaTransitionHP(sf::Vector2f position, Scene* scene)
{
    scene_ = scene;
    tag_ = "HPIcon";
    name_ = "Tako";
    layerID_ = main_layer;
    position_ = position;
    imageWidth_ = 64;
    imageHeight_ = 64;

    takoSprite_ = LP::SetMultiFrameSprite(ina_transition_hp_image, imageWidth_, imageHeight_, 4, 1);
    for (auto sprite : takoSprite_) 
    {
        LP::SetSpriteOriginCenter(&sprite);
        sprite.setPosition(position_);
        sprite.setRotation(angle_);
    }
}

InaTransitionHP::~InaTransitionHP()
{}

void InaTransitionHP::Update(float delta_time)
{
    AnimationHandle(delta_time);
    ScaleHandle(delta_time);

    if (angle_ > 40.0f || angle_ < -40.0f) endAngle_ = -endAngle_;

    if(angle_ != endAngle_) 
    {
        angle_ = math_.Lerp(angle_, endAngle_, delta_time * 3.5f);
        for (auto sprite : takoSprite_) sprite.setRotation(angle_);
    }
}

void InaTransitionHP::Draw(sf::RenderWindow& render_window) const
{
    render_window.setView(*scene_->FindView("Transition"));
    render_window.draw(takoSprite_[frame_]);
    render_window.setView(*scene_->FindView("Main"));
}

void InaTransitionHP::ReactOnCollision(GameObject& other)
{}

void InaTransitionHP::AnimationHandle(float delta_time)
{
    timer_ += delta_time;
    if (timer_ >= 1.0f)
    {
        if (frame_ == 0) frame_ = 1;
        else frame_ = 0;
        timer_ = 0.0f;
    }
}

void InaTransitionHP::ScaleHandle(float delta_time)
{
    scaleTimer_ += delta_time;
    if (scaleTimer_ >= 0.5f)
    {
        if (scale_ == 1.0f) scale_ = 0.5f;
        else scale_ = 1.0f;

        for (auto sprite : takoSprite_) sprite.setScale(scale_, scale_);
        scaleTimer_ = 0.0f;
    }
}