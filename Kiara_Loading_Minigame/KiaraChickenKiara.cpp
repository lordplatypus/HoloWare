#include "KiaraChickenKiara.h"
#include "../Lib/LP.h"
#include "../Lib/ID.h"
#include "KiaraChickenPoints.h"

KiaraChickenKiara::KiaraChickenKiara(sf::Vector2f position, Scene* scene)
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

    playerSprite_ = LP::SetSprite(kiara_chicken_kiara_image, 1142 / 2, 1043, 2, 1);
    shadowSprite_ = LP::SetSprite(kiara_chicken_shadow_image, sf::Vector2f(position_.x, position_.y + imageHeight_));

    score_ = new KiaraChickenScore(sf::Vector2f(50.0f, 50.0f));
}

KiaraChickenKiara::~KiaraChickenKiara()
{
    for (auto i : playerSprite_) LP::DeleteSprite(i);
    LP::DeleteSprite(shadowSprite_);
    delete score_;
}

void KiaraChickenKiara::Update(float delta_time)
{
    if (stun_) StunHandle(delta_time);
    else
    {
        InputHandle(delta_time);
        AnimationHandle(delta_time);
    }
}

void KiaraChickenKiara::Draw()
{
    if (!blink_)
    {
        LP::DrawSprite(shadowSprite_, sf::Vector2f(position_.x, position_.y + imageHeight_ - 50));
        LP::DrawSprite(playerSprite_[frame_], position_);
    }
    score_->Draw();
}

void KiaraChickenKiara::ReactOnCollision(GameObject& other)
{
    if (other.GetTag() == "Chicken")
    {
        score_->AddToScore(100);
        scene_->AddGameObject(new KiaraChickenPoints(sf::Vector2f(1920 - 300, 0), scene_));
        scene_->OnWin();
    }
    else if (other.GetTag() == "Rock")
    {
        stun_ = true;
        stunTimer_ = 0.5f;
    }
}

void KiaraChickenKiara::InputHandle(float delta_time)
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

void KiaraChickenKiara::AnimationHandle(float delta_time)
{
    timer_ += delta_time;
    if (timer_ >= 0.3f)
    {
        if (frame_ == 0) frame_ = 1;
        else frame_ = 0;
        timer_ = 0.0f;
    }
}

void KiaraChickenKiara::StunHandle(float delta_time)
{
    blinkTimer_ -= delta_time;
    if (blinkTimer_ <= 0.0f)
    {
        if (blink_) blink_ = false;
        else blink_ = true;
        blinkTimer_ = 0.05f;
    }

    stunTimer_ -= delta_time;
    if (stunTimer_ <= 0.0f)
    {
        stun_ = false;
        blink_ = false;
    }
}