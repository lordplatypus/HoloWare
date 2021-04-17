#include "InaTransitionDoorOpen.h"
#include "../Lib/LP.h"
#include "../Lib/MP.h"
#include "../Lib/ID.h"

InaTransitionDoorOpen::InaTransitionDoorOpen(Camera* camera, Scene* scene, float scale)
{
    scene_ = scene;
    camera_ = camera;
    tag_ = "Transition";
    name_ = "InaDoorOpen";
    scale_ = scale;
    imageWidth_ = 240 * scale;
    imageHeight_ = 270 * scale;
    positionRight_ = sf::Vector2f(camera_->GetCameraCenter().x, camera_->GetCameraTopEdge());
    endPositionRight_ = sf::Vector2f(camera_->GetCameraRightEdge(), camera_->GetCameraTopEdge());
    positionLeft_ = sf::Vector2f(camera_->GetCameraLeftEdge(), camera_->GetCameraTopEdge());
    endPositionLeft_ = sf::Vector2f(camera_->GetCameraLeftEdge() - imageWidth_, camera_->GetCameraTopEdge());

    spriteRight_ = LP::SetSprite(ina_transition_door_image, positionRight_);
    LP::SetSpriteScale(spriteRight_, scale_, scale_);
    spriteLeft_ = LP::SetSprite(ina_transition_door_image, positionLeft_);
    LP::SetSpriteScale(spriteLeft_, scale_, scale_);

    MP::PlaySound(whoosh_se);
}

InaTransitionDoorOpen::~InaTransitionDoorOpen()
{
    LP::DeleteSprite(spriteRight_);
    LP::DeleteSprite(spriteLeft_);
}

void InaTransitionDoorOpen::Update(float delta_time)
{
    if (positionRight_ != endPositionRight_) positionRight_ = math_.Lerp(positionRight_, endPositionRight_, 10 * scale_ * delta_time);
    if (positionLeft_ != endPositionLeft_) positionLeft_ = math_.Lerp(positionLeft_, endPositionLeft_, 10 * scale_ * delta_time);

    timer_ -= delta_time;
    if (timer_ <= 0.0f) Kill();
}

void InaTransitionDoorOpen::Draw()
{
    LP::DrawSprite(spriteRight_, positionRight_);
    LP::DrawSprite(spriteLeft_, positionLeft_);
}