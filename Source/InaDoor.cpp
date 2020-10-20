#include "../Header/InaDoor.h"
#include "../Header/LP.h"
#include "../Header/ID.h"

InaDoor::InaDoor(sf::Vector2f position, sf::Vector2f endPosition, Scene* scene)
{
    scene_ = scene;
    tag_ = "Transition";
    name_ = "InaDoor";
    position_ = position;
    endPosition_ = endPosition;
    imageWidth_ = 240;
    imageHeight_ = 270;
    SetLeft(0);
    SetTop(0);
    SetRight(imageWidth_);
    SetBottom(imageHeight_);

    sprite_ = LP::SetSprite(ina_door_image, position_);
}

InaDoor::~InaDoor()
{
    LP::DeleteSprite(sprite_);
}

void InaDoor::Update(float delta_time)
{
    if (position_ != endPosition_) position_ = math_.Lerp(position_, endPosition_, 10 * delta_time);
    StorePosition();
}

void InaDoor::Draw()
{
    LP::DrawSprite(sprite_, position_);
}

void InaDoor::ReactOnCollision(GameObject& other)
{
    if (other.GetTag() == "Transition")
    {
        position_ = GetPrevPosition();
    }
}