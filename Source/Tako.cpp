#include "../Header/Tako.h"
#include "../Header/LP.h"
#include "../Header/ID.h"

Tako::Tako(sf::Vector2f position, Scene* scene)
{
    scene_ = scene;
    tag_ = "HPIcon";
    name_ = "Tako";
    position_ = position;
    imageWidth_ = 64;
    imageHeight_ = 64;

    takoSprite_ = LP::SetSprite(tako_image, imageWidth_, imageHeight_, 4, 1);
    for (auto i : takoSprite_) 
    {
        LP::SetSpriteOriginCenter(i);
        LP::SetSpriteRotation(i, angle_);
    }
}

Tako::~Tako()
{
    for (auto i : takoSprite_) LP::DeleteSprite(i);
}

void Tako::Update(float delta_time)
{
    AnimationHandle(delta_time);
    ScaleHandle(delta_time);

    if (angle_ > 40.0f || angle_ < -40.0f) endAngle_ = -endAngle_;

    if(angle_ != endAngle_) 
    {
        angle_ = math_.Lerp(angle_, endAngle_, delta_time * 3.5f);
        for (auto i : takoSprite_) LP::SetSpriteRotation(i, angle_);
    }
}

void Tako::Draw()
{
    LP::DrawSprite(takoSprite_[frame_], position_);
}

void Tako::ReactOnCollision(GameObject& other)
{}

void Tako::AnimationHandle(float delta_time)
{
    timer_ += delta_time;
    if (timer_ >= 1.0f)
    {
        if (frame_ == 0) frame_ = 1;
        else frame_ = 0;
        timer_ = 0.0f;
    }
}

void Tako::ScaleHandle(float delta_time)
{
    scaleTimer_ += delta_time;
    if (scaleTimer_ >= 0.5f)
    {
        if (scale_ == 1.0f) scale_ = 0.5f;
        else scale_ = 1.0f;

        for (auto i : takoSprite_) LP::SetSpriteScale(i, scale_, scale_);
        scaleTimer_ = 0.0f;
    }
}