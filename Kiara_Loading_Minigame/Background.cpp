#include "Background.h"
#include "../Lib/LP.h"
#include "../Lib/ID.h"

Background::Background(Scene* scene)
{
    scene_ = scene;
    tag_ = "Background";
    name_ = "Background";
    layerID_ = background_layer;
    position_ = sf::Vector2f(0.0f, 0.0f);
    imageWidth_ = 480.0f;
    imageHeight_ = 270.0f;
    SetActive(false);

    sprite_ = LP::SetSprite(kiara_chicken_background_image, position_);
}

Background::~Background()
{}

void Background::Draw(sf::RenderWindow& render_window) const
{
    render_window.setView(*scene_->FindView("Main"));
    render_window.draw(sprite_);
}