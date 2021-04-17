#include "KoroneYubiStream.h"
#include "../Lib/LP.h"
#include "../Lib/ID.h"

KoroneYubiStream::KoroneYubiStream(sf::Vector2f position, Scene* scene)
{
    scene_ = scene;
    position_ = position;
    name_ = "Stream";
    tag_ = "Stream";

    streamSprite_ = LP::SetSprite(korone_yubi_stream_image, position_);
    laugh1Sprite_ = LP::SetSprite(korone_yubi_laugh1_image, position_);
    LP::SetSpriteOrigin(laugh1Sprite_, sf::Vector2f(-354, -185));
    laugh2Sprite_  = LP::SetSprite(korone_yubi_laugh2_image, position_);
    LP::SetSpriteOrigin(laugh2Sprite_, sf::Vector2f(-373, -146));
    chatSprite_  = LP::SetSprite(korone_yubi_chat_image, 75, 44, 7, 1);
    for (auto sprite : chatSprite_)
    {
        LP::SetSpriteOrigin(sprite, sf::Vector2f(-40, -226));
    }
}

KoroneYubiStream::~KoroneYubiStream()
{}

void KoroneYubiStream::Update(float delta_time)
{
    ChatHandle(delta_time);
    LaughHandle(delta_time);
}

void KoroneYubiStream::Draw()
{
    LP::DrawSprite(streamSprite_, position_);
    LP::DrawSprite(laugh1Sprite_, position_);
    LP::DrawSprite(laugh2Sprite_, position_);
    LP::DrawSprite(chatSprite_[chatFrame_], position_);
}

void KoroneYubiStream::ChatHandle(float delta_time)
{
    chatTimer_ -= delta_time;
    if (chatTimer_ < 0.0f)
    {
        chatFrame_++;
        if (chatFrame_ > 6) chatFrame_ = 0;
        chatTimer_ = (float)(rand() % 10) / 10.0f;
    }
}

void KoroneYubiStream::LaughHandle(float delta_time)
{
    laughTimer_ -= delta_time;
    if (laughTimer_ < 0.0f)
    {
        if (laughFrame_)
        {
            LP::SetSpriteOrigin(laugh1Sprite_, sf::Vector2f(-360, -185));
            LP::SetSpriteOrigin(laugh2Sprite_, sf::Vector2f(-373, -146));
            laughFrame_ = false;
        }
        else
        {
            LP::SetSpriteOrigin(laugh1Sprite_, sf::Vector2f(-354, -185));
            LP::SetSpriteOrigin(laugh2Sprite_, sf::Vector2f(-368, -141));
            laughFrame_ = true;
        }
        laughTimer_ = 0.3f;
    }
}