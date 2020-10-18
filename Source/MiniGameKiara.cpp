#include "../Header/MiniGameKiara.h"
#include "../Header/LP.h"
#include "../Header/ID.h"
#include "../Header/Kiara.h"
#include "../Header/ChickenSpawner.h"

MiniGameKiara::MiniGameKiara()
{
    background_ = LP::SetSprite(background_image);
    gom_.Add(new Kiara(sf::Vector2f(0.0f, 30.0f), this));
    gom_.Add(new ChickenSpawner(this));
    //game_->PlayMusic(kiara_theme, true);
}

MiniGameKiara::~MiniGameKiara()
{
    LP::DeleteSprite(background_);
    gom_.Clear();
}

void MiniGameKiara::Update(float delta_time)
{
    gom_.Update(delta_time);
    gom_.Collision();
    gom_.Remove();
}

void MiniGameKiara::Draw()
{
    LP::DrawSprite(background_);
    gom_.Draw();
}