#include "KoroneYubiHand.h"
#include "../Lib/LP.h"
#include "../Lib/MP.h"
#include "../Lib/ID.h"
#include "../Lib/IP.h"

KoroneYubiHand::KoroneYubiHand(sf::Vector2f position, Scene* scene, int maxHands, int num)
{
    scene_ = scene;
    position_ = position;
    name_ = "Hand";
    tag_ = "Hand";
    layerID_ = main_layer;
    ID_ = num; //hand position within the group of hands
    maxHands_ = maxHands;
    imageWidth_ = 68;
    imageHeight_ = 64;

    if (ID_ % 2 == 0) sprites_ = LP::SetMultiFrameSprite(korone_yubi_left_hand_image, imageWidth_, imageHeight_, 6, 1);
    else sprites_ = LP::SetMultiFrameSprite(korone_yubi_right_hand_image, imageWidth_, imageHeight_, 6, 1);
    for (auto sprite : sprites_) 
    {
        sprite.setScale(2.0f, 2.0f);
        sprite.setPosition(position_);
    }

    if (num <= maxHands)
    {
        nextHand_ = new KoroneYubiHand(sf::Vector2f(scene_->FindView("Main")->getCenter().x - (136 * maxHands)/2 - 68 + 136 * ID_, scene_->FindView("Main")->getSize().y - 64*2), scene_, maxHands, ID_+1);
    }
}

KoroneYubiHand::~KoroneYubiHand()
{}

void KoroneYubiHand::Update(float delta_time)
{
    if (active_) InputHandle();
    if (ID_ != maxHands_) nextHand_->Update(delta_time);
}

void KoroneYubiHand::Draw(sf::RenderWindow& render_window) const
{
    render_window.draw(sprites_[frame_]);
    if (ID_ != maxHands_) nextHand_->Draw(render_window);
}

void KoroneYubiHand::SetActive()
{
    active_ = true;
}

void KoroneYubiHand::InputHandle()
{
    if (IP::PressSpace())
    {
        if (frame_ < 4) frame_++;
        else
        { 
            frame_++;
            if (ID_ != maxHands_) nextHand_->SetActive();
            active_ = false;
        }
        MP::PlaySound(pop_se);
    }
}