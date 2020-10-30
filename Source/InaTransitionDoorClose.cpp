#include "../Header/InaTransitionDoorClose.h"
#include "../Header/LP.h"
#include "../Header/MP.h"
#include "../Header/ID.h"

InaTransitionDoorClose::InaTransitionDoorClose(Camera* camera, Scene* scene, float scale)
{
    scene_ = scene;
    camera_ = camera;
    tag_ = "Transition";
    name_ = "InaDoorClose";
    scale_ = scale;
    imageWidth_ = 240 * scale;
    imageHeight_ = 270 * scale;
    positionRight_ = sf::Vector2f(camera_->GetCameraRightEdge(), camera_->GetCameraTopEdge());
    endPositionRight_ = sf::Vector2f(camera_->GetCameraCenter().x, camera_->GetCameraTopEdge());
    positionLeft_ = sf::Vector2f(camera_->GetCameraLeftEdge() - imageWidth_, camera_->GetCameraTopEdge());
    endPositionLeft_ = sf::Vector2f(camera_->GetCameraLeftEdge(), camera_->GetCameraTopEdge());

    spriteRight_ = LP::SetSprite(ina_transition_door_image, positionRight_);
    LP::SetSpriteScale(spriteRight_, scale_, scale_);
    spriteLeft_ = LP::SetSprite(ina_transition_door_image, positionLeft_);
    LP::SetSpriteScale(spriteLeft_, scale_, scale_);

    MP::PlaySound(whoosh_se);
}

InaTransitionDoorClose::~InaTransitionDoorClose()
{
    LP::DeleteSprite(spriteRight_);
    LP::DeleteSprite(spriteLeft_);
}

void InaTransitionDoorClose::Update(float delta_time)
{
    if (positionRight_ != endPositionRight_) positionRight_ = math_.Lerp(positionRight_, endPositionRight_, 10 * scale_ * delta_time);
    if (positionLeft_ != endPositionLeft_) positionLeft_ = math_.Lerp(positionLeft_, endPositionLeft_, 10 * scale_ * delta_time);

    if (!thud_ && positionRight_.x < endPositionRight_.x + .3f) 
    {
        MP::PlaySound(thud_se);
        thud_ = true;
    }

    timer_ -= delta_time;
    if (timer_ <= 0.0f) scene_->ChangeScene();
}

void InaTransitionDoorClose::Draw()
{
    LP::DrawSprite(spriteRight_, positionRight_);
    LP::DrawSprite(spriteLeft_, positionLeft_);
}