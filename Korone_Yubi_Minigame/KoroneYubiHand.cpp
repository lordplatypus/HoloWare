#include "KoroneYubiHand.h"
#include "KoroneYubiStream.h"
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
    if (ID_ == 0) activeHand_ = true;
    maxHands_ = maxHands;
    imageWidth_ = 68;
    imageHeight_ = 64;
    SetActive(false);

    if (ID_ % 2 == 0) sprites_ = LP::SetMultiFrameSprite(korone_yubi_left_hand_image, imageWidth_, imageHeight_, 6, 1);
    else sprites_ = LP::SetMultiFrameSprite(korone_yubi_right_hand_image, imageWidth_, imageHeight_, 6, 1);
    for (int i = 0; i < sprites_.size(); i++) 
    {
        sprites_[i].setScale(2.0f, 2.0f);
        sprites_[i].setPosition(position_);
    }

    if (num < maxHands)
    {
        nextHand_ = new KoroneYubiHand(sf::Vector2f(scene_->FindView("Main")->getCenter().x - (136 * maxHands)/2 - 68 + 136 * ID_, scene_->FindView("Main")->getSize().y - 64*2), scene_, maxHands, ID_+1);
    }
}

KoroneYubiHand::~KoroneYubiHand()
{
    delete nextHand_;
}

void KoroneYubiHand::Update(float delta_time)
{
    if (activeHand_) InputHandle();
    if (ID_ != maxHands_) nextHand_->Update(delta_time);
}

void KoroneYubiHand::Draw(sf::RenderWindow& render_window) const
{
    render_window.draw(sprites_[frame_]);
    if (ID_ != maxHands_) nextHand_->Draw(render_window);
}

void KoroneYubiHand::SetActiveHand()
{
    activeHand_ = true;
}

void KoroneYubiHand::InputHandle()
{
    if (IP::PressSpace())
    {
        if (frame_ < 4) frame_++;
        else
        { 
            frame_++;
            if (ID_ != maxHands_) nextHand_->SetActiveHand();
            else 
            {
                scene_->AddGameObject(new KoroneYubiStream(sf::Vector2f(0.0f, 0.0f), scene_));
                scene_->SetOutcome(true);
            }
            activeHand_ = false;
        }
        MP::PlaySound(pop_se);
    }
}