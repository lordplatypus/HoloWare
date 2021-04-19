#include "InaTransitionDoorOpen.h"
#include "../Lib/LP.h"
#include "../Lib/MP.h"
#include "../Lib/ID.h"

InaTransitionDoorOpen::InaTransitionDoorOpen(Scene* scene)
{
    scene_ = scene;
    tag_ = "Transition";
    name_ = "InaDoorOpen";
    layerID_ = transition_layer;
    imageWidth_ = 240;
    imageHeight_ = 270;
    positionRight_ = sf::Vector2f(240.0f, 0.0f);
    endPositionRight_ = sf::Vector2f(480.0f, 0.0f);
    positionLeft_ = sf::Vector2f(0.0f, 0.0f);
    endPositionLeft_ = sf::Vector2f(-240.0f, 0.0f);

    spriteRight_ = LP::SetSprite(ina_transition_door_image, positionRight_);
    spriteLeft_ = LP::SetSprite(ina_transition_door_image, positionLeft_);

    MP::PlaySound(whoosh_se);
}

InaTransitionDoorOpen::~InaTransitionDoorOpen()
{}

void InaTransitionDoorOpen::Update(float delta_time)
{
    if (positionRight_ != endPositionRight_) positionRight_ = math_.Lerp(positionRight_, endPositionRight_, 10 * delta_time);
    if (positionLeft_ != endPositionLeft_) positionLeft_ = math_.Lerp(positionLeft_, endPositionLeft_, 10 * delta_time);

    timer_ -= delta_time;
    if (timer_ <= 0.0f) Kill();
}

void InaTransitionDoorOpen::Draw(sf::RenderWindow& render_window) const
{
    render_window.setView(*scene_->FindView("Transition"));
    render_window.draw(spriteRight_);
    render_window.draw(spriteLeft_);
    render_window.setView(*scene_->FindView("Main"));
}