#include "InaTransitionDoor.h"
#include "../Lib/LP.h"
#include "../Lib/ID.h"

InaTransitionDoor::InaTransitionDoor(sf::Vector2f position, sf::Vector2f endPosition, Scene* scene, float scale)
{
    scene_ = scene;
    tag_ = "Transition";
    name_ = "InaDoor";
    layerID_ = transition_layer;
    position_ = position;
    endPosition_ = endPosition;
    scale_ = scale;
    imageWidth_ = 240;
    imageHeight_ = 270;
    // SetLeft(0);
    // SetTop(0);
    // SetRight(imageWidth_);
    // SetBottom(imageHeight_);

    sprite_ = LP::SetSprite(ina_transition_door_image, position_);
    //LP::SetSpriteScale(sprite_, scale_, scale_);
}

InaTransitionDoor::~InaTransitionDoor()
{}

void InaTransitionDoor::Update(float delta_time)
{
    if (position_ != endPosition_) 
    {
        position_ = math_.Lerp(position_, endPosition_, 10 * delta_time);
        StorePosition();
        sprite_.setPosition(position_);
    } 
}

void InaTransitionDoor::Draw(sf::RenderWindow& render_window) const
{
    render_window.setView(*scene_->FindView("Transition"));
    render_window.draw(sprite_);
    render_window.setView(*scene_->FindView("Main"));
}

void InaTransitionDoor::ReactOnCollision(GameObject& other)
{
    if (other.GetTag() == "Transition")
    {
        position_ = GetPrevPosition();
    }
}