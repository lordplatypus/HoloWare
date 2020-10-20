#include "../Header/InaLoading.h"
#include "../Header/LP.h"
#include "../Header/ID.h"

InaLoading::InaLoading(sf::Vector2f position, Scene* scene)
{
    scene_ = scene;
    tag_ = "Loading";
    name_ = "InaLoading";
    position_ = position;
    imageWidth_ = 32;
    imageHeight_ = 32;

    letterSprites_ = LP::SetSprite(ina_loading_image, imageWidth_, imageHeight_, 10, 1);
    // scales_.push_back(0.5f);
    // for (int i = 1; i < sprites_.size(); i++) scales_.push_back(1.0f);

    // for (auto i : sprites_) LP::SetSpriteOriginCenter(i);
    // LP::SetSpriteScale(sprites_[0], scales_[0], scales_[0]);
}

InaLoading::~InaLoading()
{
    for (auto i : letterSprites_) LP::DeleteSprite(i);
}

void InaLoading::Update(float delta_time)
{
    // timer_ += delta_time;
    // if (timer_ >= 0.2f)
    // {
    //     scales_[num_] = 1.0f;
    //     LP::SetSpriteScale(sprites_[num_], scales_[num_], scales_[num_]);
    //     if (num_+1 < scales_.size()) num_++;
    //     else num_ = 0;
    //     scales_[num_] = 0.5f;
    //     LP::SetSpriteScale(sprites_[num_], scales_[num_], scales_[num_]);
    //     timer_ = 0.0f;
    // }
}

void InaLoading::Draw()
{
    for (auto i : letterSprites_) LP::DrawSprite(i, sf::Vector2f(position_.x + i * 32, position_.y));
}

void InaLoading::ReactOnCollision(GameObject& other)
{}