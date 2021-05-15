#include "KiaraLoadingBackground.h"
#include "../Lib/LP.h"
#include "../Lib/ID.h"

KiaraLoadingBackground::KiaraLoadingBackground(Scene* scene)
{
    scene_ = scene;
    tag_ = "Player";
    name_ = "Kiara";
    layerID_ = background_layer;
    position_ = sf::Vector2f(0.0f, 0.0f);
    imageWidth_ = 1920.0f;
    imageHeight_ = 1080.0f;
    SetActive(false);

    sprite_ = LP::SetSprite(kiara_chicken_background_image, position_);
}

KiaraLoadingBackground::~KiaraLoadingBackground()
{}

void KiaraLoadingBackground::Draw(sf::RenderWindow& render_window) const
{
    render_window.setView(*scene_->FindView("Main"));
    render_window.draw(sprite_);
}