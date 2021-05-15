#include "KoroneYubiStream.h"
#include "../Lib/LP.h"
#include "../Lib/ID.h"

KoroneYubiStream::KoroneYubiStream(sf::Vector2f position, Scene* scene)
{
    scene_ = scene;
    position_ = position;
    name_ = "Stream";
    tag_ = "Stream";
    layerID_ = main_layer;

    streamSprite_ = LP::SetSprite(korone_yubi_stream_image, position_);
    laugh1Sprite_ = LP::SetSprite(korone_yubi_laugh1_image, position_);
    laugh1Sprite_.setOrigin(sf::Vector2f(-354, -185));
    laugh2Sprite_  = LP::SetSprite(korone_yubi_laugh2_image, position_);
    laugh2Sprite_.setOrigin(sf::Vector2f(-373, -146));
    chatSprite_  = LP::SetMultiFrameSprite(korone_yubi_chat_image, 75, 44, 7, 1);
    for (auto sprite : chatSprite_)
    {
        sprite.setOrigin(sf::Vector2f(-40, -226));
        sprite.setPosition(position_);
    }

    scene_->FindGameObject("Hand")->Kill();
}

KoroneYubiStream::~KoroneYubiStream()
{}

void KoroneYubiStream::Update(float delta_time)
{
    ChatHandle(delta_time);
    LaughHandle(delta_time);
}

void KoroneYubiStream::Draw(sf::RenderWindow& render_window) const
{
    render_window.draw(streamSprite_);
    render_window.draw(laugh1Sprite_);
    render_window.draw(laugh2Sprite_);
    render_window.draw(chatSprite_[chatFrame_]);
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
            laugh1Sprite_.setOrigin(sf::Vector2f(-360, -185));
            laugh2Sprite_.setOrigin(sf::Vector2f(-373, -146));
            laughFrame_ = false;
        }
        else
        {
            laugh1Sprite_.setOrigin(sf::Vector2f(-354, -185));
            laugh2Sprite_.setOrigin(sf::Vector2f(-368, -141));
            laughFrame_ = true;
        }
        laughTimer_ = 0.3f;
    }
}