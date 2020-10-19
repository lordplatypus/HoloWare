#include "../Header/Kiara.h"
#include "../Header/LP.h"
#include "../Header/ID.h"
#include "../Header/Points.h"

Kiara::Kiara(sf::Vector2f position, Scene* scene)
{
    scene_ = scene;
    tag_ = "Player";
    name_ = "Kiara";
    position_ = position;
    velocity_ = sf::Vector2f(1000.0f, 1000.0f);
    imageWidth_ = 1142 / 2;
    imageHeight_ = 1043;
    SetLeft(400);
    SetRight(400 + 150);
    SetTop(375);
    SetBottom(375 + 225);

    playerSprite_ = LP::SetSprite(kiara_image, 1142 / 2, 1043, 2, 1);
    shadowSprite_ = LP::SetSprite(shadow_image, sf::Vector2f(position_.x, position_.y + imageHeight_));

    score_ = new Score(sf::Vector2f(50.0f, 50.0f));
}

Kiara::~Kiara()
{
    for (auto i : playerSprite_) LP::DeleteSprite(i);
    LP::DeleteSprite(shadowSprite_);
    delete score_;
}

void Kiara::Update(float delta_time)
{
    InputHandle(delta_time);
    AnimationHandle(delta_time);
}

void Kiara::Draw()
{
    LP::DrawSprite(shadowSprite_, sf::Vector2f(position_.x, position_.y + imageHeight_ - 50));
    LP::DrawSprite(playerSprite_[frame_], position_);
    score_->Draw();
}

void Kiara::ReactOnCollision(GameObject& other)
{
    if (other.GetTag() == "Chicken")
    {
        score_->AddToScore(100);
        scene_->AddGameObject(new Points(sf::Vector2f(1920 - 300, 0), scene_));
    }
}

void Kiara::InputHandle(float delta_time)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        position_.x -= velocity_.x * delta_time;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        position_.x += velocity_.x * delta_time;
    }

    if (position_.x < 0.0f) position_.x = 0.0f;
    if (position_.x + imageWidth_ > 1920) position_.x = 1920 - imageWidth_;
}

void Kiara::AnimationHandle(float delta_time)
{
    timer_ += delta_time;
    if (timer_ >= 0.3f)
    {
        if (frame_ == 0) frame_ = 1;
        else frame_ = 0;
        timer_ = 0.0f;
    }
}