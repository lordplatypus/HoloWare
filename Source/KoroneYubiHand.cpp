#include "../Header/KoroneYubiHand.h"
#include "../Header/LP.h"
#include "../Header/ID.h"

KoroneYubiHand::KoroneYubiHand(sf::Vector2f position, int ID, KoroneYubiManager* kym, Scene* scene)
{
    scene_ = scene;
    kym_ = kym;
    position_ = position;
    name_ = "Hand";
    tag_ = "Hand";
    ID_ = ID;
    imageWidth_ = 68;
    imageHeight_ = 64;

    if (ID_ % 2 == 0) sprites_ = LP::SetSprite(korone_yubi_left_hand_image, imageWidth_, imageHeight_, 6, 1);
    else sprites_ = LP::SetSprite(korone_yubi_right_hand_image, imageWidth_, imageHeight_, 6, 1);
    for (auto sprite : sprites_) LP::SetSpriteScale(sprite, 2.0f, 2.0f);
}

KoroneYubiHand::~KoroneYubiHand()
{
    for (auto sprite : sprites_) LP::DeleteSprite(sprite);
}

void KoroneYubiHand::Update(float delta_time)
{
    if (kym_->GetActiveHand() == ID_) InputHandle();
}

void KoroneYubiHand::Draw()
{
    LP::DrawSprite(sprites_[frame_], position_);
}

void KoroneYubiHand::InputHandle()
{
    if (!spacePressed_ && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) 
    {
        if (frame_ < 4) frame_++;
        else
        { 
            frame_++;
            kym_->SetActiveHand(ID_+1);
        }
        spacePressed_ = true;
    }

    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) spacePressed_ = false;
}