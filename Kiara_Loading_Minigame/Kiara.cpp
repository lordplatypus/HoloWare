#include "Kiara.h"
#include "../Lib/LP.h"
#include "../Lib/ID.h"
#include "../Lib/IP.h"
#include "Points.h"

Kiara::Kiara(const sf::Vector2f& position, int difficulty, ParticleManager* pm, Scene* scene)
{
    scene_ = scene;
    pm_ = pm;
    tag_ = "Player";
    name_ = "Kiara";
    layerID_ = main_layer;
    position_ = position;
    difficulty_ = difficulty + 1;
    velocity_ = sf::Vector2f(300.0f, 300.0f);
    imageWidth_ = 22;
    imageHeight_ = 28;

    kiaraSprite_ = LP::SetMultiFrameSprite(kiara_chicken_kiara_image, 26, 50, 2, 1);
    for (int i = 0; i < kiaraSprite_.size(); i++) kiaraSprite_[i].setScale(2.0f, 2.0f);
    bucketSprite_ = LP::SetMultiFrameSprite(kiara_chicken_bucket_image, 11, 14, 5, 1);
    for (int i = 0; i < bucketSprite_.size(); i++) bucketSprite_[i].setScale(2.0f, 2.0f);
    shadowSprite_ = LP::SetSprite(kiara_chicken_shadow_image, sf::Vector2f(position_.x, position_.y + imageHeight_));
    shadowSprite_.setScale(2.0f, 2.0f);

    score_.SetPosition(sf::Vector2f(10.0f, 10.0f));
}

Kiara::~Kiara()
{}

void Kiara::Update(float delta_time)
{
    if (stun_) StunHandle(delta_time);
    else
    {
        InputHandle(delta_time);
        AnimationHandle(delta_time);
    }
}

void Kiara::Draw(sf::RenderWindow& render_window) const
{
    render_window.setView(*scene_->FindView("Main"));
    if (!blink_)
    {
        render_window.draw(shadowSprite_);
        render_window.draw(bucketSprite_[chickenCount_]);
        render_window.draw(kiaraSprite_[frame_]);
    }
    score_.Draw(render_window);
}

void Kiara::ReactOnCollision(GameObject& other)
{
    if (stun_) return;
    if (other.GetTag() == "Chicken")
    {
        score_.AddToScore(100);
        scene_->AddGameObject(new Points(sf::Vector2f(480 - 75, 0), scene_));
        if (chickenCount_ < 4) chickenCount_++;
        if (chickenCount_ >= difficulty_) scene_->SetOutcome(true); 
    }
    else if (other.GetTag() == "Rock")
    {
        stun_ = true;
        stunTimer_ = 0.5f;
    }
}

void Kiara::InputHandle(float delta_time)
{
    if (IP::GetButton(sf::Keyboard::Left))
    {
        position_.x -= velocity_.x * delta_time;
    }
    else if (IP::GetButton(sf::Keyboard::Right))
    {
        position_.x += velocity_.x * delta_time;
    }

    if (position_.x < 0.0f + 17.0f * 2) position_.x = 17.0f * 2;
    if (position_.x + imageWidth_ > 480) position_.x = 480 - imageWidth_;

    kiaraSprite_[frame_].setPosition(sf::Vector2f(position_.x - 17 * 2, position_.y - 22 * 2));
    bucketSprite_[chickenCount_].setPosition(position_);
    shadowSprite_.setPosition(sf::Vector2f(position_.x - 17 * 2, position_.y + 26 * 2));
}

void Kiara::AnimationHandle(float delta_time)
{
    timer_ += delta_time;
    if (timer_ >= 0.3f)
    {
        if (frame_ == 0) frame_ = 1;
        else frame_ = 0;
        timer_ = 0.0f;

        pm_->Sweat(sf::Vector2f(position_.x - 5 * 2, position_.y - 5 * 2), scene_);
    }
}

void Kiara::StunHandle(float delta_time)
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